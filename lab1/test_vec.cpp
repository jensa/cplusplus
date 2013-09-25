#include <iostream>
#include <stdexcept>
#include "vector.h"     // inkludera din headerfil här


int main()
{
    std::cout << "Constructors" << "\n";
    // Några saker som ska fungera:
    Vector a(7);           // initiering med 7 element
    Vector b(a);           // kopieringskonstruktor 
    Vector c = a;          // kopieringskonstruktor

    std::cout << "Tilldelning" << "\n";
    a = b;                 // tilldelning genom kopiering
    a[5] = 7;              // tilldelning till element

    std::cout << a[4] << "\n";

    std::cout << "DEL 3" << "\n";
    const Vector e(10);    // konstant objekt med 10 element
    int i = e[5];          // const int oper[](int) const körs
    i = a[0];              // vektorn är nollindexerad
    i = a[5];              // int oper[](int) körs
    
    std::cout << "DEL 4" << "\n";
    a[5]++;                // öka värdet till 8

    std::cout << "DEL 5" << "\n";
    try {
        i = e[10];             // försöker hämta element som ligger utanför e
    } catch (std::out_of_range e) {
        std::cout << e.what() << std::endl;
    }

    Vector x(10);
    x[0] = 1;
    x[1] = 2;
    x[2] = 3;
    x[3] = 4;
    x[4] = 5;
    x[5] = 6;
    x[6] = 7;
    x[7] = 8;
    x[8] = 9;
    x[9] = 10;

    Vector y(5);

    y = x;
    x.print();
    y.print();

#if 0
    // Diverse saker att testa
    e[5] = 3;              // fel: (kompilerar ej) tilldelning till const
    b = b;                 // hmm: se till att inte minnet som skall behållas frigörs
#endif

    return 0;
}
