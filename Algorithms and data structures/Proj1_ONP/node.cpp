#include "NODE.h"
#include <iostream>
#define NO_CHAR 'p'
#define NO_NUMB -404

void NODE::incrementNumber() {
	this->number = number+1;
};

void NODE::setPrev(NODE*prev){
	this->prev = prev;
};
void NODE::setNext(NODE* next) {
	this->next = next;
};
void NODE::setPrio(short prio) {
	this->prio = prio;
};
void NODE::setM_val(short m_val) {
	this->m_val = m_val;
};
void NODE::setNumber(int number) {
	this->number = number;
};
void NODE::setOper(char oper) {
	this->oper = oper;
};

NODE* NODE::getPrev() const {
	return this->prev;
}
NODE* NODE::getNext() const {
	return this->next;
}
short NODE::getPrio() const {
	return this->prio;
}
int NODE::getNumber() const {
	return this->number;
}
char NODE::getOper() const {
	return this->oper;
}
short NODE::getM_value() const {
	return this->m_val;
}

char NODE::getData() {
	if (this->getPrio())
		return this->oper;
	else
		return this->number;
};

void NODE::outData() {
	if (this->getPrio())
		switch (this->oper)
		{
		case 'F':
			printf("IF ");
			break;
		case 'A':
			printf("MAX%d ",this->m_val);
			break;
		case 'I':
			printf("MIN%d ", this->m_val);
			break;
		default:
			printf("%c ", this->oper);
			break;
		}
	else
		printf("%d ", this->number);
}


NODE::NODE(NODE* pre, NODE* next, short prio, int numb)
:prev(pre),next(next),prio(prio),number(numb){
}

NODE::NODE(NODE* pre, NODE* next, char oper, short prio)
	:prev(pre), next(next),prio(prio), oper(oper) {
}

NODE::NODE(NODE* pre, NODE* next, char oper, short prio, short m_val) 
	:prev(pre), next(next), prio(prio), oper(oper), m_val(m_val) {
}

