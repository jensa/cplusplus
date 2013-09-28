#ifndef VECTOR_H
#define VECTOR_H

#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <initializer_list>

template <class T>
class Vector
{
	public:
		size_t length;
		size_t alloc_length;
		T *array;

		// Constructors

		Vector() {
			length = (size_t) 0;
			alloc_length = 2;
			array = new T[2];
		}

		explicit Vector (size_t size) {
			length = size;
			if (size >= 2)
				alloc_length = size;
			else
				alloc_length = 2;
			array = new T[alloc_length]();
		}

		Vector (const Vector & vec) {
			length = vec.size();
			alloc_length = vec.size();
		    array = new T[length];
		    for (int i = 0; i < (int) length; ++i) {
		        array[i] = vec[i];
		    }
		}

		Vector (Vector&& other) {
			array = other.array;
			length = other.length;
			alloc_length = other.alloc_length;

			other.array = NULL;
			other.length = 0;
			other.alloc_length = 0;
		}

		Vector (size_t size, T defaultval) {
			length = size;
			alloc_length = size;
			array = new T[size];
			for (int i = 0; i < (int) size; i++) {
				array[i] = defaultval;
			}
		}

		// Destructor

		~Vector () {
			delete[] array;
		}

		// Methods

		void push_back(T element) {
			allocMoreIfNecessary();
			array[length] = element;
			length++;
		}

		void insert(size_t idx, T element) {
			if ((int) idx > length || (int) idx < 0) {
				throw std::out_of_range("Out of range!");
			} else if ((int) idx == length) {
				push_back(element);
				return;
			}

			allocMoreIfNecessary();

			for (int i = length-1; i >= (int) idx ; i--) {
				array[i+1] = array[i];
			}

			array[idx] = element;
			length++;
		}

		void erase(size_t idx) {
			if ((int) idx >= length || (int) idx < 0)
				throw std::out_of_range("Out of range!");

			for (int i = (int) idx; i < (int) length; i++) {
				array[i] = array[i+1];
			}
			length--;
		}

		void clear() {
			length = 0;
		}

		size_t size() const {
			return length;
		}

		static bool comp (const T & a, const T & b) {
			return b < a;
		}

		void sort(bool ascending) {
			if (ascending) {
				std::sort(array, array+length);
			} else {
				std::sort(array, array+length, comp);
			}
		}

		void unique_sort(bool ascending) {
			// TODO
		}

		bool exists(const T & element) {
			int* res = std::find(array, array+length, element);
			return (res != array+length);
		}

		/**
		inc_alloc_length

		Dubblar antalet allokerade platser
		*/

		void inc_alloc_length () {

			if ((alloc_length - length ) > 0 )
				std::cout << "Finns ju fan plats kvar. Nåt är knas. \n";

			if (length == 0)
				length = 1;

			T* tmp_array = new T[length*2];

			for (int i = 0; i < (int) length; i++) {
				tmp_array[i] = array[i];
			}

			delete[] array;
			array = tmp_array;
			alloc_length = 2*length;
		}

		void allocMoreIfNecessary() {
			if ((int) (alloc_length - length) < 0) {
				std::cout << "Nåt är jävligt fel \n";
			} else if ((int) (alloc_length - length) == 0) {
				inc_alloc_length();
			}
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
				alloc_length = vec.size();
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
					alloc_length = other.alloc_length;

					other.array = NULL;
					other.length = 0;
					other.alloc_length = 0;
				}
				return *this;
		}

		Vector & operator=(const std::initializer_list<T>& il) {
			delete[] array;
			array = new T[il.size()];
			length = il.size();
			alloc_length = il.size();

			typename std::initializer_list<T>::iterator it;
			int i = 0;

			for (it = il.begin(); it != il.end(); it++, i++) {
				array[i] = *it;
			}

			return *this;
		}
};

#endif