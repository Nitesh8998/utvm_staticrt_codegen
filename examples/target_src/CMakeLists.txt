CMAKE_MINIMUM_REQUIRED(VERSION 3.1 FATAL_ERROR)
PROJECT(example_target_src)

INCLUDE(../../cmake/LinkTVM.cmake)

SET(TVM_ROOT "/home/nitesh/nitesh_nfs_share/tvm/")
SET(DMLC_CORE "${TVM_ROOT}/3rdparty/dmlc-core")
SET(GEM5_PATH "/home/nitesh/nitesh_nfs_share/gem5-gaia")

#SET(PKG_CFLAGS "-std=c++14 -O2 -fPIC -march=armv8-a+sve -I${GEM5_PATH}/include -I${TVM_ROOT}/include -I${DMLC_CODE}/include -I${TVM_ROOT}/3rdparty/dlpack/include ")
SET(PKG_CFLAGS " -Ofast -frecord-gcc-switches -fPIC -march=armv8-a+sve2 -I${GEM5_PATH}/include -I${TVM_ROOT}/include -I${DMLC_CODE}/include -I${TVM_ROOT}/3rdparty/dlpack/include ")

SET(PKG_LDFLAGS "-L/home/nitesh/nitesh_nfs_share/runtime/arm_runtime -ldl -pthread")
SET(GEM5_LDFLAGS "-L${GEM5_PATH}/util/m5/build/aarch64/out -lm5")
# CROSS COMPILING
SET(CMAKE_C_COMPILER  aarch64-linux-gnu-gcc-10)
#SET(CMAKE_C_COMPILER  clang)
SET(CMAKE_CXX_COMPILER  aarch64-linux-gnu-g++-10)


# Enable DBGPRINTF() in DEBUG mode (`cmake -DCMAKE_BUILD_TYPE=Debug ..`)
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG -DTVMCG_DEBUG_ALLOCATIONS")
SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -D_DEBUG -DTVMCG_DEBUG_ALLOCATIONS")

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${PKG_CFLAGS}")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${PKG_CFLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${PKG_LDFLAGS}")




SET(TVM_OUT_DIR ../out)

FILE(GLOB TVM_KERNELS
    ${TVM_OUT_DIR}/lib*.c
    ${TVM_OUT_DIR}/lib*.cc
    # New model will have model name prefix
    ${TVM_OUT_DIR}/*_lib*.c
    ${TVM_OUT_DIR}/*_lib*.cc
    ${TVM_OUT_DIR}/*.o
)

ADD_EXECUTABLE(${PROJECT_NAME}
    main.c
    ${TVM_OUT_DIR}/staticrt.c
    ${TVM_KERNELS}
)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} PUBLIC tvm_static_rt)
TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
