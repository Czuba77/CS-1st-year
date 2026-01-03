#include "Book.h"
#include <iostream>
#include <string>

std::ostream& operator<<(std::ostream& ostr, const Book& b) {
	ostr << "Ksiazka: ";
	ostr << "Tytul " << b.getTitle() << " Autor " << b.getAuthor() << std::endl;;
	return ostr;
}


Book::Book() {
	this->title = "";
	this->author = "";
}

const std::string Book::getAuthor() const {
	return this->author;
}

const std::string Book::getTitle() const {
	return this->title;
}

//l
Book::Book(const std::string& author, const std::string& title) 
	:title(title), author(author){
}

void Book::setTitle(const std::string& title) {
	this->title = title;
}

void Book::setAuthor(const std::string& author) {
	this->author = author;
}


//r
Book::Book(std::string&& author, std::string&& title) 
:title(std::move(title)),author(std::move(author)){
}

void Book::setTitle(std::string&& title) {
	this->title = std::move(title);
}

void Book::setAuthor(std::string&& author) {
	this->author = std::move(author);
}

//konstruktor kopiujacy
Book::Book(const Book& other)
:author(other.author),title(other.title){
}
//konstruktor przenosz¹cy
Book::Book(Book&& other) noexcept
{
	author = std::move(other.author);
	title = std::move(other.title);
}

//kopiowanie op
Book& Book::operator=(const Book& other) {
	this->author = other.author;
	this->title = other.title;
	return *this;
}
//przenoszenie op
Book& Book::operator=(Book&& right)noexcept {
	author=std::move(right.author);
	title=std::move(right.title);
	return *this;
}

Book::~Book() {
}



