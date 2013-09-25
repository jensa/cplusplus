#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Data {
    int x, y, z;
};  

Data ** foo(Data ** v, int x) {
	cout << "v in foo: " << &v << "\n";
    for (int i = 0; i < x; i++)
        // if (v[i] != 0)
        {
			v[i] = new Data;
        	//	delete v[i];
        }
    return v;
}

int main () {
    const int size = 5;
    Data ** v = new Data * [size];
    cout << "v in main: " << &v << "\n";
    Data ** p = foo(v, size);
    cout << "p in main: " << &p << "\n";
    delete[] p;
}
