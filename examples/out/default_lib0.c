// tvm target: c -keys=cpu -link-params=0 -model=host
#define TVM_EXPORTS
#include "tvm/runtime/c_runtime_api.h"
#include "tvm/runtime/c_backend_api.h"
#include <math.h>
#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_pad_1(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* T_pad = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  for (int32_t ax0_ax1_fused = 0; ax0_ax1_fused < 8; ++ax0_ax1_fused) {
    for (int32_t ax2 = 0; ax2 < 18; ++ax2) {
      for (int32_t ax3_outer = 0; ax3_outer < 2; ++ax3_outer) {
        for (int32_t ax3_inner = 0; ax3_inner < 16; ++ax3_inner) {
          if (((ax3_outer * 16) + ax3_inner) < 18) {
            ((float*)T_pad)[(((((ax0_ax1_fused * 324) + (ax2 * 18)) + (ax3_outer * 16)) + ax3_inner))] = (((((2 <= ax2) && (ax2 < 16)) && (2 <= ((ax3_outer * 16) + ax3_inner))) && (((ax3_outer * 16) + ax3_inner) < 16)) ? ((float*)placeholder)[((((((ax0_ax1_fused * 196) + (ax3_outer * 16)) + (ax2 * 14)) + ax3_inner) - 30))] : ((float*)placeholder1)[(0)]);
          }
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_transpose(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* T_transpose = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  for (int32_t ax0 = 0; ax0 < 10; ++ax0) {
    for (int32_t ax1_outer = 0; ax1_outer < 16; ++ax1_outer) {
      for (int32_t ax1_inner = 0; ax1_inner < 16; ++ax1_inner) {
        ((float*)T_transpose)[((((ax0 * 256) + (ax1_outer * 16)) + ax1_inner))] = ((float*)placeholder)[((((ax1_outer * 160) + (ax1_inner * 10)) + ax0))];
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_reshape_1(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* T_reshape = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  for (int32_t ax0 = 0; ax0 < 256; ++ax0) {
    for (int32_t ax1_inner = 0; ax1_inner < 10; ++ax1_inner) {
      ((float*)T_reshape)[(((ax0 * 10) + ax1_inner))] = ((float*)placeholder)[(((ax0 * 10) + ax1_inner))];
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_max_pool2d_1(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* tensor = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  for (int32_t ax0_ax1_fused = 0; ax0_ax1_fused < 16; ++ax0_ax1_fused) {
    for (int32_t ax2 = 0; ax2 < 4; ++ax2) {
      for (int32_t ax3 = 0; ax3 < 4; ++ax3) {
        ((float*)tensor)[((((ax0_ax1_fused * 16) + (ax2 * 4)) + ax3))] = -3.402823e+38f;
        for (int32_t rv0 = 0; rv0 < 3; ++rv0) {
          for (int32_t rv1 = 0; rv1 < 3; ++rv1) {
            float _1 = ((float*)tensor)[((((ax0_ax1_fused * 16) + (ax2 * 4)) + ax3))];
            float _2 = ((float*)placeholder)[((((((ax0_ax1_fused * 196) + (ax2 * 42)) + (rv0 * 14)) + (ax3 * 3)) + rv1))];
            ((float*)tensor)[((((ax0_ax1_fused * 16) + (ax2 * 4)) + ax3))] = ((_1) > (_2) ? (_1) : (_2));
          }
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_add(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* T_add = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  for (int32_t ax0_ax1_fused = 0; ax0_ax1_fused < 8; ++ax0_ax1_fused) {
    for (int32_t ax2 = 0; ax2 < 28; ++ax2) {
      for (int32_t ax3_outer = 0; ax3_outer < 2; ++ax3_outer) {
        for (int32_t ax3_inner = 0; ax3_inner < 16; ++ax3_inner) {
          if (((ax3_outer * 16) + ax3_inner) < 28) {
            ((float*)T_add)[(((((ax0_ax1_fused * 784) + (ax2 * 28)) + (ax3_outer * 16)) + ax3_inner))] = (((float*)placeholder)[(((((ax0_ax1_fused * 784) + (ax2 * 28)) + (ax3_outer * 16)) + ax3_inner))] + ((float*)placeholder1)[(ax0_ax1_fused)]);
          }
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_max_pool2d(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* tensor = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  for (int32_t ax0_ax1_fused = 0; ax0_ax1_fused < 8; ++ax0_ax1_fused) {
    for (int32_t ax2 = 0; ax2 < 14; ++ax2) {
      for (int32_t ax3 = 0; ax3 < 14; ++ax3) {
        ((float*)tensor)[((((ax0_ax1_fused * 196) + (ax2 * 14)) + ax3))] = -3.402823e+38f;
        for (int32_t rv0 = 0; rv0 < 2; ++rv0) {
          for (int32_t rv1 = 0; rv1 < 2; ++rv1) {
            float _1 = ((float*)tensor)[((((ax0_ax1_fused * 196) + (ax2 * 14)) + ax3))];
            float _2 = ((float*)placeholder)[((((((ax0_ax1_fused * 784) + (ax2 * 56)) + (rv0 * 28)) + (ax3 * 2)) + rv1))];
            ((float*)tensor)[((((ax0_ax1_fused * 196) + (ax2 * 14)) + ax3))] = ((_1) > (_2) ? (_1) : (_2));
          }
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_conv2d_1(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* output_unpack = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  void* data_vec = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)10368, 2, 32);
  if (data_vec == NULL) {
    return -1;
  }
  void* kernel_vec = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)12800, 2, 32);
  if (kernel_vec == NULL) {
    return -1;
  }
  for (int32_t bs_c_fused_h_fused = 0; bs_c_fused_h_fused < 36; ++bs_c_fused_h_fused) {
    for (int32_t w = 0; w < 18; ++w) {
      for (int32_t vc = 0; vc < 4; ++vc) {
        ((float*)data_vec)[((((bs_c_fused_h_fused * 72) + (w * 4)) + vc))] = ((float*)placeholder)[((((((bs_c_fused_h_fused / 18) * 1296) + (vc * 324)) + ((bs_c_fused_h_fused % 18) * 18)) + w))];
      }
    }
  }
  for (int32_t occ_k_h_fused = 0; occ_k_h_fused < 20; ++occ_k_h_fused) {
    for (int32_t icc = 0; icc < 2; ++icc) {
      for (int32_t k_w = 0; k_w < 5; ++k_w) {
        for (int32_t icb = 0; icb < 4; ++icb) {
          for (int32_t ocb = 0; ocb < 4; ++ocb) {
            ((float*)kernel_vec)[((((((((occ_k_h_fused / 5) * 800) + (icc * 400)) + ((occ_k_h_fused % 5) * 80)) + (k_w * 16)) + (icb * 4)) + ocb))] = ((float*)placeholder1)[((((((((occ_k_h_fused / 5) * 800) + (ocb * 200)) + (icc * 100)) + (icb * 25)) + ((occ_k_h_fused % 5) * 5)) + k_w))];
          }
        }
      }
    }
  }
  for (int32_t n_c_outer_fused_h_fused = 0; n_c_outer_fused_h_fused < 56; ++n_c_outer_fused_h_fused) {
    float conv2d_NCHWc_global[56];
    for (int32_t oc_block_c_init = 0; oc_block_c_init < 4; ++oc_block_c_init) {
      conv2d_NCHWc_global[(oc_block_c_init)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init1 = 0; oc_block_c_init1 < 4; ++oc_block_c_init1) {
      conv2d_NCHWc_global[((oc_block_c_init1 + 4))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init2 = 0; oc_block_c_init2 < 4; ++oc_block_c_init2) {
      conv2d_NCHWc_global[((oc_block_c_init2 + 8))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init3 = 0; oc_block_c_init3 < 4; ++oc_block_c_init3) {
      conv2d_NCHWc_global[((oc_block_c_init3 + 12))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init4 = 0; oc_block_c_init4 < 4; ++oc_block_c_init4) {
      conv2d_NCHWc_global[((oc_block_c_init4 + 16))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init5 = 0; oc_block_c_init5 < 4; ++oc_block_c_init5) {
      conv2d_NCHWc_global[((oc_block_c_init5 + 20))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init6 = 0; oc_block_c_init6 < 4; ++oc_block_c_init6) {
      conv2d_NCHWc_global[((oc_block_c_init6 + 24))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init7 = 0; oc_block_c_init7 < 4; ++oc_block_c_init7) {
      conv2d_NCHWc_global[((oc_block_c_init7 + 28))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init8 = 0; oc_block_c_init8 < 4; ++oc_block_c_init8) {
      conv2d_NCHWc_global[((oc_block_c_init8 + 32))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init9 = 0; oc_block_c_init9 < 4; ++oc_block_c_init9) {
      conv2d_NCHWc_global[((oc_block_c_init9 + 36))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init10 = 0; oc_block_c_init10 < 4; ++oc_block_c_init10) {
      conv2d_NCHWc_global[((oc_block_c_init10 + 40))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init11 = 0; oc_block_c_init11 < 4; ++oc_block_c_init11) {
      conv2d_NCHWc_global[((oc_block_c_init11 + 44))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init12 = 0; oc_block_c_init12 < 4; ++oc_block_c_init12) {
      conv2d_NCHWc_global[((oc_block_c_init12 + 48))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init13 = 0; oc_block_c_init13 < 4; ++oc_block_c_init13) {
      conv2d_NCHWc_global[((oc_block_c_init13 + 52))] = 0.000000e+00f;
    }
    for (int32_t ic_outer = 0; ic_outer < 2; ++ic_outer) {
      for (int32_t kh = 0; kh < 5; ++kh) {
        for (int32_t kw = 0; kw < 5; ++kw) {
          for (int32_t ic_inner = 0; ic_inner < 4; ++ic_inner) {
            for (int32_t oc_block_c = 0; oc_block_c < 4; ++oc_block_c) {
              conv2d_NCHWc_global[(oc_block_c)] = (conv2d_NCHWc_global[(oc_block_c)] + (((float*)data_vec)[((((((ic_outer * 1296) + (kh * 72)) + ((n_c_outer_fused_h_fused % 14) * 72)) + (kw * 4)) + ic_inner))] * ((float*)kernel_vec)[((((((((n_c_outer_fused_h_fused / 14) * 800) + (ic_outer * 400)) + (kh * 80)) + (kw * 16)) + (ic_inner * 4)) + oc_block_c))]));
            }
            for (int32_t oc_block_c1 = 0; oc_block_c1 < 4; ++oc_block_c1) {
              conv2d_NCHWc_global[((oc_block_c1 + 4))] = (conv2d_NCHWc_global[((oc_block_c1 + 4))] + (((float*)data_vec)[(((((((ic_outer * 1296) + (kh * 72)) + ((n_c_outer_fused_h_fused % 14) * 72)) + (kw * 4)) + ic_inner) + 4))] * ((float*)kernel_vec)[((((((((n_c_outer_fused_h_fused / 14) * 800) + (ic_outer * 400)) + (kh * 80)) + (kw * 16)) + (ic_inner * 4)) + oc_block_c1))]));
            }
            for (int32_t oc_block_c2 = 0; oc_block_c2 < 4; ++oc_block_c2) {
              conv2d_NCHWc_global[((oc_block_c2 + 8))] = (conv2d_NCHWc_global[((oc_block_c2 + 8))] + (((float*)data_vec)[(((((((ic_outer * 1296) + (kh * 72)) + ((n_c_outer_fused_h_fused % 14) * 72)) + (kw * 4)) + ic_inner) + 8))] * ((float*)kernel_vec)[((((((((n_c_outer_fused_h_fused / 14) * 800) + (ic_outer * 400)) + (kh * 80)) + (kw * 16)) + (ic_inner * 4)) + oc_block_c2))]));
            }
            for (int32_t oc_block_c3 = 0; oc_block_c3 < 4; ++oc_block_c3) {
              conv2d_NCHWc_global[((oc_block_c3 + 12))] = (conv2d_NCHWc_global[((oc_block_c3 + 12))] + (((float*)data_vec)[(((((((ic_outer * 1296) + (kh * 72)) + ((n_c_outer_fused_h_fused % 14) * 72)) + (kw * 4)) + ic_inner) + 12))] * ((float*)kernel_vec)[((((((((n_c_outer_fused_h_fused / 14) * 800) + (ic_outer * 400)) + (kh * 80)) + (kw * 16)) + (ic_inner * 4)) + oc_block_c3))]));
            }
            for (int32_t oc_block_c4 = 0; oc_block_c4 < 4; ++oc_block_c4) {
              conv2d_NCHWc_global[((oc_block_c4 + 16))] = (conv2d_NCHWc_global[((oc_block_c4 + 16))] + (((float*)data_vec)[(((((((ic_outer * 1296) + (kh * 72)) + ((n_c_outer_fused_h_fused % 14) * 72)) + (kw * 4)) + ic_inner) + 16))] * ((float*)kernel_vec)[((((((((n_c_outer_fused_h_fused / 14) * 800) + (ic_outer * 400)) + (kh * 80)) + (kw * 16)) + (ic_inner * 4)) + oc_block_c4))]));
            }
            for (int32_t oc_block_c5 = 0; oc_block_c5 < 4; ++oc_block_c5) {
              conv2d_NCHWc_global[((oc_block_c5 + 20))] = (conv2d_NCHWc_global[((oc_block_c5 + 20))] + (((float*)data_vec)[(((((((ic_outer * 1296) + (kh * 72)) + ((n_c_outer_fused_h_fused % 14) * 72)) + (kw * 4)) + ic_inner) + 20))] * ((float*)kernel_vec)[((((((((n_c_outer_fused_h_fused / 14) * 800) + (ic_outer * 400)) + (kh * 80)) + (kw * 16)) + (ic_inner * 4)) + oc_block_c5))]));
            }
            for (int32_t oc_block_c6 = 0; oc_block_c6 < 4; ++oc_block_c6) {
              conv2d_NCHWc_global[((oc_block_c6 + 24))] = (conv2d_NCHWc_global[((oc_block_c6 + 24))] + (((float*)data_vec)[(((((((ic_outer * 1296) + (kh * 72)) + ((n_c_outer_fused_h_fused % 14) * 72)) + (kw * 4)) + ic_inner) + 24))] * ((float*)kernel_vec)[((((((((n_c_outer_fused_h_fused / 14) * 800) + (ic_outer * 400)) + (kh * 80)) + (kw * 16)) + (ic_inner * 4)) + oc_block_c6))]));
            }
            for (int32_t oc_block_c7 = 0; oc_block_c7 < 4; ++oc_block_c7) {
              conv2d_NCHWc_global[((oc_block_c7 + 28))] = (conv2d_NCHWc_global[((oc_block_c7 + 28))] + (((float*)data_vec)[(((((((ic_outer * 1296) + (kh * 72)) + ((n_c_outer_fused_h_fused % 14) * 72)) + (kw * 4)) + ic_inner) + 28))] * ((float*)kernel_vec)[((((((((n_c_outer_fused_h_fused / 14) * 800) + (ic_outer * 400)) + (kh * 80)) + (kw * 16)) + (ic_inner * 4)) + oc_block_c7))]));
            }
            for (int32_t oc_block_c8 = 0; oc_block_c8 < 4; ++oc_block_c8) {
              conv2d_NCHWc_global[((oc_block_c8 + 32))] = (conv2d_NCHWc_global[((oc_block_c8 + 32))] + (((float*)data_vec)[(((((((ic_outer * 1296) + (kh * 72)) + ((n_c_outer_fused_h_fused % 14) * 72)) + (kw * 4)) + ic_inner) + 32))] * ((float*)kernel_vec)[((((((((n_c_outer_fused_h_fused / 14) * 800) + (ic_outer * 400)) + (kh * 80)) + (kw * 16)) + (ic_inner * 4)) + oc_block_c8))]));
            }
            for (int32_t oc_block_c9 = 0; oc_block_c9 < 4; ++oc_block_c9) {
              conv2d_NCHWc_global[((oc_block_c9 + 36))] = (conv2d_NCHWc_global[((oc_block_c9 + 36))] + (((float*)data_vec)[(((((((ic_outer * 1296) + (kh * 72)) + ((n_c_outer_fused_h_fused % 14) * 72)) + (kw * 4)) + ic_inner) + 36))] * ((float*)kernel_vec)[((((((((n_c_outer_fused_h_fused / 14) * 800) + (ic_outer * 400)) + (kh * 80)) + (kw * 16)) + (ic_inner * 4)) + oc_block_c9))]));
            }
            for (int32_t oc_block_c10 = 0; oc_block_c10 < 4; ++oc_block_c10) {
              conv2d_NCHWc_global[((oc_block_c10 + 40))] = (conv2d_NCHWc_global[((oc_block_c10 + 40))] + (((float*)data_vec)[(((((((ic_outer * 1296) + (kh * 72)) + ((n_c_outer_fused_h_fused % 14) * 72)) + (kw * 4)) + ic_inner) + 40))] * ((float*)kernel_vec)[((((((((n_c_outer_fused_h_fused / 14) * 800) + (ic_outer * 400)) + (kh * 80)) + (kw * 16)) + (ic_inner * 4)) + oc_block_c10))]));
            }
            for (int32_t oc_block_c11 = 0; oc_block_c11 < 4; ++oc_block_c11) {
              conv2d_NCHWc_global[((oc_block_c11 + 44))] = (conv2d_NCHWc_global[((oc_block_c11 + 44))] + (((float*)data_vec)[(((((((ic_outer * 1296) + (kh * 72)) + ((n_c_outer_fused_h_fused % 14) * 72)) + (kw * 4)) + ic_inner) + 44))] * ((float*)kernel_vec)[((((((((n_c_outer_fused_h_fused / 14) * 800) + (ic_outer * 400)) + (kh * 80)) + (kw * 16)) + (ic_inner * 4)) + oc_block_c11))]));
            }
            for (int32_t oc_block_c12 = 0; oc_block_c12 < 4; ++oc_block_c12) {
              conv2d_NCHWc_global[((oc_block_c12 + 48))] = (conv2d_NCHWc_global[((oc_block_c12 + 48))] + (((float*)data_vec)[(((((((ic_outer * 1296) + (kh * 72)) + ((n_c_outer_fused_h_fused % 14) * 72)) + (kw * 4)) + ic_inner) + 48))] * ((float*)kernel_vec)[((((((((n_c_outer_fused_h_fused / 14) * 800) + (ic_outer * 400)) + (kh * 80)) + (kw * 16)) + (ic_inner * 4)) + oc_block_c12))]));
            }
            for (int32_t oc_block_c13 = 0; oc_block_c13 < 4; ++oc_block_c13) {
              conv2d_NCHWc_global[((oc_block_c13 + 52))] = (conv2d_NCHWc_global[((oc_block_c13 + 52))] + (((float*)data_vec)[(((((((ic_outer * 1296) + (kh * 72)) + ((n_c_outer_fused_h_fused % 14) * 72)) + (kw * 4)) + ic_inner) + 52))] * ((float*)kernel_vec)[((((((((n_c_outer_fused_h_fused / 14) * 800) + (ic_outer * 400)) + (kh * 80)) + (kw * 16)) + (ic_inner * 4)) + oc_block_c13))]));
            }
          }
        }
      }
    }
    for (int32_t w_inner = 0; w_inner < 14; ++w_inner) {
      for (int32_t c_inner = 0; c_inner < 4; ++c_inner) {
        ((float*)output_unpack)[((((((n_c_outer_fused_h_fused / 14) * 784) + (c_inner * 196)) + ((n_c_outer_fused_h_fused % 14) * 14)) + w_inner))] = conv2d_NCHWc_global[(((w_inner * 4) + c_inner))];
      }
    }
  }
  if (TVMBackendFreeWorkspace(1, dev_id, kernel_vec) != 0) {
    return -1;
  }
  if (TVMBackendFreeWorkspace(1, dev_id, data_vec) != 0) {
    return -1;
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_conv2d(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* output_unpack = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  void* data_vec = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)4096, 2, 32);
  if (data_vec == NULL) {
    return -1;
  }
  float kernel_vec[200];
  for (int32_t bs_c_fused_h_fused = 0; bs_c_fused_h_fused < 32; ++bs_c_fused_h_fused) {
    for (int32_t w = 0; w < 32; ++w) {
      ((float*)data_vec)[(((bs_c_fused_h_fused * 32) + w))] = ((float*)placeholder)[(((bs_c_fused_h_fused * 32) + w))];
    }
  }
  for (int32_t occ_k_h_fused = 0; occ_k_h_fused < 10; ++occ_k_h_fused) {
    for (int32_t k_w = 0; k_w < 5; ++k_w) {
      for (int32_t ocb = 0; ocb < 4; ++ocb) {
        kernel_vec[((((occ_k_h_fused * 20) + (k_w * 4)) + ocb))] = ((float*)placeholder1)[((((((occ_k_h_fused / 5) * 100) + (ocb * 25)) + ((occ_k_h_fused % 5) * 5)) + k_w))];
      }
    }
  }
  for (int32_t n_c_outer_fused_h_fused = 0; n_c_outer_fused_h_fused < 56; ++n_c_outer_fused_h_fused) {
    float conv2d_NCHWc_global[112];
    for (int32_t oc_block_c_init = 0; oc_block_c_init < 4; ++oc_block_c_init) {
      conv2d_NCHWc_global[(oc_block_c_init)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init1 = 0; oc_block_c_init1 < 4; ++oc_block_c_init1) {
      conv2d_NCHWc_global[((oc_block_c_init1 + 4))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init2 = 0; oc_block_c_init2 < 4; ++oc_block_c_init2) {
      conv2d_NCHWc_global[((oc_block_c_init2 + 8))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init3 = 0; oc_block_c_init3 < 4; ++oc_block_c_init3) {
      conv2d_NCHWc_global[((oc_block_c_init3 + 12))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init4 = 0; oc_block_c_init4 < 4; ++oc_block_c_init4) {
      conv2d_NCHWc_global[((oc_block_c_init4 + 16))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init5 = 0; oc_block_c_init5 < 4; ++oc_block_c_init5) {
      conv2d_NCHWc_global[((oc_block_c_init5 + 20))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init6 = 0; oc_block_c_init6 < 4; ++oc_block_c_init6) {
      conv2d_NCHWc_global[((oc_block_c_init6 + 24))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init7 = 0; oc_block_c_init7 < 4; ++oc_block_c_init7) {
      conv2d_NCHWc_global[((oc_block_c_init7 + 28))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init8 = 0; oc_block_c_init8 < 4; ++oc_block_c_init8) {
      conv2d_NCHWc_global[((oc_block_c_init8 + 32))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init9 = 0; oc_block_c_init9 < 4; ++oc_block_c_init9) {
      conv2d_NCHWc_global[((oc_block_c_init9 + 36))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init10 = 0; oc_block_c_init10 < 4; ++oc_block_c_init10) {
      conv2d_NCHWc_global[((oc_block_c_init10 + 40))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init11 = 0; oc_block_c_init11 < 4; ++oc_block_c_init11) {
      conv2d_NCHWc_global[((oc_block_c_init11 + 44))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init12 = 0; oc_block_c_init12 < 4; ++oc_block_c_init12) {
      conv2d_NCHWc_global[((oc_block_c_init12 + 48))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init13 = 0; oc_block_c_init13 < 4; ++oc_block_c_init13) {
      conv2d_NCHWc_global[((oc_block_c_init13 + 52))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init14 = 0; oc_block_c_init14 < 4; ++oc_block_c_init14) {
      conv2d_NCHWc_global[((oc_block_c_init14 + 56))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init15 = 0; oc_block_c_init15 < 4; ++oc_block_c_init15) {
      conv2d_NCHWc_global[((oc_block_c_init15 + 60))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init16 = 0; oc_block_c_init16 < 4; ++oc_block_c_init16) {
      conv2d_NCHWc_global[((oc_block_c_init16 + 64))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init17 = 0; oc_block_c_init17 < 4; ++oc_block_c_init17) {
      conv2d_NCHWc_global[((oc_block_c_init17 + 68))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init18 = 0; oc_block_c_init18 < 4; ++oc_block_c_init18) {
      conv2d_NCHWc_global[((oc_block_c_init18 + 72))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init19 = 0; oc_block_c_init19 < 4; ++oc_block_c_init19) {
      conv2d_NCHWc_global[((oc_block_c_init19 + 76))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init20 = 0; oc_block_c_init20 < 4; ++oc_block_c_init20) {
      conv2d_NCHWc_global[((oc_block_c_init20 + 80))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init21 = 0; oc_block_c_init21 < 4; ++oc_block_c_init21) {
      conv2d_NCHWc_global[((oc_block_c_init21 + 84))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init22 = 0; oc_block_c_init22 < 4; ++oc_block_c_init22) {
      conv2d_NCHWc_global[((oc_block_c_init22 + 88))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init23 = 0; oc_block_c_init23 < 4; ++oc_block_c_init23) {
      conv2d_NCHWc_global[((oc_block_c_init23 + 92))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init24 = 0; oc_block_c_init24 < 4; ++oc_block_c_init24) {
      conv2d_NCHWc_global[((oc_block_c_init24 + 96))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init25 = 0; oc_block_c_init25 < 4; ++oc_block_c_init25) {
      conv2d_NCHWc_global[((oc_block_c_init25 + 100))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init26 = 0; oc_block_c_init26 < 4; ++oc_block_c_init26) {
      conv2d_NCHWc_global[((oc_block_c_init26 + 104))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init27 = 0; oc_block_c_init27 < 4; ++oc_block_c_init27) {
      conv2d_NCHWc_global[((oc_block_c_init27 + 108))] = 0.000000e+00f;
    }
    for (int32_t kh = 0; kh < 5; ++kh) {
      for (int32_t kw = 0; kw < 5; ++kw) {
        for (int32_t oc_block_c = 0; oc_block_c < 4; ++oc_block_c) {
          conv2d_NCHWc_global[(oc_block_c)] = (conv2d_NCHWc_global[(oc_block_c)] + (((float*)data_vec)[((((kh * 32) + ((n_c_outer_fused_h_fused % 28) * 32)) + kw))] * kernel_vec[((((((n_c_outer_fused_h_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c))]));
        }
        for (int32_t oc_block_c1 = 0; oc_block_c1 < 4; ++oc_block_c1) {
          conv2d_NCHWc_global[((oc_block_c1 + 4))] = (conv2d_NCHWc_global[((oc_block_c1 + 4))] + (((float*)data_vec)[(((((kh * 32) + ((n_c_outer_fused_h_fused % 28) * 32)) + kw) + 1))] * kernel_vec[((((((n_c_outer_fused_h_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c1))]));
        }
        for (int32_t oc_block_c2 = 0; oc_block_c2 < 4; ++oc_block_c2) {
          conv2d_NCHWc_global[((oc_block_c2 + 8))] = (conv2d_NCHWc_global[((oc_block_c2 + 8))] + (((float*)data_vec)[(((((kh * 32) + ((n_c_outer_fused_h_fused % 28) * 32)) + kw) + 2))] * kernel_vec[((((((n_c_outer_fused_h_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c2))]));
        }
        for (int32_t oc_block_c3 = 0; oc_block_c3 < 4; ++oc_block_c3) {
          conv2d_NCHWc_global[((oc_block_c3 + 12))] = (conv2d_NCHWc_global[((oc_block_c3 + 12))] + (((float*)data_vec)[(((((kh * 32) + ((n_c_outer_fused_h_fused % 28) * 32)) + kw) + 3))] * kernel_vec[((((((n_c_outer_fused_h_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c3))]));
        }
        for (int32_t oc_block_c4 = 0; oc_block_c4 < 4; ++oc_block_c4) {
          conv2d_NCHWc_global[((oc_block_c4 + 16))] = (conv2d_NCHWc_global[((oc_block_c4 + 16))] + (((float*)data_vec)[(((((kh * 32) + ((n_c_outer_fused_h_fused % 28) * 32)) + kw) + 4))] * kernel_vec[((((((n_c_outer_fused_h_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c4))]));
        }
        for (int32_t oc_block_c5 = 0; oc_block_c5 < 4; ++oc_block_c5) {
          conv2d_NCHWc_global[((oc_block_c5 + 20))] = (conv2d_NCHWc_global[((oc_block_c5 + 20))] + (((float*)data_vec)[(((((kh * 32) + ((n_c_outer_fused_h_fused % 28) * 32)) + kw) + 5))] * kernel_vec[((((((n_c_outer_fused_h_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c5))]));
        }
        for (int32_t oc_block_c6 = 0; oc_block_c6 < 4; ++oc_block_c6) {
          conv2d_NCHWc_global[((oc_block_c6 + 24))] = (conv2d_NCHWc_global[((oc_block_c6 + 24))] + (((float*)data_vec)[(((((kh * 32) + ((n_c_outer_fused_h_fused % 28) * 32)) + kw) + 6))] * kernel_vec[((((((n_c_outer_fused_h_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c6))]));
        }
        for (int32_t oc_block_c7 = 0; oc_block_c7 < 4; ++oc_block_c7) {
          conv2d_NCHWc_global[((oc_block_c7 + 28))] = (conv2d_NCHWc_global[((oc_block_c7 + 28))] + (((float*)data_vec)[(((((kh * 32) + ((n_c_outer_fused_h_fused % 28) * 32)) + kw) + 7))] * kernel_vec[((((((n_c_outer_fused_h_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c7))]));
        }
        for (int32_t oc_block_c8 = 0; oc_block_c8 < 4; ++oc_block_c8) {
          conv2d_NCHWc_global[((oc_block_c8 + 32))] = (conv2d_NCHWc_global[((oc_block_c8 + 32))] + (((float*)data_vec)[(((((kh * 32) + ((n_c_outer_fused_h_fused % 28) * 32)) + kw) + 8))] * kernel_vec[((((((n_c_outer_fused_h_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c8))]));
        }
        for (int32_t oc_block_c9 = 0; oc_block_c9 < 4; ++oc_block_c9) {
          conv2d_NCHWc_global[((oc_block_c9 + 36))] = (conv2d_NCHWc_global[((oc_block_c9 + 36))] + (((float*)data_vec)[(((((kh * 32) + ((n_c_outer_fused_h_fused % 28) * 32)) + kw) + 9))] * kernel_vec[((((((n_c_outer_fused_h_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c9))]));
        }
        for (int32_t oc_block_c10 = 0; oc_block_c10 < 4; ++oc_block_c10) {
          conv2d_NCHWc_global[((oc_block_c10 + 40))] = (conv2d_NCHWc_global[((oc_block_c10 + 40))] + (((float*)data_vec)[(((((kh * 32) + ((n_c_outer_fused_h_fused % 28) * 32)) + kw) + 10))] * kernel_vec[((((((n_c_outer_fused_h_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c10))]));
        }
        for (int32_t oc_block_c11 = 0; oc_block_c11 < 4; ++oc_block_c11) {
          conv2d_NCHWc_global[((oc_block_c11 + 44))] = (conv2d_NCHWc_global[((oc_block_c11 + 44))] + (((float*)data_vec)[(((((kh * 32) + ((n_c_outer_fused_h_fused % 28) * 32)) + kw) + 11))] * kernel_vec[((((((n_c_outer_fused_h_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c11))]));
        }
        for (int32_t oc_block_c12 = 0; oc_block_c12 < 4; ++oc_block_c12) {
          conv2d_NCHWc_global[((oc_block_c12 + 48))] = (conv2d_NCHWc_global[((oc_block_c12 + 48))] + (((float*)data_vec)[(((((kh * 32) + ((n_c_outer_fused_h_fused % 28) * 32)) + kw) + 12))] * kernel_vec[((((((n_c_outer_fused_h_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c12))]));
        }
        for (int32_t oc_block_c13 = 0; oc_block_c13 < 4; ++oc_block_c13) {
          conv2d_NCHWc_global[((oc_block_c13 + 52))] = (conv2d_NCHWc_global[((oc_block_c13 + 52))] + (((float*)data_vec)[(((((kh * 32) + ((n_c_outer_fused_h_fused % 28) * 32)) + kw) + 13))] * kernel_vec[((((((n_c_outer_fused_h_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c13))]));
        }
        for (int32_t oc_block_c14 = 0; oc_block_c14 < 4; ++oc_block_c14) {
          conv2d_NCHWc_global[((oc_block_c14 + 56))] = (conv2d_NCHWc_global[((oc_block_c14 + 56))] + (((float*)data_vec)[(((((kh * 32) + ((n_c_outer_fused_h_fused % 28) * 32)) + kw) + 14))] * kernel_vec[((((((n_c_outer_fused_h_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c14))]));
        }
        for (int32_t oc_block_c15 = 0; oc_block_c15 < 4; ++oc_block_c15) {
          conv2d_NCHWc_global[((oc_block_c15 + 60))] = (conv2d_NCHWc_global[((oc_block_c15 + 60))] + (((float*)data_vec)[(((((kh * 32) + ((n_c_outer_fused_h_fused % 28) * 32)) + kw) + 15))] * kernel_vec[((((((n_c_outer_fused_h_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c15))]));
        }
        for (int32_t oc_block_c16 = 0; oc_block_c16 < 4; ++oc_block_c16) {
          conv2d_NCHWc_global[((oc_block_c16 + 64))] = (conv2d_NCHWc_global[((oc_block_c16 + 64))] + (((float*)data_vec)[(((((kh * 32) + ((n_c_outer_fused_h_fused % 28) * 32)) + kw) + 16))] * kernel_vec[((((((n_c_outer_fused_h_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c16))]));
        }
        for (int32_t oc_block_c17 = 0; oc_block_c17 < 4; ++oc_block_c17) {
          conv2d_NCHWc_global[((oc_block_c17 + 68))] = (conv2d_NCHWc_global[((oc_block_c17 + 68))] + (((float*)data_vec)[(((((kh * 32) + ((n_c_outer_fused_h_fused % 28) * 32)) + kw) + 17))] * kernel_vec[((((((n_c_outer_fused_h_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c17))]));
        }
        for (int32_t oc_block_c18 = 0; oc_block_c18 < 4; ++oc_block_c18) {
          conv2d_NCHWc_global[((oc_block_c18 + 72))] = (conv2d_NCHWc_global[((oc_block_c18 + 72))] + (((float*)data_vec)[(((((kh * 32) + ((n_c_outer_fused_h_fused % 28) * 32)) + kw) + 18))] * kernel_vec[((((((n_c_outer_fused_h_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c18))]));
        }
        for (int32_t oc_block_c19 = 0; oc_block_c19 < 4; ++oc_block_c19) {
          conv2d_NCHWc_global[((oc_block_c19 + 76))] = (conv2d_NCHWc_global[((oc_block_c19 + 76))] + (((float*)data_vec)[(((((kh * 32) + ((n_c_outer_fused_h_fused % 28) * 32)) + kw) + 19))] * kernel_vec[((((((n_c_outer_fused_h_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c19))]));
        }
        for (int32_t oc_block_c20 = 0; oc_block_c20 < 4; ++oc_block_c20) {
          conv2d_NCHWc_global[((oc_block_c20 + 80))] = (conv2d_NCHWc_global[((oc_block_c20 + 80))] + (((float*)data_vec)[(((((kh * 32) + ((n_c_outer_fused_h_fused % 28) * 32)) + kw) + 20))] * kernel_vec[((((((n_c_outer_fused_h_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c20))]));
        }
        for (int32_t oc_block_c21 = 0; oc_block_c21 < 4; ++oc_block_c21) {
          conv2d_NCHWc_global[((oc_block_c21 + 84))] = (conv2d_NCHWc_global[((oc_block_c21 + 84))] + (((float*)data_vec)[(((((kh * 32) + ((n_c_outer_fused_h_fused % 28) * 32)) + kw) + 21))] * kernel_vec[((((((n_c_outer_fused_h_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c21))]));
        }
        for (int32_t oc_block_c22 = 0; oc_block_c22 < 4; ++oc_block_c22) {
          conv2d_NCHWc_global[((oc_block_c22 + 88))] = (conv2d_NCHWc_global[((oc_block_c22 + 88))] + (((float*)data_vec)[(((((kh * 32) + ((n_c_outer_fused_h_fused % 28) * 32)) + kw) + 22))] * kernel_vec[((((((n_c_outer_fused_h_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c22))]));
        }
        for (int32_t oc_block_c23 = 0; oc_block_c23 < 4; ++oc_block_c23) {
          conv2d_NCHWc_global[((oc_block_c23 + 92))] = (conv2d_NCHWc_global[((oc_block_c23 + 92))] + (((float*)data_vec)[(((((kh * 32) + ((n_c_outer_fused_h_fused % 28) * 32)) + kw) + 23))] * kernel_vec[((((((n_c_outer_fused_h_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c23))]));
        }
        for (int32_t oc_block_c24 = 0; oc_block_c24 < 4; ++oc_block_c24) {
          conv2d_NCHWc_global[((oc_block_c24 + 96))] = (conv2d_NCHWc_global[((oc_block_c24 + 96))] + (((float*)data_vec)[(((((kh * 32) + ((n_c_outer_fused_h_fused % 28) * 32)) + kw) + 24))] * kernel_vec[((((((n_c_outer_fused_h_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c24))]));
        }
        for (int32_t oc_block_c25 = 0; oc_block_c25 < 4; ++oc_block_c25) {
          conv2d_NCHWc_global[((oc_block_c25 + 100))] = (conv2d_NCHWc_global[((oc_block_c25 + 100))] + (((float*)data_vec)[(((((kh * 32) + ((n_c_outer_fused_h_fused % 28) * 32)) + kw) + 25))] * kernel_vec[((((((n_c_outer_fused_h_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c25))]));
        }
        for (int32_t oc_block_c26 = 0; oc_block_c26 < 4; ++oc_block_c26) {
          conv2d_NCHWc_global[((oc_block_c26 + 104))] = (conv2d_NCHWc_global[((oc_block_c26 + 104))] + (((float*)data_vec)[(((((kh * 32) + ((n_c_outer_fused_h_fused % 28) * 32)) + kw) + 26))] * kernel_vec[((((((n_c_outer_fused_h_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c26))]));
        }
        for (int32_t oc_block_c27 = 0; oc_block_c27 < 4; ++oc_block_c27) {
          conv2d_NCHWc_global[((oc_block_c27 + 108))] = (conv2d_NCHWc_global[((oc_block_c27 + 108))] + (((float*)data_vec)[(((((kh * 32) + ((n_c_outer_fused_h_fused % 28) * 32)) + kw) + 27))] * kernel_vec[((((((n_c_outer_fused_h_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c27))]));
        }
      }
    }
    for (int32_t w_inner = 0; w_inner < 28; ++w_inner) {
      for (int32_t c_inner = 0; c_inner < 4; ++c_inner) {
        ((float*)output_unpack)[((((((n_c_outer_fused_h_fused / 28) * 3136) + (c_inner * 784)) + ((n_c_outer_fused_h_fused % 28) * 28)) + w_inner))] = conv2d_NCHWc_global[(((w_inner * 4) + c_inner))];
      }
    }
  }
  if (TVMBackendFreeWorkspace(1, dev_id, data_vec) != 0) {
    return -1;
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_add_1(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* T_add = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  for (int32_t ax0_ax1_fused = 0; ax0_ax1_fused < 16; ++ax0_ax1_fused) {
    for (int32_t ax2 = 0; ax2 < 14; ++ax2) {
      for (int32_t ax3_inner = 0; ax3_inner < 14; ++ax3_inner) {
        ((float*)T_add)[((((ax0_ax1_fused * 196) + (ax2 * 14)) + ax3_inner))] = (((float*)placeholder)[((((ax0_ax1_fused * 196) + (ax2 * 14)) + ax3_inner))] + ((float*)placeholder1)[(ax0_ax1_fused)]);
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_relu(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* T_relu = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  for (int32_t ax0_ax1_fused = 0; ax0_ax1_fused < 8; ++ax0_ax1_fused) {
    for (int32_t ax2 = 0; ax2 < 28; ++ax2) {
      for (int32_t ax3_outer = 0; ax3_outer < 2; ++ax3_outer) {
        for (int32_t ax3_inner = 0; ax3_inner < 16; ++ax3_inner) {
          if (((ax3_outer * 16) + ax3_inner) < 28) {
            float _1 = ((float*)placeholder)[(((((ax0_ax1_fused * 784) + (ax2 * 28)) + (ax3_outer * 16)) + ax3_inner))];
            ((float*)T_relu)[(((((ax0_ax1_fused * 784) + (ax2 * 28)) + (ax3_outer * 16)) + ax3_inner))] = ((_1) > (0.000000e+00f) ? (_1) : (0.000000e+00f));
          }
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_pad(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* T_pad = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  for (int32_t ax2 = 0; ax2 < 32; ++ax2) {
    for (int32_t ax3_outer = 0; ax3_outer < 2; ++ax3_outer) {
      for (int32_t ax3_inner = 0; ax3_inner < 16; ++ax3_inner) {
        ((float*)T_pad)[((((ax2 * 32) + (ax3_outer * 16)) + ax3_inner))] = (((((2 <= ax2) && (ax2 < 30)) && (2 <= ((ax3_outer * 16) + ax3_inner))) && (((ax3_outer * 16) + ax3_inner) < 30)) ? ((float*)placeholder)[(((((ax2 * 28) + (ax3_outer * 16)) + ax3_inner) - 58))] : ((float*)placeholder1)[(0)]);
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_dense(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* compute = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  void* packed_weight = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)10240, 2, 32);
  if (packed_weight == NULL) {
    return -1;
  }
  for (int32_t z = 0; z < 2; ++z) {
    for (int32_t y = 0; y < 256; ++y) {
      for (int32_t x = 0; x < 5; ++x) {
        ((float*)packed_weight)[((((z * 1280) + (y * 5)) + x))] = ((float*)placeholder1)[((((z * 1280) + (x * 256)) + y))];
      }
    }
  }
  for (int32_t x_outer_y_outer_fused = 0; x_outer_y_outer_fused < 2; ++x_outer_y_outer_fused) {
    float compute_global[5];
    for (int32_t x_c_init = 0; x_c_init < 5; ++x_c_init) {
      compute_global[(x_c_init)] = 0.000000e+00f;
    }
    for (int32_t k_outer = 0; k_outer < 256; ++k_outer) {
      for (int32_t x_c = 0; x_c < 5; ++x_c) {
        compute_global[(x_c)] = (compute_global[(x_c)] + (((float*)placeholder)[(k_outer)] * ((float*)packed_weight)[((((x_outer_y_outer_fused * 1280) + (k_outer * 5)) + x_c))]));
      }
    }
    for (int32_t x_inner_inner = 0; x_inner_inner < 5; ++x_inner_inner) {
      ((float*)compute)[(((x_outer_y_outer_fused * 5) + x_inner_inner))] = compute_global[(x_inner_inner)];
    }
  }
  if (TVMBackendFreeWorkspace(1, dev_id, packed_weight) != 0) {
    return -1;
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_relu_1(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* T_relu = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  for (int32_t ax0_ax1_fused = 0; ax0_ax1_fused < 16; ++ax0_ax1_fused) {
    for (int32_t ax2 = 0; ax2 < 14; ++ax2) {
      for (int32_t ax3_inner = 0; ax3_inner < 14; ++ax3_inner) {
        float _1 = ((float*)placeholder)[((((ax0_ax1_fused * 196) + (ax2 * 14)) + ax3_inner))];
        ((float*)T_relu)[((((ax0_ax1_fused * 196) + (ax2 * 14)) + ax3_inner))] = ((_1) > (0.000000e+00f) ? (_1) : (0.000000e+00f));
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_reshape(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* T_reshape = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  for (int32_t ax1_outer = 0; ax1_outer < 16; ++ax1_outer) {
    for (int32_t ax1_inner = 0; ax1_inner < 16; ++ax1_inner) {
      ((float*)T_reshape)[(((ax1_outer * 16) + ax1_inner))] = ((float*)placeholder)[(((ax1_outer * 16) + ax1_inner))];
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_add_2(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* T_add = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  for (int32_t ax1_inner = 0; ax1_inner < 10; ++ax1_inner) {
    ((float*)T_add)[(ax1_inner)] = (((float*)placeholder)[(ax1_inner)] + ((float*)placeholder1)[(ax1_inner)]);
  }
  return 0;
}

