mkdir -p out

g++ -Wall -g -c sfw.cpp -o out/sfw.o
g++ -Wall -g -c game_scene.cpp -o out/game_scene.o
g++ -Wall -g -c main.cpp -o out/main.o

g++ -Wall -static-libgcc -static-libstdc++ -g out/sfw.o out/game_scene.o out/main.o -lX11 -o out/game