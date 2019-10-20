#!/bin/bash

if [[ "$OSTYPE" == "win32" || "$OSTYPE" == "cygwin" || "$OSTYPE" == "msys" ]] 
then
	WINDOWS=true
else
	WINDOWS=false
fi

mkdir -p bin
cd bin

if [[ "$WINDOWS" = true ]]; then
	cmake .. -G "MinGW Makefiles"
    mingw32-make
	SOURCE='libs/SFML/lib'
	for file in $SOURCE/*.dll
	do
		cp ${file} .
	done
else
	cmake ..
    make
fi
cd ..