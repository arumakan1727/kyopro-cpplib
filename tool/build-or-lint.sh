#!/bin/bash

set -eu

if [ $# -ne 1 ]; then
  echo "Usage: $0 <SourceFile>" 1>&2
  exit 1
fi

SCRIPT_DIR=$(cd $(dirname $0); pwd)
COMPILE_FLAGS_FILE=$SCRIPT_DIR/../compile_flags.txt
BITS_DIR=$SCRIPT_DIR/../bits-dir

file=$1
fileExt=${file##*.}
fileDir=$(dirname $file)
fileBasename=$(basename $file)
basenameWithoutExt=${fileBasename%.*}

# Debug
# echo $SCRIPT_DIR
# echo $file
# echo $fileExt
# echo $fileDir
# echo $fileBasename
# echo $basenameWithoutExt

if [ $fileExt = hpp -o $fileExt = h ]; then
  echo "/usr/bin/g++ -fsyntax-only @$COMPILE_FLAGS_FILE $file"
  /usr/bin/g++ -fsyntax-only @$COMPILE_FLAGS_FILE $file
else
  echo "/usr/bin/g++ @$COMPILE_FLAGS_FILE -I${BITS_DIR} $file -o $fileDir/build/$basenameWithoutExt.bin"
  /usr/bin/g++ @$COMPILE_FLAGS_FILE -I${BITS_DIR} $file -o $fileDir/build/$basenameWithoutExt.bin
fi
