battle : main.o graphics.o
	g++ main.o graphics.o -o battle -lSDL2 -lSDL2_image

main.o : src/main.cpp src/graphics/graphics.h
	g++ -c src/main.cpp
