character:
	c++ -std=c++0x -c character.cpp -o character.o
player:
	c++ -std=c++0x -c player.cpp -o player.o
troll:
	c++ -std=c++0x -c troll.cpp -o troll.o
object:
	c++ -std=c++0x -c object.cpp -o object.o
environment:
	c++ -std=c++0x -c environment.cpp -o environment.o

game: character player troll object environment
	c++ -std=c++0x -o game.o game.cpp character.o player.o troll.o object.o environment.o

