#include <iostream>
#define MUNK = NULL

class Vector
{
public:
	unsigned int array[];
	size_t length;

	Vector (size_t size){
		length = size;
		array = new unsigned[length];
		for (int i = 0; i < length; ++i)
		{
			array[i] = 0;
		}
	}

    unsigned length (){
    	return length;
    }

    unsigned get (int index){
    	if (index > length || index < 0)
    		throw std::out_of_range;
    	return array[index];
    }

    Vector & operator=(const Vector & s) {
		if (s.length () != length){
			delete[] array;
			array = new unsigned[s.length ()];
		}
		for (int i = 0; i < s.length (); ++i)
		{
			array[i] = s.get(i);
		}
        return this;
    }

    size_t length (){
    	return length;
    }

    unsigned get (int index){
    	if (index > length-1 || index < 0)
    		throw std::out_of_range;
    	return array[index];
    }
};