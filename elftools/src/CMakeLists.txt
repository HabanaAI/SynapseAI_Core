# COPYRIGHT (c) 2019-2021 Habanalabs Ltd. See COPYING.md file

set(ELFTOOL elftool)
set(TPC_ELF_READEER TpcElfReader)

set(CMAKE_CXX_FLAGS_DEBUG "-ggdb -O0 ")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")
if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, defaulting to Debug")
    set(CMAKE_BUILD_TYPE "Debug")
endif()

file(GLOB ELFTOLLREAD elfTool.cpp)
file(GLOB TPCELFREADEF *.cpp)

include_directories(./
                    ./elfio/
                    ../../external_includes/
)

ADD_LIBRARY(${TPC_ELF_READEER} SHARED ${TPCELFREADEF})
