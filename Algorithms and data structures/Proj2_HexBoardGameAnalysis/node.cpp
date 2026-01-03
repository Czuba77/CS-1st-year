#include "NODE.h"
#include <iostream>
#define oX 0
#define oY 1

void NODE::setPrev(NODE*prev){
	this->prev = prev;
};
void NODE::setNext(NODE* next) {
	this->next = next;
};

void NODE::setOper(char oper) {
	this->character = oper;
};

NODE* NODE::getPrev() const {
	return this->prev;
}
NODE* NODE::getNext() const {
	return this->next;
}
char NODE::getCharacter() const {
	return this->character;
}
void NODE::getXY(int xy[2]) const {
	xy[oX] = this->XY[oX];
	xy[oY] = this->XY[oY];
}

void NODE::outData() const{
		printf("%c ", this->character);
}

NODE::NODE(NODE* pre, NODE* next, char oper)
	:prev(pre), next(next), character(oper) {
}

NODE::NODE(NODE* pre, NODE* next, int xy[2]) 
	:prev(pre), next(next){
	this->XY[oX] = xy[oX];
	this->XY[oY] = xy[oY];
}

