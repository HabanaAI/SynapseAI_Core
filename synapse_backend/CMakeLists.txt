# COPYRIGHT (c) 2019-2021 Habanalabs Ltd. See COPYING.md file

cmake_minimum_required(VERSION 3.5.1)

set(HLTHUNK_LIB_PATH "/usr/lib/habanalabs" CACHE STRING "Path to hl-thunk library")
set(HLTHUNK_INCLUDE_PATH "/usr/include/habanalabs" CACHE STRING "Path to hl-thunk headers")
set(DRIVER_INCLUDE_PATH "/usr/include" CACHE STRING "Path to driver uapi header")

# Decide which files to compile
file(GLOB_RECURSE SRC *.cpp)

# define .so object for compiling.
add_library(${SYNAPSE_BACKEND_TARGET} SHARED ${SRC})

set (TESTS_CORE_EXTERNAL 1)

set (HLTHUNK_LIBRARY ${HLTHUNK_LIB_PATH}/libhl-thunk.so)

target_compile_options(${SYNAPSE_BACKEND_TARGET} PUBLIC -DTESTS_CORE_EXTERNAL=1)

target_include_directories(${SYNAPSE_BACKEND_TARGET} PUBLIC
                    ./low_level_driver/
                    ./infra/
                    ../external_includes/
                    ${HLTHUNK_INCLUDE_PATH}/
                    ${DRIVER_INCLUDE_PATH}/
                    )

target_link_libraries(${SYNAPSE_BACKEND_TARGET} ${HLTHUNK_LIBRARY})
