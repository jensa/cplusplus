character:
	c++ -std=c++0x -c character.cpp -o character.o
player:
	c++ -std=c++0x -c player.cpp -o player.o
npc:
	c++ -std=c++0x -c npc.cpp -o npc.o
object:
	c++ -std=c++0x -c object.cpp -o object.o
environment:
	c++ -std=c++0x -c environment.cpp -o environment.o

main: character player npc object environment
	c++ -std=c++0x -o main.o main.cpp character.o player.o npc.o object.o environment.o

