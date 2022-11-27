# COPYRIGHT (c) 2019-2021 Habanalabs Ltd. See COPYING.md file
cmake_minimum_required(VERSION 3.5.1)

project (tpc_kernels_db)

set(TPC_LLVM_BIN_PATH "/usr/bin" CACHE STRING "Path to TPC LLVM binaries")

set(TPC_COMPILER_PATH "${TPC_LLVM_BIN_PATH}/tpc-clang" CACHE STRING "Path to TPC C/C++ compiler")
set(TPC_DISASSEMBLER_PATH "${TPC_LLVM_BIN_PATH}/tpc-llvm-objdump" CACHE STRING "Path to TPC disassembler")
set(TPC_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../external_includes" CACHE STRING "Path to TPC includes")
set(TPC_CURRENT_LIST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/kernels/include" CACHE STRING "Path to kernel includes")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror -Wno-sign-compare -fno-strict-aliasing")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe")

if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 8.0)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-attributes")
endif()

if (NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS 7.0)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-parentheses")
endif()

# Add TPC-C source files to be compiled by TPC Gaudi compiler and
# linked into tpc_kernels executable.
file(GLOB TPC_C_GAUDI_SOURCES_TO_EMBED ./kernels/gaudi/*.c)
file(GLOB TPC_C_GAUDI2_SOURCES_TO_EMBED ./kernels/gaudi2/*.c)

# Generate a list of all TPC headers for compilation dependencies.
file(GLOB TPC_GAUDI_HEADERS ./kernels/include/*.h)

include_directories(../external_includes)

add_subdirectory(src)  # build production
