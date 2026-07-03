#!/bin/zsh
rm -rf ./build
cmake -B build
cmake --build build --parallel
mv build/game .
./game