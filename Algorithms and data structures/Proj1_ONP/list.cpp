#include <iostream>
#include <limits.h>
#include "LIST.h"
#define NUMBER 0
#define ADDITION 1
#define MULITIPLICATION 2
#define SPECIAL 3
#define BRACKET -4

void LIST::outLIST() const{
	NODE* node = this->first;
	while (node!=nullptr)
	{
		node->outData();
		node = node->getNext();
	}
	printf("\n");
}

void LIST::outResult(){
	if (staque->first != nullptr) {
		int a = staque->get();
		printf("%d\n", a);
	}
}

void LIST::setFirst(NODE* first) {
	this->first = first;
};
void LIST::setLast(NODE* last) {
	this->last = last;
};

LIST* LIST::getStack() const {
	return this->staque;
};

NODE* LIST::getFirst() const {
	return this->first;
};
NODE* LIST::getLast() const {
	return this->last;
};

LIST::LIST(bool cond) {
	this->first = nullptr;
	this->last = nullptr;
}

LIST::LIST() {
	this->first = nullptr;
	this->last = nullptr;
	this->staque = new LIST(true);
	this->stack_mval = new LIST(true);
}

void LIST::pullgreaterprio(short prio) {
	char tmp;
	short tmp_prio, tmp_m_value;
	while (staque->first != nullptr) {
		tmp_prio = staque->last->getPrio();
		if (tmp_prio >= prio) {
			if (staque->last->getData() == 'I' || staque->last->getData() == 'A') { 
				tmp_m_value = staque->last->getM_value();
				tmp = staque->pop();
				this->put(tmp, tmp_prio, tmp_m_value);
			}
			else {
				tmp = staque->pop();
				this->put(tmp, tmp_prio);
			}
		}
		else
			break;
	}
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

void LIST::handleErr() {
	printf("ERROR\n");
	delList(staque);
	delList(stack_mval);
	delList(this);
}


void LIST::input_logic(char character) {
	NODE* point;
	switch (character)
	{
	case '-'://prio 1
	case '+':
		this->pullgreaterprio(ADDITION);
		staque->put(character, ADDITION);
		break;

	case '*'://prio 2
	case '/'://dodaj exeption ze nie moze byc 0 
		this->pullgreaterprio(MULITIPLICATION);
		staque->put(character, MULITIPLICATION);
		break;

	case 'M'://min max //prio 3
		character = std::getchar(); // rozorzanianie min i max
		std::getchar(); //buffor
		stack_mval->put(1);//stawia na stack mvalue o 1 bo pierwsza wartosc jest  bez przecinka
		if (staque->last != nullptr && staque->last->getPrio() != SPECIAL)
			this->pullgreaterprio(SPECIAL);
		staque->put(character, SPECIAL);
		break;
	case 'I'://if
		character = std::getchar();
		if (staque->last != nullptr && staque->last->getPrio() != SPECIAL)
			this->pullgreaterprio(SPECIAL);
		staque->put(character, SPECIAL);
		stack_mval->put(character, SPECIAL);
		break;
	case 'N'://negacja
		if(staque->last!=nullptr && staque->last->getPrio() != SPECIAL)
			this->pullgreaterprio(SPECIAL);
		staque->put(character, SPECIAL);
		break;

	case '(': //prio 4
		stack_mval->put(character,BRACKET);
		staque->put(character, BRACKET);
		break;
	case ')':
		while (staque->first != nullptr) {
			character = staque->pop();
			if (character == '(') break;
			else this->put(character, BRACKET);
		}
		stack_mval->pop();//popuje nawias z mval
		if (stack_mval->last != nullptr) {
			if (stack_mval->last->getPrio() == 0) { // jesli jest na mval jakis nie nawias to sciaga wartosc z mval i operator M ze stosu i daje mu dobre mval
				character = staque->pop();
				this->put(character, SPECIAL, stack_mval->pop());
			}
			else if (stack_mval->last->getData() == 'F') { // jesli jest na mval jakis nie nawias to sciaga wartosc z mval i operator M ze stosu i daje mu dobre mval
				character = staque->pop();
				stack_mval->pop();
				this->put(character, SPECIAL);
			}
		}
		break;
	case ',':
		while (staque->first != nullptr && staque->getLast()->getData() != '(') {
			character = staque->pop();
			this->put(character, BRACKET);
		}
		stack_mval->last->getPrev()->incrementNumber();
		break;

	case '.':
		this->dot_counter++;
		break;

	default:
		if (isdigit(character)) { //liczba
			char liczbaT[10];
			int i = 0;
			while (isdigit(character)) {
				liczbaT[i] = character;
				i++;
				character = std::getchar();
			}
			i = atoi(liczbaT);
			this->put(i);
			input_logic(character);
		}
		break;
	};
}

void LIST::input() {
	int dot = dot_counter + 1;
	char tmp;
	while (dot > dot_counter) {
		tmp = std::getchar();
		input_logic(tmp);
	}
	while (staque->first!=nullptr)
	{
		tmp = staque->pop();
		if (isdigit(tmp))
			this->put(tmp);
		else
			this->put(tmp, 3);
	}
}

void LIST::createSolvingQueue() {
	while (this->first != nullptr && this->first->getPrio() == 0) {
		reAsignNodeToQue();
	}
	reAsignNodeToQue();
}

void LIST::SolveQueue() {
	int a, b, c, i, m_val, minmax;
	switch (staque->first->getData())
	{
	case '-':
		staque->get(true);
		a = staque->get();
		b = staque->get();
		staque->push(b - a);
		break;
	case '+':
		staque->get(true);
		a = staque->get();
		b = staque->get();
		staque->push(b + a);
		break;
	case '*':
		staque->get(true);
		a = staque->get();
		b = staque->get();
		staque->push(b * a);
		break;
	case '/':
		staque->get(true);
		a = staque->get(); 
		b = staque->get();
		if (a == 0)
			handleErr();
		else
			staque->push(b / a);
		break;
	case 'I'://min
		m_val = staque->first->getM_value();
		i = 0; 
		minmax = INT_MAX;
		staque->get(true);
		while (i < m_val) {
			a = staque->get();
			if (a < minmax) {
				minmax = a;
			}
			i++;
		}
		staque->push(minmax);
		break;
	case 'A'://max
		m_val = staque->first->getM_value(); 
		i = 0; 
		minmax = INT_MIN;
		staque->get(true);
		while (i < m_val) {
			a = staque->get();
			if (a > minmax) {
				minmax = a;
			}
			i++;
		}
		staque->push(minmax);
		break;
	case 'F'://if
		staque->get(true);
		a = staque->get();
		b = staque->get(); 
		c = staque->get();
		if (c > 0)
			staque->push(b);
		else
			staque->push(a);
		break;
	case 'N'://negacja
		staque->get(true);
		a = staque->get();
		staque->push(-a);
		break;
	}
}



void LIST::addfirst(int numb) {
	this->first=new NODE(nullptr, nullptr, NUMBER, numb);
	this->last = this->first;
}

void LIST::addfirst(char oper, short prio) {
	this->first = new NODE(nullptr, nullptr, oper, prio);
	this->last = this->first;
}

void LIST::addfirst(char oper, short prio, short m_value) {
	this->first = new NODE(nullptr, nullptr, oper, prio, m_value);
	this->last = this->first;
}

void LIST::push(int numb) {
	if (first == nullptr) addfirst(numb);
	else {
		this->first->setPrev(new NODE(nullptr, this->first, 0, numb));
		this->first = this->first->getPrev();
	}
}

void LIST::push(char oper, short prio) {
	if (first == nullptr) addfirst(oper, prio);
	else {
		this->first->setPrev(new NODE(nullptr, this->first, oper, prio));
		this->first = this->first->getPrev();
	}
}

void LIST::push(char oper, short prio, short m_value) {
	if (first == nullptr) addfirst(oper, prio, m_value);
	else {
		this->first->setPrev(new NODE(nullptr, this->first, oper, prio, m_value));
		this->first = this->first->getPrev();
	}
}

void LIST::put(int numb) {
	if (this->last == nullptr) addfirst(numb);
	else {
		this->last->setNext(new NODE(this->last, nullptr, NUMBER, numb));
		this->last = this->last->getNext();
	}
}

void LIST::put(char oper, short prio) {
	if (this->last == nullptr) addfirst(oper, prio);
	else {
		this->last->setNext(new NODE(this->last, nullptr, oper, prio));
		this->last = this->last->getNext();
	}
}

void LIST::put(char oper, short prio,short m_value) {
	if (this->last == nullptr) addfirst(oper, prio, m_value);
	else {
		this->last->setNext(new NODE(this->last, nullptr, oper, prio, m_value));
		this->last = this->last->getNext();
	}
}

int LIST::get() {
	int numb = this->first->getNumber();
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
	return numb;
}

char LIST::get(bool cond) {
	char token = this->first->getData();
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
	char token=this->last->getData();
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

void LIST::reAsigningThisPoint() {
	if (this->last == this->first) {
		this->last = nullptr;
		this->first = nullptr;
	}
	else {
		this->first = this->first->getNext();
		this->first->setPrev(nullptr);
	}
}

void LIST::reAsignNodeToQue() {
	if (staque->first == nullptr) {
		staque->first = this->first;
		staque->last = staque->first;
		reAsigningThisPoint();
		staque->first->setNext(nullptr);
	}
	else {
		staque->first->setPrev(this->first);
		reAsigningThisPoint();
		staque->first->getPrev()->setNext(staque->first);
		staque->first = staque->first->getPrev();
	}
}