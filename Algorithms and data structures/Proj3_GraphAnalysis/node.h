#pragma once
class NODE
{
    NODE* next;
    NODE* prev;
    int index;
public:
    void setPrev(NODE* pre);
    void setNext(NODE* nex);
    void setIndex(int ind);

    NODE* getPrev() const;
    NODE* getNext() const;

    int getIndex() const;
    void outData() const;

    NODE(NODE* pre, NODE* nex, int ind);
    ~NODE();
};


