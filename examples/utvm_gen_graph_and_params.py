import os
import sys
import logging
import shutil
import tarfile
import json

import numpy as np

import tvm
import tvm.micro
from tvm import te
from tvm import relay
from tvm import ir
from tvm import autotvm
from tvm.contrib import graph_runtime
from tvm.contrib import utils as tvm_utils
from tvm.micro import export_model_library_format

from tflite.TensorType import TensorType as TType

# import compiler_ext
import codegen


class TensorInfo:
    def __init__(self, t):
        self.name = t.Name().decode()

        typeLookup = {
            TType.FLOAT32: (4, "float32"),
            TType.UINT8: (1, "uint8"),
            TType.INT8: (1, "int8")
        }
        self.tysz, self.ty = typeLookup[t.Type()]
        assert self.ty != ""

        shape = tuple([t.Shape(si) for si in range(0, t.ShapeLength())])
        self.shape = shape

        self.size = self.tysz
        for dimSz in self.shape:
            self.size *= dimSz


class ModelInfo:
    def __init__(self, model):
        assert model.SubgraphsLength() == 1
        g = model.Subgraphs(0)

        self.inTensors = []
        for i in range(0, g.InputsLength()):
            t = g.Tensors(g.Inputs(i))
            self.inTensors.append(TensorInfo(t))

        self.outTensors = []
        for i in range(0, g.OutputsLength()):
            t = g.Tensors(g.Outputs(i))
            self.outTensors.append(TensorInfo(t))

class OnnxModelInfo:
    def __init__(self, onnx_model):

        self.inNodes = [node for node in onnx_model.graph.input]


        #for i in range(0,len(model.graph.input)):
        #    in_node = model.graph.input[i]
        #    self.inNodes.append(in_node)

        self.outNodes = [node for node in onnx_model.graph.output]

        #for i in range(0,len(model.graph.input)):
        #    out_node = model.graph.output[i]
        #    self.outNodes.append(out_node)

    def get_shapes(self):



        self.inShapes = []
        self.outShapes = []

        for _node in self.inNodes:
            self.inShapes.append(tuple([d.dim_value for d in _node.type.tensor_type.shape.dim]))
            print("node: ", _node.name, "dim", _node.type.tensor_type.shape.dim)
        
        for _node in self.outNodes:
            self.outShapes.append(tuple([d.dim_value for d in
                _node.type.tensor_type.shape.dim]))


        return



