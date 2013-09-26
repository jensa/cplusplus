#ifndef VECTOR_H
#define VECTOR_H

#include <cstdlib>
#include <stdexcept>
#include <initializer_list>

class Vector
{
	public:
		size_t length;
		unsigned int *array;

		Vector();
		explicit Vector (size_t size);
		Vector (const Vector & vec);
		Vector (Vector&& other);
		~Vector ();

		size_t size() const;
		void print();
		
		unsigned int & operator[](unsigned int index);
		const unsigned int & operator[](unsigned int index) const;

		Vector & operator=(const Vector & s);
		Vector & operator=(Vector && other);
		Vector & operator=(const std::initializer_list<int>& il);

	private:
		bool arrayCreated;
		void fitArray (const Vector & vec);
};

#endif