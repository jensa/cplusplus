%.out:	%.cpp
	g++ -g -std=c++0x -Wall $*.cpp -o $*.out

vector:
	g++ -c -std=c++0x -o vector.o vector.cpp

test:
	cxxtestgen --error-printer -o 1.2b.cpp test_must_follow_a.cpp
	g++ -o test_1.2b.out -I ../../cpp/cxxtest/ 1.2b.cpp must_follow_a.o

test_vec:
	g++ -g -std=c++0x -Wall -o tester.out vector.cpp test_vec.cpp

kattis14:
	g++ -g -std=c++0x -Wall -o kattis14.out vector.cpp cprog09lab14.cpp

cxx_test:
	make vector
	../../cpp/cxxtest/cxxtestgen.py --error-printer -o generated_vector_test_cxx.cpp test_cxx.cpp
	g++ -std=c++0x -o vector_test_cxx.out -I ../../cpp/cxxtest/ generated_vector_test_cxx.cpp vector.o
	./vector_test_cxx.out