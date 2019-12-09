# targets
all: battle battletest

battle: main.o graphics.o game.o fps.o unit.o
	g++ main.o graphics.o game.o fps.o unit.o -o $@ -lSDL2 -lSDL2_image

battletest: unit-test.o unit.o graphics.o
	g++ unit-test.o unit.o graphics.o -o $@ -lSDL2 -lSDL2_image

clean:
	rm -f *.o
# objects:
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

unit-test.o: test/unit-test.cpp lib/catch.hpp src/unit.h
	g++ -c test/unit-test.cpp


