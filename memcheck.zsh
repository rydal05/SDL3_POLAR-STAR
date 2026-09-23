#!/bin/zsh
rm -rf ./build
cmake -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --parallel
mv build/game .
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./game -s