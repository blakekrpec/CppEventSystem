#!/bin/bash

if [[ "$1" == "--clean" ]]; then
    if [ -d "build" ]; then
        echo "Cleaning build directory..."
        rm -rf build
    fi
fi

if [ ! -d "build" ]; then
    echo "Creating build directory..."
    mkdir build
fi

cd build
cmake ..

# wait until compile_commands.json exists and is not empty
while [ ! -s compile_commands.json ]; do
  echo "Waiting for compile_commands.json to be created..."
  sleep 0.5
done

rm -f ../compile_commands.json
ln -s $(pwd)/compile_commands.json ../compile_commands.json

cmake --build .
