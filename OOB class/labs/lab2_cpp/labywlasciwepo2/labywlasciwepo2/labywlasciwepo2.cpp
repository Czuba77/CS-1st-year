#include <iostream>
#include <string>
#include "Book.h"
#include "Library.h"
using namespace std;

int main()
{
    string a = "Joker2115", t = "JokerStory";
    Book e;
    cout << "e: " << e << endl;
    Book b1 = { a, t };
    cout << "b1: " << b1 << endl;
    Book b2 = { "TrapDani","NeptunEP" };
    cout << "b2: " << b2 << endl;
    Book b3 = b1;
    cout << "b3: " << b3 << " b1: " << b1 << endl;
    e = std::move(b2);
    cout << "e: " << e << " b2:" << b2 << endl;
    e.setAuthor("Baron");
    cout << "e: " << e << endl;
    e.setTitle("OkupEP");
    cout << "e: " << e << endl << endl;

    Library lib;
    cout << "lib: " << lib << endl;
    //3-5 książek 
    Library l1 = { {"Szekspir", "Makbet"}, {"Dostojewski", "Zbrodnia i Kara"}, {"Konwicki", "Mala Apokalipsa"} };
    cout << "l1: " << l1 << endl << endl;
    Library l2(2);;
    cout << "l2: " << l2 << endl << endl;
    l2[0] = { "Mickiewicz", "Pan Tadeusz" };
    l2[1] = { "Slowacki", "Balladyna" };
    cout << "l2: " << l2 << endl << endl;
    lib = std::move(l2);
    cout << "lib: " << lib << " l2: " << l2 << endl << endl;
    l1[0] = std::move(lib[1]);
    cout << "l1: " << l1 << " lib: " << lib << endl << endl;

    return 0;
}
