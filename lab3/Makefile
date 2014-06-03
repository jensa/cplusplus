char:
	c++ -std=c++0x -g -c character/character.cpp -o bin/character.o
	c++ -std=c++0x -g -c character/player.cpp -o bin/player.o
	c++ -std=c++0x -g -c character/npc.cpp -o bin/npc.o
	c++ -std=c++0x -g -c character/troll.cpp -o bin/troll.o
	c++ -std=c++0x -g -c character/necromancer.cpp -o bin/necromancer.o
	c++ -std=c++0x -g -c character/lampmaker.cpp -o bin/lampmaker.o
	c++ -std=c++0x -g -c character/dragon.cpp -o bin/dragon.o

obj:
	c++ -std=c++0x -g -c object/object.cpp -o bin/object.o
	c++ -std=c++0x -g -c object/ring.cpp -o bin/ring.o
	c++ -std=c++0x -g -c object/container.cpp -o bin/container.o
	c++ -std=c++0x -g -c object/pocket.cpp -o bin/pocket.o
	c++ -std=c++0x -g -c object/bag.cpp -o bin/bag.o
	c++ -std=c++0x -g -c object/key.cpp -o bin/key.o
	c++ -std=c++0x -g -c object/lamp.cpp -o bin/lamp.o
	c++ -std=c++0x -g -c object/weapon.cpp -o bin/weapon.o
	c++ -std=c++0x -g -c object/pointeritem.cpp -o bin/pointeritem.o

env:
	c++ -std=c++0x -g -c environment/environment.cpp -o bin/environment.o
	c++ -std=c++0x -g -c environment/darkroom.cpp -o bin/darkroom.o
	c++ -std=c++0x -g -c environment/lockedroom.cpp -o bin/lockedroom.o

main: char obj env
	c++ -std=c++0x -g -o main.o main.cpp bin/character.o bin/player.o bin/npc.o bin/troll.o bin/necromancer.o bin/lampmaker.o bin/dragon.o bin/object.o bin/ring.o bin/container.o bin/pocket.o bin/bag.o bin/key.o bin/lamp.o bin/weapon.o bin/pointeritem.o bin/environment.o bin/darkroom.o bin/lockedroom.o

clean:
	rm -r *.o