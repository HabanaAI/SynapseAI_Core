# COPYRIGHT (c) 2019-2021 Habanalabs Ltd. See COPYING.md file

# Decide which files to compile
file(GLOB SRC *.cpp)

# define .so object for compiling.
add_library(${SYNAPSE_CORE_TARGET} SHARED ${SRC})

target_include_directories(${SYNAPSE_CORE_TARGET} PUBLIC
                    ../synapse_backend/low_level_driver/
                    ../synapse_backend/infra/
                    ../external_includes/)

target_link_libraries(${SYNAPSE_CORE_TARGET} synapse_backend TpcElfReader dl)
