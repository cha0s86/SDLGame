#!/usr/bin/bash
g++ -o main main.cpp game.cpp -I./include/ -L./lib/ -lSDL2 -lSDL2main -lSDL2_mixer -lSDL2_image
