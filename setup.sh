#!/bin/bash

mkdir -p build-libs
cd build-libs
mkdir -p SFML
cd SFML
cmake ../../libs/SFML
make
