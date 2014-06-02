character:
	c++ -std=c++0x -c character.cpp -o character.o
player:
	c++ -std=c++0x -c player.cpp -o player.o
npc:
	c++ -std=c++0x -c npc.cpp -o npc.o
object:
	c++ -std=c++0x -c object.cpp -o object.o
ring:
	c++ -std=c++0x -c ring.cpp -o ring.o
container:
	c++ -std=c++0x -c container.cpp -o container.o
pocket:
	c++ -std=c++0x -c pocket.cpp -o pocket.o
bag:
	c++ -std=c++0x -c bag.cpp -o bag.o
environment:
	c++ -std=c++0x -c environment.cpp -o environment.o

main: character player npc object ring container pocket bag environment
	c++ -std=c++0x -o main.o main.cpp character.o player.o npc.o object.o ring.o container.o pocket.o bag.o environment.o

