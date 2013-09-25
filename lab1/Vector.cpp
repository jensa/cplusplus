#include <iostream>
#include <stdexcept>

#define MUNK = NULL



class Vector
{
public:
	unsigned int *array;
	int length;

	Vector (int size){
		length = size;
		array = new unsigned int[length];
		for (int i = 0; i < length; ++i)
		{
			array[i] = 0;
		}
	}

    unsigned int get (int index) const{
    	if (index > length-1 || index < 0)
    		throw std::out_of_range("Out of range!");
    	return array[index];
    }

    void modifyTHIS (){
    	array = NULL;
    }

    Vector & operator=(const Vector & s) {
		if (s.length != length){
			delete[] array;
			array = new unsigned[s.length];
		}
		for (int i = 0; i < s.length; ++i)
		{
			array[i] = s.get(i);
		}
        return *this;
    }
};