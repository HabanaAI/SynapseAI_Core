# COPYRIGHT (c) 2019-2021 Habanalabs Ltd. See COPYING.md file

cmake_minimum_required(VERSION 3.5.1)

project(synapse_core)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror -Wno-sign-compare -fno-strict-aliasing")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe")

if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 8.0)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-attributes")
endif()

if (NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS 7.0)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-parentheses")
endif()

set(SYNAPSE_BACKEND_TARGET synapse_backend)
set(SYNAPSE_CORE_TARGET synapse_core)

# Copy library files to a lib sub-directory
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# Copy executable files to a bin sub-directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

add_subdirectory(synapse_backend)
add_subdirectory(elftools)
add_subdirectory(synapse_core)
add_subdirectory(tpc_kernels_db)
add_subdirectory(tests)
