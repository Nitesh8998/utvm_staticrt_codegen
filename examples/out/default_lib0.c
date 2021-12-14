#include <tvm/runtime/crt/module.h>
#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_bias_add(TVMValue* args, int* type_code, int num_args, TVMValue* out_value, int* out_type_code);
#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_conv1d(TVMValue* args, int* type_code, int num_args, TVMValue* out_value, int* out_type_code);
#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t _lookup_linked_param(TVMValue* args, int* type_code, int num_args, TVMValue* out_value, int* out_type_code);
static TVMBackendPackedCFunc _tvm_func_array[] = {
    (TVMBackendPackedCFunc)tvmgen_default_fused_nn_bias_add,
    (TVMBackendPackedCFunc)tvmgen_default_fused_nn_conv1d,
    (TVMBackendPackedCFunc)_lookup_linked_param,
};
static const TVMFuncRegistry _tvm_func_registry = {
    "\003tvmgen_default_fused_nn_bias_add\000tvmgen_default_fused_nn_conv1d\000_lookup_linked_param\000",    _tvm_func_array,
};
static const TVMModule _tvm_system_lib = {
    &_tvm_func_registry,
};
const TVMModule* TVMSystemLibEntryPoint(void) {
    return &_tvm_system_lib;
}
;