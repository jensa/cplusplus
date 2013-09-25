#include <iostream>
#include <stdexcept>
#include "vector.h"     // inkludera din headerfil h�r


int main()
{
    std::cout << "Constructors" << "\n";
    // N�gra saker som ska fungera:
    Vector a(7);           // initiering med 7 element
    Vector b(a);           // kopieringskonstruktor 
    Vector c = a;          // kopieringskonstruktor 

    std::cout << "Tilldelning" << "\n";
    a = b;                 // tilldelning genom kopiering
    a[5] = 7;              // tilldelning till element

    std::cout << "DEL 3" << "\n";
    const Vector e(10);    // konstant objekt med 10 element
    int i = e[5];          // const int oper[](int) const k�rs
    i = a[0];              // vektorn �r nollindexerad
    i = a[5];              // int oper[](int) k�rs
    
    std::cout << "DEL 4" << "\n";
    a[5]++;                // �ka v�rdet till 8

    std::cout << "DEL 5" << "\n";
    try {
        i = e[10];             // f�rs�ker h�mta element som ligger utanf�r e
    } catch (std::out_of_range e) {
        std::cout << e.what() << std::endl;
    }
    
#if 0
    // Diverse saker att testa
    e[5] = 3;              // fel: (kompilerar ej) tilldelning till const
    b = b;                 // hmm: se till att inte minnet som skall beh�llas frig�rs
#endif

    return 0;
}
