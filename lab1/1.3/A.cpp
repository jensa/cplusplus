#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class A {
    
public:
    A() 
        {cout << "The default contructor" << "\n"; }
    A(const A & ref) 
        {cout << "The copy contructor" << "\n"; }
    ~A() 
        {cout << "The destructor" << "\n"; }
    A(char * s) 
        {cout << "Some other constructor " << s << "\n";}
    A & operator=(const A & s) 
        {cout << "The assignment operator" << "\n"; 
         return *this;}
};

void no_ref(A a) {cout << "a in no_ref: " << &a << "\n";}
void with_ref(const A & a) {cout << "a in with_ref: " << &a << "\n";}

int main()
{
    cout << 1 << "\n";
    A a("my name is a");
    cout << "a: " << &a << "\n";

    cout << 2 << "\n";
    A b = a;         // vad är skillnaden
    cout << "b: " << &b << "\n";

    cout << 3 << "\n";
    A c(a);          // mellan dessa
    cout << "c: " << &c << "\n";

    cout << 4 << "\n";
    A d;             // tre tekniker?
    cout << "d: " << &d << "\n";

    cout << 5 << "\n";
    d = a;
    cout << "d: " << &d << "\n";
    cout << "a: " << &a << "\n";

    cout << 6 << "\n";
    cout << "a: " << &a << "\n";
    no_ref(a);       // Bildas temporära objekt? Ja, och sedan kallas destruktorn.
    cout << 7 << "\n";
    cout << "a: " << &a << "\n";
    with_ref(a);     // Bildas temporära objekt? Nope.

    cout << 8 << "\n";
    A *aa = new A[5];

    cout << 9 << "\n";
    delete[] aa;       // Vad kommer att hända?
    return 0;
}
