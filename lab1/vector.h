#ifndef VECTOR_H
#define VECTOR_H

#include <cstdlib>
#include <stdexcept>
#include <initializer_list>

class Vector
{
	public:
		Vector();
		explicit Vector (size_t size);
		Vector (const Vector & vec);
		~Vector ();

		size_t size() const;
		void print();
		
		unsigned int & operator[](unsigned int index);
		const unsigned int & operator[](unsigned int index) const;

		Vector & operator=(const Vector & s);
		Vector & operator=(const std::initializer_list<int>& il);

	private:
		int length;
		unsigned int *array;
		bool arrayCreated;
		void fitArray (const Vector & vec);
};

#endif