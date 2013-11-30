item:
	c++ -std=c++0x -c Item.cpp -o Item.o
container:
	c++ -std=c++0x -c Container.cpp -o Container.o

itemtest: item container
	c++ -std=c++0x -o ItemTest.o ItemTest.cpp Item.o Container.o