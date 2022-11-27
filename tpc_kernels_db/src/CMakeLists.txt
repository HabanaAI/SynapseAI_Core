# COPYRIGHT (c) 2019-2021 Habanalabs Ltd. See COPYING.md file

set(TPC_PERF_TARGET custom_tpc_perf_lib)

# Decide which files to compile
file(GLOB SRC *.cpp gaudi_src/*.cpp)

# define .so object for compiling.
add_library(${TPC_PERF_TARGET} SHARED ${SRC})

include_directories(.
                    gaudi_src
                    )

IF( NOT CMAKE_BUILD_TYPE )
   SET( CMAKE_BUILD_TYPE Release ... FORCE )
ENDIF()

if ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    set (COND_EXEC "echo")
    set (OPT_FLAG "-O0")
    set (DEBUG_FLAG "-g")
    message("Debug mode is on")
else()
    set (OPT_FLAG "-O2")
    set (DEBUG_FLAG "")
    message("Debug mode is off")
endif()
separate_arguments(OPT_FLAG)

# This routine does the following:
# 1. Copies the TPC-C source file to 'bin' for reference.
# 2. Compiles sources using TPC-C compiler (two times - one is for testing of compiler regression).
# 3. Wraps compiler output in X86 elf.
# 4. Links the X86 elf into the executable
# 5. Disassemble the file for debug purposes
function(CompileTPCCWithClang TPC_C_SOURCES_TO_EMBED TPC_HEADERS deviceName)
    set(OBJ_LIST )
    foreach(SOURCE_FILE  ${TPC_C_SOURCES_TO_EMBED})
        file(RELATIVE_PATH RELATIVE_FILE_PATH ${CMAKE_SOURCE_DIR}  ${SOURCE_FILE})
        get_filename_component(RELATIVE_DIRECTORY ${RELATIVE_FILE_PATH} DIRECTORY)
        get_filename_component(SOURCE_NAME_NO_PATH_NO_SUFFIX ${SOURCE_FILE} NAME_WE)
        get_filename_component(SOURCE_FILE_NAME_NO_PATH ${SOURCE_FILE} NAME)
        if ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug" AND "${SOURCE_FILE_NAME_NO_PATH}" STREQUAL "filter_2d_i8_w33_s11.c")
            set (OPT_FLAG "-O1")
        elseif("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
            set (OPT_FLAG "-O0")
        endif()

        # get prefix from relative path (for example: get "_gaudi2_spatial_pooling" from "kernels/gaudi2/spatial/pooling")
        string(REGEX MATCHALL  "/.*" WITHOUT_PARENT_DIR ${RELATIVE_DIRECTORY})
        string(REPLACE "/" "_" PATH_PREFIX ${WITHOUT_PARENT_DIR})

        file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${RELATIVE_DIRECTORY})

        add_custom_command(OUTPUT "${RELATIVE_DIRECTORY}/${SOURCE_NAME_NO_PATH_NO_SUFFIX}_x86.o"
            DEPENDS ${SOURCE_FILE} ${TPC_COMPILER_PATH} ${TPC_HEADERS}
            IMPLICIT_DEPENDS C ${SOURCE_FILE}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${RELATIVE_DIRECTORY}
            COMMAND cp ${SOURCE_FILE}  ${CMAKE_CURRENT_BINARY_DIR}/${RELATIVE_FILE_PATH}
            COMMAND ${TPC_COMPILER_PATH} -Wall -Werror -march=${deviceName} ${OPT_FLAG} ${DEBUG_FLAG} -I${TPC_INCLUDE_DIR}/ -I${TPC_CURRENT_LIST_DIR} ./${SOURCE_FILE_NAME_NO_PATH} -c
            COMMAND objcopy -I binary -O elf64-x86-64 -B i386:x86-64 --prefix-symbols=${PATH_PREFIX} ./${SOURCE_NAME_NO_PATH_NO_SUFFIX}.o "${SOURCE_NAME_NO_PATH_NO_SUFFIX}_x86.o"
            COMMAND  ${TPC_DISASSEMBLER_PATH} --triple tpc -d -j .text --no-show-raw-insn --no-leading-addr --mcpu=${deviceName} ${SOURCE_NAME_NO_PATH_NO_SUFFIX}.o > ${SOURCE_NAME_NO_PATH_NO_SUFFIX}.tpcasm)
        list(APPEND OBJ_LIST "${RELATIVE_DIRECTORY}/${SOURCE_NAME_NO_PATH_NO_SUFFIX}_x86.o")
    endforeach()

    add_library(${deviceName} STATIC ${OBJ_LIST})
    set_target_properties(${deviceName} PROPERTIES LINKER_LANGUAGE C)
    target_include_directories(${deviceName} PRIVATE ${TPC_HEADERS})
    target_link_libraries(${TPC_PERF_TARGET} ${deviceName})
endfunction(CompileTPCCWithClang)

CompileTPCCWithClang("${TPC_C_GAUDI_SOURCES_TO_EMBED}" "${TPC_GAUDI_HEADERS}" gaudi)
CompileTPCCWithClang("${TPC_C_GAUDI2_SOURCES_TO_EMBED}" "${TPC_GAUDI_HEADERS}" gaudi2)
