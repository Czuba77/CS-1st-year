#pragma once
#include "NODE.h"
class LIST
{
	NODE* first;
    NODE* last;
public:
    void setFirst(NODE* first);
    void setLast(NODE* last);

    NODE* getFirst() const;
    NODE* getLast() const;

    LIST();
    ~LIST();

    void outLIST() const;
    void addfirst(char character);
    void addfirst(int xy[2]);
    void delList(LIST* l);
    void push(char character);
    void put(char character);
    void push(int xy[2]);
    void put(int xy[2]);
    char pop();
    void pop(int xy[2]);
    char get();
};

