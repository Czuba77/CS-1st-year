#pragma once
#include "NODE.h"
class LIST
{
    LIST* staque; //stack w inpucie queue w solve
    LIST* stack_mval;
	NODE* first;
    NODE* last;
    short dot_counter=0;
public:
    void setFirst(NODE* first);
    void setLast(NODE* last);

    LIST* getStack() const;
    NODE* getFirst() const;
    NODE* getLast() const;
    void outLIST() const;
    void outResult();

    LIST();
    LIST(bool cond);

    void pullgreaterprio(short prio);
    void input_logic(char tmp);
    void input();

    void createSolvingQueue();
    void reAsignNodeToQue();
    void SolveQueue();
    void handleErr();
    void delList(LIST* l);

    void addfirst(int number);
    void addfirst(char oper, short prio);
    void addfirst(char oper, short prio, short m_value);

    void push(int numb);
    void push(char oper, short prio);
    void push(char oper, short prio, short m_value);

    void put(int number);
    void put(char oper, short prio);
    void put(char oper, short prio, short m_value);

    void reAsigningThisPoint();
    char pop();
    char get(bool cond);
    int get();

};

