all: battle test

battle: main.o graphics.o game.o fps.o unit.o
	g++ main.o graphics.o game.o fps.o unit.o -o battle -lSDL2 -lSDL2_image

test: unit-test.o unit.o
	g++ unit-test.o unit.o -o test

main.o: src/main.cpp src/graphics.h
	g++ -c src/main.cpp

graphics.o: src/graphics.cpp
	g++ -c src/graphics.cpp

game.o: src/game.cpp src/graphics.h
	g++ -c src/game.cpp

fps.o: src/fps.cpp
	g++ -c src/fps.cpp

unit.o: src/unit.cpp
	g++ -c src/unit.cpp

# unit tests:
unit-test.o: test/unit-test.cpp src/unit.h
	g++ -c test/unit-test.cpp
