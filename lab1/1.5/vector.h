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

		Vector();

		explicit Vector (size_t size);

		Vector (const Vector & vec);

		Vector (Vector&& other);

		Vector (size_t size, T defaultval);

		// Destructor

		~Vector ();

		// Functions

		void push_back(T element);

		void insert(size_t idx, T element);

		void erase(size_t idx);

		void clear();

		size_t size() const;

		static bool comp (const T & a, const T & b);

		void sort(bool ascending);

		void unique_sort(bool ascending);

		bool exists(const T & element);

		/**
		inc_alloc_length

		Dubblar antalet allokerade platser
		*/

		void inc_alloc_length ();

		void allocMoreIfNecessary();

		void print();

		// [] operators
		
		T & operator[](unsigned int index);

		const T & operator[](unsigned int index) const;

		// = operators

		Vector & operator=(const Vector & vec);

		Vector & operator=(Vector && other);

		Vector & operator=(const std::initializer_list<T>& il);
};
#include "vector.cpp"
#endif