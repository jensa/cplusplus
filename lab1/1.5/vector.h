#ifndef VECTOR_H
#define VECTOR_H

#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include <initializer_list>

template <class T>
class Vector
{
	public:
		size_t length;
		T *array;

		// Constructors

		Vector() {
			length = (size_t) 0;
			array = new T[0];
		}

		explicit Vector (size_t size) {
			length = size;
			array = new T[length]();
		}

		Vector (const Vector & vec) {
			length = vec.size();
		    array = new T[length];
		    for (int i = 0; i < (int) length; ++i) {
		        array[i] = vec[i];
		    }
		}

		Vector (Vector&& other) {
			array = other.array;
			length = other.length;

			other.array = NULL;
			other.length = 0;
		}

		// Destructor

		~Vector () {
			delete[] array;
		}

		// Methods

		void push_back(T element) {
			// TODO
		}

		void insert(size_t i, T element) {
			// TODO
		}

		void erase(size_t i) {
			// TODO
		}

		void clear() {
			// TODO
		}

		size_t size() const {
			return length;
		}

		void sort(bool ascending) {
			// TODO
		}

		void unique_sort(bool ascending) {
			// TODO
		}

		bool exists(const T & element) {
			// TODO
			return false;
		}

		void print() {
			std::cout << "[";
			for (int i = 0; i < (int) length; i++){
				std::cout << array[i];
				if (i != (int) length-1)
					std::cout << ",";
			}
			std::cout << "]" << "\n";
		}

		// [] operators
		
		T & operator[](unsigned int index) {
			if (index >= length || index < 0)
			throw std::out_of_range("Out of range!");
			return array[index];
		}

		const T & operator[](unsigned int index) const {
			if (index >= length || index < 0)
			throw std::out_of_range("Out of range!");
			return array[index];
		}

		// = operators

		Vector & operator=(const Vector & vec) {
			if (this != &vec) {
				delete[] array;
				array = new T[vec.size()];
				length = vec.size();
				for (int i = 0; i < (int) vec.size(); ++i) {
					array[i] = vec[i];
				}
			}
			return *this;	
		}

		Vector & operator=(Vector && other) {
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

		Vector & operator=(const std::initializer_list<T>& il) {
			delete[] array;
			array = new T[il.size()];
			length = il.size();

			typename std::initializer_list<T>::iterator it;
			int i = 0;

			for (it = il.begin(); it != il.end(); it++, i++) {
				array[i] = *it;
			}

			return *this;
		}
};

#endif