#include <iostream>
#include <ctype.h>
#include "NODE.h"
#include "LIST.h"



int main()
{
    LIST* l1=new LIST();
    NODE* n = nullptr;
    short dot_amount, i = 0;
    std::cin >> dot_amount;
    while (i<dot_amount) {
        l1->input();
        l1->outLIST();
        while (l1->getFirst() != nullptr) {
            l1->createSolvingQueue();
            l1->getStack()->outLIST();
            l1->SolveQueue();
        }
        l1->outResult();
        i++;
    }
    return 0;
}
