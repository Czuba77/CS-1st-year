#pragma once
#include "NODE.h"
#define SS 0
#define DWUDZIELNOSC 1
#define STRONA 2

#define LEWA false
#define PRAWA true

class LIST
{
protected:
    NODE* iterator;
	NODE* first;
    NODE* last;
    int index;
public:
    void setFirst(NODE* first);
    void setLast(NODE* last);
    void setIndex(int ind);
    void incrementIndex();
    int getIndex() const;
    NODE* getFirst() const;
    NODE* getLast() const;

    LIST();
    ~LIST();
    void delList(LIST* l);

    void setIteratorToLast();
    void resetIteration();
    void iterate();
    NODE* getItVer() const;

    void outLIST() const;

    void addfirst(int ind);
    void push(int ind);
    void put(int ind);
    int pop();
    int get();
};
