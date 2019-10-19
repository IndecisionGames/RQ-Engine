#!/bin/bash

mkdir -p bin
cd bin
cmake ..

if [[ "$OSTYPE" == "win32" ]]; then
    mingw32-make
else
    make
fi
