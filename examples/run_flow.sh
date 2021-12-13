#!/bin/bash

set -e

run_test() {
    python3 utvm_gen_graph_and_params.py $1

    ../build/utvm_staticrt_codegen out/graph.json out/params.bin out/staticrt.c $(cat out/workspace_size.txt)


    TVM_DIR=$(grep TVM_DIR ../build/CMakeCache.txt)

    cd target_src
    mkdir -p build
    cd build
    echo "building deploy binary"
    cmake -D$TVM_DIR -DCMAKE_BUILD_TYPE=Debug ..
    make -j`nproc`

    ./example_target_src

    cd ../..
}

#run_test sine_model.tflite
#run_test cifar10.tflite

#run_test /home/nitesh/nitesh_nfs_share/models//classification/mnist/mnist-8.onnx

#run_test /home/nitesh/nitesh_nfs_share/models//classification/zfnet-512/zfnet512-9.onnx
#run_test /home/nitesh/nitesh_nfs_share/models//classification/resnet/resnet18v1.onnx


run_test /home/nitesh/nitesh_nfs_share/models/micro_models/simple_Nets/simple_CNN.onnx
