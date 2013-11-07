julian:
	c++ -std=c++0x -c julian.cpp -o julian.o
gregorian:
	c++ -std=c++0x -c gregorian.cpp -o gregorian.o
european:
	c++ -std=c++0x -c european.cpp -o european.o
date:
	c++ -std=c++0x -c date.cpp -o date.o
kattistime:
	c++ -std=c++0x -c kattistime.cpp -o kattistime.o
test: julian gregorian european date kattistime
	c++ -std=c++0x -o test.o datetest.cpp julian.o gregorian.o date.o european.o kattistime.o
kattistest: julian gregorian european date kattistime
		c++ -std=c++0x -o kattistest.o cprog09lab22c.cpp julian.o gregorian.o date.o european.o kattistime.o
		cat lab22c.in | ./kattistest.o > testut.txt
		diff -y lab22c.out testut.txt | grep '|' | more
greptest: julian gregorian european date kattistime
		c++ -std=c++0x -o kattistest.o cprog09lab22c.cpp julian.o gregorian.o date.o european.o kattistime.o
		cat lab22c.in | ./kattistest.o > testut.txt
		diff -y lab22c.out testut.txt
calendarlol: julian gregorian european date kattistime
	c++ -std=c++0x -o calendar.o calendar.cpp julian.o gregorian.o date.o european.o kattistime.o
calendar: 
	c++ -std=c++0x -c calendar.cpp -o calendar.o
calendartest: julian gregorian european date calendar kattistime
		c++ -std=c++0x -o calendartest.o cprog09lab23.cpp julian.o gregorian.o date.o european.o kattistime.o calendar.o
		cat lab23.in | ./calendartest.o > testut
		diff -y lab23 testut | grep '>' | more