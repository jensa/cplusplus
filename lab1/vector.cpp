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

	//Copy contructor
	Vector (const Vector & vec){
		fitArray (vec);
		for (int i = 0; i < vec.length; ++i)
		{
			array[i] = vec.get(i);
		}
	}

    unsigned int get (int index) const{
    	if (index > length-1 || index < 0)
    		throw std::out_of_range("Out of range!");
    	return array[index];
    }

    Vector & operator=(const Vector & vec) {
		fitArray (vec);
		for (int i = 0; i < vec.length; ++i)
		{
			array[i] = vec.get(i);
		}
        return *this;
    }

    unsigned int &operator[](const int & index){
    	return array[index];
    }

private:
	void fitArray (const Vector & vec){
		if (vec.length != length){
			delete[] array;
			array = new unsigned[vec.length];
		}
	}
};

int main (){
	
}