#include <iostream>
#include "vector.h"

Vector::Vector(){
	length = (size_t) 0;
	array = new unsigned int[0];
	arrayCreated = 1;
}

Vector::Vector (const size_t size){
	length = size;
	array = new unsigned int[length];
	arrayCreated = 1;
	for (int i = 0; i < length; ++i)
	{
		array[i] = 0;
	}
}

//Copy contructor
Vector::Vector (const Vector & vec){
	length = vec.size();
    array = new unsigned int[length];
    for (unsigned int i = 0; i < length; ++i) {
        array[i] = vec[i];
    }
}

Vector::~Vector () {
	delete array;
}

size_t Vector::size() const{
	return length;
}

Vector & Vector::operator=(const Vector & vec) {
	fitArray (vec);
	length = vec.size();
	for (int i = 0; i < vec.size(); ++i)
	{
		array[i] = vec[i];
	}
	return *this;	
}

Vector & Vector::operator=(const std::initializer_list<int>& il){
	Vector vec(il.size());
	fitArray(vec);
	length = vec.size();

	std::initializer_list<int>::iterator it;
	int i = 0;

	for (it = il.begin(); it != il.end(); it++, i++){
		std::cout << "Inserting " << *it << " at index " << i << "\n"; 
		array[i] = *it;
	}

	return *this;
}

unsigned int & Vector::operator[](unsigned int index){
	if (index >= length || index < 0)
		throw std::out_of_range("Out of range!");
	return array[index];
}

const unsigned int & Vector::operator[](unsigned int index) const {
	if (index >= length || index < 0)
		throw std::out_of_range("Out of range!");
	return array[index];
}

void Vector::fitArray (const Vector & vec){
	if (vec.size() != length){
		if (arrayCreated)
			delete[] array;
		array = new unsigned int[vec.size()];
	}
}

void Vector::print () {
	std::cout << "[";
	for (int i = 0; i < length; i++){
		std::cout << array[i];
		if (i != length-1)
			std::cout << ",";
	}
	std::cout << "]" << "\n";
}