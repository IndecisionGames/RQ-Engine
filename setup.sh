#!/bin/bash

mkdir -p build-libs
cd build-libs
mkdir -p SFML
cd SFML
cmake ../../libs/SFML

if [[ "$OSTYPE" == "win32" ]]; then
    mingw32-make
else
    make
fi
