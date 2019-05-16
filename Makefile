battle : main.o graphics.o
	g++ main.o graphics.o -o battle -lSDL2 -lSDL2_image

main.o : main.cpp graphics.h
	g++ -c main.cpp
