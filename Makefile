battle : main.o graphics.o game.o fps.o unit.o
	g++ main.o graphics.o game.o fps.o unit.o -o battle -lSDL2 -lSDL2_image

#test: 

main.o : src/main.cpp src/graphics.h
	g++ -c src/main.cpp

graphics.o: src/graphics.cpp
	g++ -c src/graphics.cpp

game.o: src/game.cpp src/graphics.h
	g++ -c src/game.cpp

fps.o: src/fps.cpp
	g++ -c src/fps.cpp

unit.o: src/unit.cpp
	g++ -c src/unit.cpp

