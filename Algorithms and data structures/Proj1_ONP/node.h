#pragma once
class NODE
{
    NODE* next;
    NODE* prev;
    short prio, m_val;
    int number;
    char oper;
public:
    void setPrev(NODE* prev);
    void setNext(NODE* next);
    void setPrio(short prio);
    void setNumber(int number);
    void setM_val(short prio);
    void setOper(char oper);

    NODE* getPrev() const;
    NODE* getNext() const;
    short getPrio() const;
    short getM_value() const;
    int getNumber() const;
    char getOper() const;

    void incrementNumber();


    char getData();
    void outData();

    NODE(NODE* pre, NODE* next, char oper, short prio);
    NODE(NODE* pre, NODE* next, char oper, short prio, short m_val);
    NODE(NODE* pre, NODE* next, short prio, int numb);

    NODE(NODE* pre, NODE* next);
    NODE(NODE* pre, NODE* next, char tmp);

};

