#include <iostream>
#include <stdexcept>
#include "vector.h"

#define MUNK = NULL

Vector::Vector (int size){
	length = size;
	array = new unsigned int[length];
	for (int i = 0; i < length; ++i)
	{
		array[i] = 0;
	}
}

//Copy contructor
Vector::Vector (const Vector & vec){
	fitArray (vec);
	length = vec.getLength();
	for (int i = 0; i < vec.getLength(); ++i)
	{
		int boeg = vec.get(i);
		array[i]  = boeg;
	}
}

int Vector::getLength() const{
	return length;
}

unsigned int Vector::get (int index) const{
	if (index > length-1 || index < 0)
		throw std::out_of_range("Out of range!");
	return array[index];
}

Vector & Vector::operator=(const Vector & vec) {
	fitArray (vec);
	for (int i = 0; i < vec.getLength()-1; ++i)
	{
		array[i] = vec.get(i); //LANGAR SEGFAULT :()
	}
    return *this;
}

unsigned int & Vector::operator[](const int & index) const{
	return array[index];
}

void Vector::fitArray (const Vector & vec){
	if (vec.getLength() != length){
		//delete[] array;
		array = new unsigned int[vec.getLength()];
	}
}