#include <iostream>

using namespace std;

class Vector
{
public:
	unsigned[] array;
	size_t length;

	Vector (size_t size){
		length = size;
		array = new unsigned[length];
		for (int i = 0; i < length; ++i)
		{
			array[i] = 0;
		}
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

    unsigned length (){
    	return length;
    }

    unsigned get (int index){
    	if (index > length || index < 0)
    		throw std::out_of_range;
    	return array[index];
    }

}