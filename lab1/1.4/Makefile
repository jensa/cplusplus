vector:
	g++ -c -std=c++0x -o vector.o vector.cpp

test_vec:
	g++ -g -std=c++0x -Wall -o tester.out vector.cpp test_vec.cpp

cxx_test:
	make vector
	../../../cpp/cxxtest/cxxtestgen.py --error-printer -o generated_vector_test_cxx.cpp test_cxx.cpp
	g++ -std=c++0x -o vector_test_cxx.out -I ../../../cpp/cxxtest/ generated_vector_test_cxx.cpp vector.o
	./vector_test_cxx.out