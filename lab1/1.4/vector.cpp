#include <iostream>
#include "vector.h"

Vector::Vector(){
	length = (size_t) 0;
	array = new unsigned int[0];
}

Vector::Vector (const size_t size){
	length = size;
	array = new unsigned int[length];
	for (int i = 0; i < (int) length; ++i)
	{
		array[i] = 0;
	}
}

//Copy contructor
Vector::Vector (const Vector & vec){
	length = vec.size();
    array = new unsigned int[length];
    for (int i = 0; i < (int) length; ++i) {
        array[i] = vec[i];
    }
}

//Move constructor
Vector::Vector (Vector&& other){
	array = other.array;
	length = other.length;

	other.array = NULL;
	other.length = 0;
} 

//Destructor
Vector::~Vector () {
	delete array;
}

size_t Vector::size() const{
	return length;
}

Vector & Vector::operator=(const Vector & vec) {
	if (this != &vec) 
	{
		delete[] array;
		array = new unsigned int[vec.size()];
		length = vec.size();
		for (int i = 0; i < (int) vec.size(); ++i)
		{
			array[i] = vec[i];
		}
	}
	return *this;	
}

Vector & Vector::operator=(Vector && other)
{
	if (this != &other)
	{
		delete[] array;
		array = other.array;
		length = other.length;

		other.array = NULL;
		other.length = 0;
	}
	return *this;
}

Vector & Vector::operator=(const std::initializer_list<int>& il){
	
	delete[] array;
	array = new unsigned int[il.size()];
	length = il.size();

	std::initializer_list<int>::iterator it;
	int i = 0;

	for (it = il.begin(); it != il.end(); it++, i++) {
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

void Vector::print () {
	std::cout << "[";
	for (int i = 0; i < (int) length; i++){
		std::cout << array[i];
		if (i != (int) length-1)
			std::cout << ",";
	}
	std::cout << "]" << "\n";
}