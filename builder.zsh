#!/bin/zsh
rm -rf ./build
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel --config Release -j
mv build/game .
./game