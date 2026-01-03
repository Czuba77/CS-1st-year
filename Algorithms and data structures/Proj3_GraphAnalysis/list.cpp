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

int LIST::getIndex() const {
	return index;
}
void LIST::setIndex(int ind) {
	this->index = ind;
}
void LIST::incrementIndex() {
	this->index++;
};

NODE* LIST::getFirst() const {
	return first;
};
NODE* LIST::getLast() const {
	return last;
};

LIST::LIST() {
	this->first = nullptr;
	this->last = nullptr;
}

LIST::~LIST() {
	while (this->last != this->first) {
		this->last = this->last->getPrev();
		delete(this->last->getNext());
		this->last->setNext(nullptr);
	}
	this->first = nullptr;
	delete(this->last);
	this->last = nullptr;
	int a;
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


void LIST::setIteratorToLast() {
	iterator = last;
};
void LIST::resetIteration() {
	iterator = first;
};
void LIST::iterate() {
	iterator = iterator->getNext();
};
NODE* LIST::getItVer() const {
	return iterator;
};


void LIST::addfirst(int ind) {
	this->first = new NODE(nullptr, nullptr, ind);
	this->last = this->first;
}

void LIST::push(int ind) {
	if (first == nullptr) addfirst(ind);
	else {
		this->first->setPrev(new NODE(nullptr, this->first, ind));
		this->first = this->first->getPrev();
	}
}

void LIST::put(int ind) {
	if (this->last == nullptr) addfirst(ind);
	else {
		this->last->setNext(new NODE(this->last, nullptr, ind));
		this->last = this->last->getNext();
	}
}


int LIST::pop() {
	int ind = this->last->getIndex();
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
	return ind;
};

int LIST::get() {
	int ind = this->first->getIndex();
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
	return ind;
};


