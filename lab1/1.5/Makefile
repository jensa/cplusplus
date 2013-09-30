vector:
	g++ -c -std=c++0x -o vector.o vector.cpp

test_template:
	g++ -g -std=c++0x -Wall -o tester.out test_template_vec.cpp

cxx_test:
	../../../cpp/cxxtest/cxxtestgen.py --error-printer -o generated_vector_test_cxx.cpp test_cxx.cpp
	g++ -std=c++0x -o vector_test_cxx.out -I ../../../cpp/cxxtest/ generated_vector_test_cxx.cpp
	./vector_test_cxx.out