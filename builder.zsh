#!/bin/zsh

cmake -B build
cmake --build build --parallel
mv build/game .
./game