# targets
all: battle

battle: main.o graphics.o controller.o game.o fps.o unit.o utils.o
	g++ main.o graphics.o controller.o game.o fps.o unit.o utils.o -o $@ -lSDL2 -lSDL2_image

tests: utilstest unittest
	./utilstest
	./unittest

utilstest: utils-test.o utils.o
	g++ utils-test.o graphics.o controller.o unit.o utils.o -o $@ -lSDL2 -lSDL2_image

unittest: unit-test.o graphics.o controller.o unit.o utils.o
	g++ unit-test.o graphics.o controller.o unit.o utils.o -o $@ -lSDL2 -lSDL2_image

clean:
	rm -f *.o battle battletest

# objects:
main.o: src/main.cpp src/graphics.h
	g++ -c src/main.cpp

graphics.o: src/graphics.cpp
	g++ -c src/graphics.cpp

game.o: src/game.cpp src/graphics.h src/controller.h
	g++ -c src/game.cpp

fps.o: src/fps.cpp
	g++ -c src/fps.cpp

unit.o: src/unit.cpp src/utils.h
	g++ -c src/unit.cpp

controller.o: src/controller.cpp src/unit.h
	g++ -c src/controller.cpp

utils.o: src/utils.cpp
	g++ -c src/utils.cpp

# test objects
unit-test.o: test/unit-test.cpp lib/catch.hpp src/unit.h
	g++ -c test/unit-test.cpp

utils-test.o: test/utils-test.cpp lib/catch.hpp
	g++ -c test/utils-test.cpp

