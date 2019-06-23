battle : main.o graphics.o game.o
	g++ main.o graphics.o game.o -o battle -lSDL2 -lSDL2_image

main.o : src/main.cpp src/graphics/graphics.h
	g++ -c src/main.cpp

graphics.o: src/graphics/graphics.cpp src/globals.h
	g++ -c src/graphics/graphics.cpp

game.o: src/game.cpp src/graphics/graphics.h
	g++ -c src/game.cpp