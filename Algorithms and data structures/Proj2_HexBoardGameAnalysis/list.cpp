#include <iostream>
#include "LIST.h"
#define oX 0
#define oY 1

void LIST::outLIST() const{
	NODE* node = this->first;
	while (node!=nullptr)
	{
		node->outData();
		node = node->getNext();
	}
	printf("\n");
}

void LIST::setFirst(NODE* first) {
	this->first = first;
};
void LIST::setLast(NODE* last) {
	this->last = last;
};
NODE* LIST::getFirst() const {
	return this->first;
};
NODE* LIST::getLast() const {
	return this->last;
};

LIST::LIST() {
	this->first = nullptr;
	this->last = nullptr;
}
LIST::~LIST() {
	delList(this);
}
void LIST::delList(LIST* l) {
	while (l->last != l->first) {
		l->last = l->last->getPrev();
		delete(l->last->getNext());
		l->last->setNext(nullptr);
	}
	delete(l->last);
	l->last = nullptr;
	l->first = nullptr;
}



void LIST::addfirst(char character) {
	this->first = new NODE(nullptr, nullptr, character);
	this->last = this->first;
}

void LIST::push(char character) {
	if (first == nullptr) addfirst(character);
	else {
		this->first->setPrev(new NODE(nullptr, this->first, character));
		this->first = this->first->getPrev();
	}
}

void LIST::put(char character) {
	if (this->last == nullptr) addfirst(character);
	else {
		this->last->setNext(new NODE(this->last, nullptr, character));
		this->last = this->last->getNext();
	}
}



void LIST::addfirst(int xy[2]) {
	this->first = new NODE(nullptr, nullptr, xy);
	this->last = this->first;
}

void LIST::push(int xy[2]) {
	if (first == nullptr) addfirst(xy);
	else {
		this->first->setPrev(new NODE(nullptr, this->first, xy));
		this->first = this->first->getPrev();
	}
}

void LIST::put(int xy[2]) {
	if (this->last == nullptr) addfirst(xy);
	else {
		this->last->setNext(new NODE(this->last, nullptr, xy));
		this->last = this->last->getNext();
	}
}


char LIST::get() {
	char token = this->first->getCharacter();
	if (this->last == this->first) {
		delete(this->last);
		this->last = nullptr;
		this->first = nullptr;
	}
	else {
		this->first = this->first->getNext();
		delete(this->first->getPrev());
		this->first->setPrev(nullptr);
	}
	return token;
}

char LIST::pop() {
	char token=this->last->getCharacter();
	if (this->last == this->first) {
		delete(this->last);
		this->last = nullptr;
		this->first = nullptr;
	}
	else {
		this->last = this->last->getPrev();
		delete(this->last->getNext());
		this->last->setNext(nullptr);
	}
	return token;
};



void LIST::pop(int xy[2]) {
	this->last->getXY(xy);
	if (this->last == this->first) {
		delete(this->last);
		this->last = nullptr;
		this->first = nullptr;
	}
	else {
		this->last = this->last->getPrev();
		delete(this->last->getNext());
		this->last->setNext(nullptr);
	}
};
