%.out:	%.cpp
	g++ -g -std=c++0x -Wall $*.cpp -o $*.out

test:
	../../cpp/cxxtest/cxxtestgen.py --error-printer -o 1.2b.cpp test_must_follow_a.cpp
	g++ -o test_1.2b.out -I ../../cpp/cxxtest/ 1.2b.cpp must_follow_a.o