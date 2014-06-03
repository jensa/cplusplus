char:
	c++ -std=c++0x -c character/character.cpp -o bin/character.o
player:
	c++ -std=c++0x -c character/player.cpp -o bin/player.o
npc:
	c++ -std=c++0x -c character/npc.cpp -o bin/npc.o
troll:
	c++ -std=c++0x -c character/troll.cpp -o bin/troll.o
obj:
	c++ -std=c++0x -c object/object.cpp -o bin/object.o
ring:
	c++ -std=c++0x -c object/ring.cpp -o bin/ring.o
container:
	c++ -std=c++0x -c object/container.cpp -o bin/container.o
pocket:
	c++ -std=c++0x -c object/pocket.cpp -o bin/pocket.o
bag:
	c++ -std=c++0x -c object/bag.cpp -o bin/bag.o
env:
	c++ -std=c++0x -c environment/environment.cpp -o bin/environment.o
darkroom:
	c++ -std=c++0x -c environment/darkroom.cpp -o bin/darkroom.o

main: char player npc troll obj ring container pocket bag env darkroom
	c++ -std=c++0x -o main.o main.cpp bin/character.o bin/player.o bin/npc.o bin/troll.o bin/object.o bin/ring.o bin/container.o bin/pocket.o bin/bag.o bin/environment.o bin/darkroom.o

clean:
	rm -r *.o