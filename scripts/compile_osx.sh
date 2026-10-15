#!/bin/bash
cd "$(dirname "$0")/.."

export SDKROOT=$(xcrun --show-sdk-path)
export args="-std=c++14 -w -framework Cocoa -framework IOKit -framework CoreFoundation -framework CoreAudio -framework AudioToolbox"

mkdir -p out
mkdir -p out/sfw

clang++ $args -g -c sfw/sfw.cpp -o out/sfw/sfw.o
clang++ -w -framework Cocoa -framework IOKit -framework CoreFoundation -framework CoreAudio -framework AudioToolbox -g -c sfw/sfw_3rd.m -o out/sfw/sfw_3rd.o

clang++ $args -g -c test_scene.cpp -o out/test_scene.o
clang++ $args -g -c test_application.cpp -o out/test_application.o
clang++ $args -g -c main.cpp -o out/main.o

# You might need to add -lpthread and/or -latomic depending on your compiler version 
clang++ $args -g out/sfw/sfw.o out/sfw/sfw_3rd.o out/test_scene.o out/test_application.o out/main.o -o out/game