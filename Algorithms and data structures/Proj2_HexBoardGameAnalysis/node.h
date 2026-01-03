#pragma once
class NODE
{
    NODE* next;
    NODE* prev;
    char character;
    int XY[2];
public:
    void setPrev(NODE* prev);
    void setNext(NODE* next);
    void setOper(char oper);

    NODE* getPrev() const;
    NODE* getNext() const;
    char getCharacter() const;
    void getXY(int xy[2]) const;
    void outData() const;

    NODE(NODE* pre, NODE* next, char oper);
    NODE(NODE* pre, NODE* next, int xy[2]);
};

