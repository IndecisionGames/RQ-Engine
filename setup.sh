#!/bin/bash

if [ "$#" -ne 1 ]
then
  echo "Usage: ./setup.sh all/box/sfml"
  exit 1
fi

SETUP=[]
if [[ "$1" == "all" ]]; then
    SETUP="SFML", "Box2D"
elif [[ "$1" == "box" ]]; then
    SETUP="Box2D"
elif [[ "$1" == "sfml" ]]; then
    SETUP="SFML"
fi

mkdir -p build-libs
cd build-libs
for LIB in ${SETUP}
do
    echo "Building ${LIB}."
    mkdir -p $LIB
    cd $LIB
    cmake ../../libs/$LIB

    echo "Making ${LIB}."
    if [[ "$OSTYPE" == "win32" ]]; then
        mingw32-make
    else
        make
    fi

    cd ..
done
