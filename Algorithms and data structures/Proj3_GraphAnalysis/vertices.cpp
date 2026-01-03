#include "VERTICES.h"

void VERTICES::setIsChecked(bool IsChecked, int index) {
	this->isChecked[index] = IsChecked;
};


int VERTICES::getNumOfNeigh() const {
	return number_of_neighbours;
}

int VERTICES::getColour() const {
	return colour;
}



bool VERTICES::getIsChecked(int index) const {
	return isChecked[index];
}


void VERTICES::setNeigh(int neigh) {
	this->number_of_neighbours = neigh;
}



void VERTICES::setColour(int colour) {
	this->colour = colour;
}

VERTICES::VERTICES() 
	: LIST(){
	colour = 0;
	isChecked[SS] = false;
	isChecked[DWUDZIELNOSC] = false;
	isChecked[KOLO_ZACH] = false;
}


void VERTICES::addfirst(int index) {
	this->first = new NODE(nullptr, nullptr, index);
	this->last = this->first;
}

void VERTICES::push(int index) {
	if (first == nullptr) addfirst(index);
	else {
		this->first->setPrev(new NODE(nullptr, this->first, index));
		this->first = this->first->getPrev();
	}
}

void VERTICES::put(int index) {
	if (this->last == nullptr) addfirst(index);
	else {
		this->last->setNext(new NODE(this->last, nullptr, index));
		this->last = this->last->getNext();
	}
}


int VERTICES::pop() {
	int index = this->last->getIndex();
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
	return index;
};

int VERTICES::get() {
	int index = this->first->getIndex();
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
	return index;
};