class TVMFlow:
    def __init__(self):
        self.opt_level = 0
        self.local = False
        if self.local:
            self.target = "c  -keys=arm_cpu --link-params --runtime=c --system-lib=1"
            self.target = "llvm  -mtriple=aarch64-linux-gnu -mattr=+sve"
        else:
            self.target = tvm.target.target.micro("host")

            self.target = "c  -keys=arm_cpu --link-params --runtime=c  --system-lib=1 -march=armv8-a+sve"
            #self.target = "llvm  -mtriple=aarch64-linux-gnu -mattr=+sve --system-lib=1"
            print(self.target)


    def loadModel(self, path):
        
        print("### TVMFlow.loadModel")

        #modelBuf = open(path, "rb").read()

        #import tflite
        #tflModel = tflite.Model.GetRootAsModel(modelBuf, 0)

        import onnx
        onnx_model = onnx.load(path)
        

        shapes = []
        types = {}

        #self.modelInfo = ModelInfo(tflModel)
        
        self.modelInfo = OnnxModelInfo(onnx_model)
        self.modelInfo.get_shapes()
        for n in self.modelInfo.inNodes:
            shape = tuple([d.dim_value for d in n.type.tensor_type.shape.dim])
            #print(n)
            print("Input", '"' + n.name + '"', shape)
            shapes.append({n.name:shape})
            #types[n.name] = ty

        #print(self.modelInfo.inShapes)
        #self.mod, self.params = relay.frontend.from_tflite(tflModel, shape_dict=shapes, dtype_dict=types)
        print(shapes)
        self.mod, self.params = relay.frontend.from_onnx(onnx_model, shapes[0])

    def build(self):
        print("### TVMFlow.build")

        if self.local:
            cfg = {}
        else:
            cfg = { "tir.disable_vectorize": True}#True }

        with tvm.transform.PassContext(opt_level=self.opt_level, config=cfg):
            print("bulding model using relay")
            print(self.target)
            c_mod = relay.build(self.mod, target=self.target, params=self.params)
            print("model built successfully using relay")
            self.graph = c_mod.get_graph_json()
            self.c_params = c_mod.get_params()

        if not self.local:
            # Extract metadata.
            mlfDir = os.path.dirname(os.path.abspath(os.path.expanduser(__file__))) +"/temp"
            os.makedirs(mlfDir, exist_ok=True)
            tarFile = os.path.join(mlfDir, "archive.tar")
            export_model_library_format(c_mod, tarFile)
            tarfile.open(tarFile).extractall(mlfDir)
            with open(os.path.join(mlfDir, "metadata.json")) as f:
                metadata = json.load(f)
            workspaceBytes = 0
            print(metadata["memory"])
            for op in metadata["memory"]["functions"]["operator_functions"]:
                workspaceBytes = max(workspaceBytes, op["workspace"][0]["workspace_size_bytes"])

            # Cross compile
            # self.workspace = tvm.micro.Workspace(debug=True)
            # opts = tvm.micro.default_options(os.path.join(tvm.micro.get_standalone_crt_dir(), "template", "host"))
            # self.compiler = compiler_ext.Compiler_Ext(target=self.target)
            # self.micro_binary = tvm.micro.build_static_runtime(
            #     self.workspace,
            #     self.compiler,
            #     c_mod,
            #     opts,
            #     extra_libs=[tvm.micro.get_standalone_crt_lib("memory")]
            # )

            # Prepare target data
            self.outDir = "out"
            if os.path.exists(os.path.join(self.outDir, "params.bin")):
                shutil.rmtree(self.outDir)

            print("INFO: outdir:", self.outDir)
            shutil.copytree(os.path.join(mlfDir, "codegen", "host", "src"), self.outDir)
            # TODO: remove this temporary workaround for old tvm version
            legacy = False
            curr_path = os.path.dirname(os.path.abspath(os.path.expanduser(__file__)))
            if os.path.exists(os.path.join(mlfDir, "src", "relay.txt")):
                print(os.path.join(mlfDir, "src", "relay.txt"))
                shutil.copy2(os.path.join(mlfDir, "src", "relay.txt"), os.path.join(self.outDir, "relay.txt"))
            else:
                legacy = True
                shutil.copy2(os.path.join(mlfDir, "relay.txt"), os.path.join(self.outDir, "relay.txt"))
            shutil.copy2(os.path.join(mlfDir, "metadata.json"), os.path.join(self.outDir, "metadata.json"))

            if self.graph:
                with open(os.path.join(self.outDir, "graph.json"), "w") as f:
                    f.write(self.graph)

            with open(os.path.join(self.outDir, "metadata.json")) as json_f:
                metadata = json.load(json_f)

            with open(os.path.join(self.outDir, "params.bin"), "wb") as f:
                f.write(relay.save_param_dict(self.c_params))
            with open(os.path.join(self.outDir, "workspace_size.txt"), "w") as f:
                f.write(str(workspaceBytes))
            codegen.generateTargetCode(self.outDir + "/runtime_wrapper.c", self.graph, relay.save_param_dict(self.c_params), self.modelInfo)

        if  self.local:
            # Extract metadata.
            mlfDir = os.path.dirname(os.path.abspath(os.path.expanduser(__file__))) +"/temp"
            os.makedirs(mlfDir, exist_ok=True)
            tarFile = os.path.join(mlfDir, "archive.tar")
            export_model_library_format(c_mod, tarFile)
            tarfile.open(tarFile).extractall(mlfDir)
            with open(os.path.join(mlfDir, "metadata.json")) as f:
                metadata = json.load(f)
            workspaceBytes = 0
            print(metadata["memory"])
            for op in metadata["memory"]["functions"]["operator_functions"]:
                workspaceBytes = max(workspaceBytes, op["workspace"][0]["workspace_size_bytes"])

            # Cross compile
            # self.workspace = tvm.micro.Workspace(debug=True)
            # opts = tvm.micro.default_options(os.path.join(tvm.micro.get_standalone_crt_dir(), "template", "host"))
            # self.compiler = compiler_ext.Compiler_Ext(target=self.target)
            # self.micro_binary = tvm.micro.build_static_runtime(
            #     self.workspace,
            #     self.compiler,
            #     c_mod,
            #     opts,
            #     extra_libs=[tvm.micro.get_standalone_crt_lib("memory")]
            # )

            # Prepare target data
            self.outDir = "out"
            if os.path.exists(os.path.join(self.outDir, "params.bin")):
                shutil.rmtree(self.outDir)

            print("INFO: outdir:", self.outDir)
            shutil.copytree(os.path.join(mlfDir, "codegen", "host", "lib"), self.outDir)
            # TODO: remove this temporary workaround for old tvm version
            legacy = False
            curr_path = os.path.dirname(os.path.abspath(os.path.expanduser(__file__)))
            if os.path.exists(os.path.join(mlfDir, "lib", "relay.txt")):
                print(os.path.join(mlfDir, "lib", "relay.txt"))
                shutil.copy2(os.path.join(mlfDir, "lib", "relay.txt"), os.path.join(self.outDir, "relay.txt"))
            else:
                legacy = True
                shutil.copy2(os.path.join(mlfDir, "src" ,"relay.txt"), os.path.join(self.outDir, "relay.txt"))
            shutil.copy2(os.path.join(mlfDir, "metadata.json"), os.path.join(self.outDir, "metadata.json"))

            if self.graph:
                with open(os.path.join(self.outDir, "graph.json"), "w") as f:
                    f.write(self.graph)

            with open(os.path.join(self.outDir, "metadata.json")) as json_f:
                metadata = json.load(json_f)

            with open(os.path.join(self.outDir, "params.bin"), "wb") as f:
                f.write(relay.save_param_dict(self.c_params))
            with open(os.path.join(self.outDir, "workspace_size.txt"), "w") as f:
                f.write(str(workspaceBytes))
            codegen.generateTargetCode(self.outDir + "/runtime_wrapper.c", self.graph, relay.save_param_dict(self.c_params), self.modelInfo)

def main():
    if len(sys.argv) != 2:
        print("Usage:", sys.argv[0], "model.tflite")
        sys.exit(1)

    flow = TVMFlow()
    flow.loadModel(sys.argv[1])
    flow.build()
    print("flow built successfully")

if __name__ == "__main__":
    main()
