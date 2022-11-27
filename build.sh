#!/bin/bash
set -e

# If the TPC LLVM binaries are not installed in /usr/bin, you need
# to manually point to them. e.g. if they are located at
# $HOME/habanaTools/build/bin then you need to define EXTRA_CMAKE_FLAGS as:
# 
# EXTRA_CMAKE_FLAGS=-DTPC_LLVM_BIN_PATH=$HOME/habanaTools/build/bin

# If the hl-thunk library is not installed in /usr/lib/habanalabs,
# you need to manually point to it. e.g. if it is located at
# $HOME/hl-thunk/build/lib then you need to define EXTRA_CMAKE_FLAGS as:
# EXTRA_CMAKE_FLAGS=-DHLTHUNK_LIB_PATH=$HOME/hl-thunk/build/lib

# If the hl-thunk headers are not installed in /usr/include/habanalabs,
# you need to manually point to them. e.g. if they are located at
# $HOME/hl-thunk/include/uapi then you need to define EXTRA_CMAKE_FLAGS as:
# EXTRA_CMAKE_FLAGS=-DHLTHUNK_INCLUDE_PATH=$HOME/hl-thunk/include/uapi

# If the driver uapi header is not found at /usr/include/misc/habanalabs.h,
# you need to manually point to it. e.g. if it is located at
# $HOME/habanalabs/include/uapi/misc/habanalabs.h
# then you need to define EXTRA_CMAKE_FLAGS as:
# EXTRA_CMAKE_FLAGS=-DDRIVER_INCLUDE_PATH=$HOME/habanalabs/include/uapi

SECONDS=0;
SRCDIR=`dirname $0`
BUILDDIR="$SRCDIR/build"
build_type="Release"

while [ -n "$1" ]; do
    case $1 in 
        -debug)
            build_type="Debug"
            ;;
    esac;
    shift;
done

if [ -d $BUILDDIR ]; then
	rm -rf $BUILDDIR
fi

mkdir -p "$BUILDDIR"

if hash cmake3 2>/dev/null; then
    # CentOS users should install cmake3 from EPEL
    CMAKE=cmake3
else
    CMAKE=cmake
fi

cd "$BUILDDIR"

$CMAKE -DCMAKE_BUILD_TYPE=${build_type} ${EXTRA_CMAKE_FLAGS:-} ..
make -j8

printf "\nElapsed time: %02u:%02u:%02u \n\n" $(($SECONDS / 3600)) $((($SECONDS / 60) % 60)) $(($SECONDS % 60));

