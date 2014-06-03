char:
	c++ -std=c++0x -c character/character.cpp -o bin/character.o
	c++ -std=c++0x -c character/player.cpp -o bin/player.o
	c++ -std=c++0x -c character/npc.cpp -o bin/npc.o
	c++ -std=c++0x -c character/troll.cpp -o bin/troll.o

obj:
	c++ -std=c++0x -c object/object.cpp -o bin/object.o
	c++ -std=c++0x -c object/ring.cpp -o bin/ring.o
	c++ -std=c++0x -c object/container.cpp -o bin/container.o
	c++ -std=c++0x -c object/pocket.cpp -o bin/pocket.o
	c++ -std=c++0x -c object/bag.cpp -o bin/bag.o
	c++ -std=c++0x -c object/key.cpp -o bin/key.o
	c++ -std=c++0x -c object/lamp.cpp -o bin/lamp.o
	c++ -std=c++0x -c object/weapon.cpp -o bin/weapon.o

env:
	c++ -std=c++0x -c environment/environment.cpp -o bin/environment.o
	c++ -std=c++0x -c environment/darkroom.cpp -o bin/darkroom.o
	c++ -std=c++0x -c environment/lockedroom.cpp -o bin/lockedroom.o

main: char obj env
	c++ -std=c++0x -o main.o main.cpp bin/character.o bin/player.o bin/npc.o bin/troll.o bin/object.o bin/ring.o bin/container.o bin/pocket.o bin/bag.o bin/key.o bin/lamp.o bin/weapon.o bin/environment.o bin/darkroom.o bin/lockedroom.o

clean:
	rm -r *.o