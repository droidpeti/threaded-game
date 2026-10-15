#!/bin/bash
cd "$(dirname "$0")/.."

mkdir -p out
mkdir -p out/sfw

g++ -Wall -g -c sfw/sfw.cpp -o out/sfw/sfw.o
g++ -Wall -g -c test_scene.cpp -o out/test_scene.o
g++ -Wall -g -c test_application.cpp -o out/test_application.o
g++ -Wall -g -c main.cpp -o out/main.o

# You might need to add -lpthread and/or -latomic depending on your compiler version 
g++ -Wall -g out/sfw/sfw.o out/test_scene.o out/test_application.o out/main.o \
    -lgdi32 -lShlwapi -lws2_32 \
    -o out/game.exe