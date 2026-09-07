#!/bin/zsh
rm -rf ./build
cmake -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --parallel
mv build/game .
./game