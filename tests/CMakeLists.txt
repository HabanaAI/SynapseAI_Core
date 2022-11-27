# COPYRIGHT (c) 2019-2021 Habanalabs Ltd. See COPYING.md file

cmake_minimum_required(VERSION 3.5.1)
project (synapse_core_tests)
set(TARGET1 memcpy_test)
set(TARGET2 div_test)

set (CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS_DEBUG "-ggdb -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG -fopenmp")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(FATAL_ERROR "Compiler does not support C++11")
endif()


add_executable(${TARGET1} memcpy_test.cpp test_infra.cpp)
add_executable(${TARGET2} div_test.cpp test_infra.cpp)

set (INCLUDE_PATH ../external_includes/)
target_link_libraries(${TARGET1} synapse_core)
target_link_libraries(${TARGET2} synapse_core)

include_directories(${INCLUDE_PATH})
