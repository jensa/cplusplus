%.out:	%.cpp
	g++ -g -std=c++0x -Wall $*.cpp -o $*.out

test:
	cxxtestgen --error-printer -o 1.2b.cpp test_must_follow_a.cpp
	g++ -o test_1.2b.out -I ../../cpp/cxxtest/ 1.2b.cpp must_follow_a.o

vec_test:
	g++ -g -std=c++0x -Wall -o tester.out vector.cpp test_vec.cpp