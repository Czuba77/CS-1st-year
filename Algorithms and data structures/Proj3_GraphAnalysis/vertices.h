#pragma once
#include "LIST.h"
#define SS 0
#define DWUDZIELNOSC 1
#define STRONA 2
#define KOLO_ZACH 3

#define LEWA false
#define PRAWA true
class VERTICES : public LIST
{
    int colour;
    int number_of_neighbours;
    bool isChecked[4];
public:
    void setNeigh(int neigh);

    void setColour(int colour);
    void setIsChecked(bool isChecked, int index);

    bool getIsChecked(int index) const;
    int getColour() const;
    int getNumOfNeigh() const;

    VERTICES();

    void addfirst(int index);
    void push(int index);
    void put(int index);
    int pop();
    int get();
};

