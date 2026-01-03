#include "NODE.h"
#include <iostream>
#define oX 0
#define oY 1

void NODE::setPrev(NODE*pre){
	this->prev = pre;
};
void NODE::setNext(NODE* nex) {
	this->next = nex;
};

void NODE::setIndex(int ind) {
	this->index = ind;
};

NODE* NODE::getPrev() const {
	return this->prev;
}
NODE* NODE::getNext() const {
	return this->next;
}

int NODE::getIndex() const {
	return this->index;
}

void NODE::outData() const{
		printf("%d ", this->index);
}


NODE::NODE(NODE* pre, NODE* nex, int ind) 
	:prev(pre), next(nex){
	this->index = ind;
}

NODE::~NODE(){
	this->prev = nullptr;
	this->next = nullptr;
}

