julian:
	c++ -std=c++0x -c julian.cpp -o julian.o
gregorian:
	c++ -std=c++0x -c gregorian.cpp -o gregorian.o
european:
	c++ -std=c++0x -c european.cpp -o european.o
date:
	c++ -std=c++0x -c date.cpp -o date.o
test: julian gregorian european date
	c++ -std=c++0x  datetest.cpp julian.o gregorian.o date.o european.o kattistime.cpp kattistime.h