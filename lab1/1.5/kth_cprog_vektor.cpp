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
		explicit Vector (size_t);
		Vector (const Vector &);
		Vector (const std::initializer_list<T>);
		Vector (Vector&&);
		Vector (size_t, T);

		// Destructor

		~Vector ();

		// 1.5 functions implementations

		void push_back(T);
		void insert(size_t, T);
		void erase(size_t);
		void clear();
		size_t size() const;
		static bool comp (const T &, const T &);
		void sort(bool);
		void unique_sort(bool);
		bool exists(const T &);

		// Methods for allocating more space for the vector

		void allocMoreIfNecessary();
		void increase_alloc_length ();
		// Print method for debugging
		void print();

		// [] operators
		
		T & operator[](unsigned int);
		const T & operator[](unsigned int) const;

		// = operators

		Vector & operator=(const Vector &);
		Vector & operator=(Vector &&);
		Vector & operator=(const std::initializer_list<T>&);
};

#endif

/**
Constructors
*/

// Defaultkonstruktor
template <class T>
Vector<T>::Vector() {
	length = (size_t) 0;
	alloc_length = 2;
	array = new T[alloc_length];
}

// Konstruktor som skapar en Vector av en given storlek
template <class T>
Vector<T>::Vector (size_t size) {
	length = size;
	if (size >= 2)
		alloc_length = size;
	else
		alloc_length = 2;
	array = new T[alloc_length]();
}

// Kopieringskonstruktor
template <class T>
Vector<T>::Vector (const Vector & vec) {
	length = vec.size();
	alloc_length = vec.size();
    array = new T[length];
    for (int i = 0; i < (int) length; ++i) {
        array[i] = vec[i];
    }
}

// Konstruktor för initializer_list<T>
template <class T>
Vector<T>::Vector (const std::initializer_list<T> il) {
	array = new T[il.size()];
	length = il.size();
	alloc_length = il.size();
	typename std::initializer_list<T>::iterator it;
	int i = 0;
	for (it = il.begin(); it != il.end(); it++, i++) {
		array[i] = *it;
	}
}

// Movekonstruktor
template <class T>
Vector<T>::Vector (Vector&& other) {
	array = other.array;
	length = other.length;
	alloc_length = other.alloc_length;
	other.array = NULL;
	other.length = 0;
	other.alloc_length = 0;
}

// Konstruktor som skapar en Vector av en given storlek och 
// initierar alla element till ett givet standardvärde
template <class T>
Vector<T>::Vector (size_t size, T defaultval) {
	length = size;
	alloc_length = size;
	array = new T[size];
	for (int i = 0; i < (int) size; i++) {
		array[i] = defaultval;
	}
}

// Destruktor
template <class T>
Vector<T>::~Vector () 
{	delete[] array;
}

// 1.5 functions implementations

/**
push_back(T)

Lägger till ett element sist i vektorn. Det ska för det mesta
ske i konstant tid.
*/
template <class T>
void Vector<T>::push_back(T element) {
	allocMoreIfNecessary();
	array[length] = element;
	length++;
}

/**
insert(size_t, T)

Lägger till ett element före plats i. Om i är lika
med antal element i vektorn fungerar metoden som push_back.
*/
template <class T>
void Vector<T>::insert(size_t idx, T element) {
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

/**
erase(size_t)

Tar bort ett element på plats i.
*/
template <class T>
void Vector<T>::erase(size_t idx) {
	if ((int) idx >= length || (int) idx < 0)
		throw std::out_of_range("Out of range!");
	for (int i = (int) idx; i < (int) length-1; i++) {
		array[i] = array[i+1];
	}
	length--;
}

/**
clear()

Tar bort alla element.
*/
template <class T>
void Vector<T>::clear() {
	length = 0;
}

/**
size()

Ger antal element i vektorn.
*/
template <class T>
size_t Vector<T>::size() const{
	return length;
}

/**
Comparator a > b

Implementerad som b < a eftersom alla klasser som används implementerar operator<
men inte nödvändigtvis operator>.
*/
template <class T>
bool Vector<T>::comp (const T & a, const T & b) {
	return b < a;
}

/**
sort(bool) 

Sorterar vektorn i angiven riktning på
enklast möjliga sätt. Använd std::sort (datatyper som ska jämföras måste
deﬁniera operator<.)
*/
template <class T>
void Vector<T>::sort(bool ascending) {
	if (ascending) {
		std::sort(array, array+length);
	} else {
		std::sort(array, array+length, comp);
	}
}

/**
unique_sort(bool)

Sorterar samt tar bort dubletter
i vektorn. Använd std::unique. OBS! se till att vektorns storlek ändras om
element tagits bort.
*/
template <class T>
void Vector<T>::unique_sort(bool ascending) {
	sort(ascending);
	T* ptr = std::unique(array, array+length);
	length = ptr-array;
}

template <class T>
bool Vector<T>::exists(const T & element) {
	T* res = std::find(array, array+length, element);
	return (res != array+length);
}

/**
increase_alloc_length(T)

Dubblar antalet platser i den interna arrayen.
*/
template <class T>
void Vector<T>::increase_alloc_length () {
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

/**
allocMoreIfNecessary()

Kollar om det finns plats för fler element i den interna arrayen och
allokerar fler platser om det behövs.
*/
template <class T>
void Vector<T>::allocMoreIfNecessary() {
	if ((int) (alloc_length - length) < 0) {
		std::cout << "Nåt är jävligt fel \n";
	} else if ((int) (alloc_length - length) == 0) {
		increase_alloc_length();
	}
}

/**
print()

Skriver ut vektorn (används för debugging).
*/
template <class T>
void Vector<T>::print() {
	std::cout << "[";
	for (int i = 0; i < (int) length; i++){
		std::cout << array[i];
		if (i != (int) length-1)
			std::cout << ",";
	}
	std::cout << "]" << "\n";
}

/**
operator[]
*/
// Standard operator[]
template <class T>
T & Vector<T>::operator[](unsigned int index) {
	if (index >= length || index < 0)
	throw std::out_of_range("Out of range!");
	return array[index];
}

// En konstant medlemsfunktion för read only-åtkomster
template <class T>
const T & Vector<T>::operator[](unsigned int index) const {
	if (index >= length || index < 0)
	throw std::out_of_range("Out of range!");
	return array[index];
}

/**
operator=
*/

// Standard tilldelningsoperator
template <class T>
Vector<T> & Vector<T>::operator=(const Vector & vec) {
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

// Move-operator
template <class T>
Vector<T> & Vector<T>::operator=(Vector && other) {
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

// Tilldelningsoperator för initializer_list<T>
template <class T>
Vector<T> & Vector<T>::operator=(const std::initializer_list<T>& il) {
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