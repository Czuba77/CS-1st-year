#include "Library.h"
#include <initializer_list>
#include <algorithm>
#include <iostream>
#include "Book.h"

std::ostream& operator<<(std::ostream& ostr, const Library& Library) {
	if (Library.size > 0) {
		ostr << "Lib"<<std::endl;
		for (std::size_t i = 0; i < Library.GetSize(); i++)
		{
			ostr << Library[i];
		}
	}
	return ostr;
}

//bezparametrowy
Library::Library(){
	array = nullptr;
	size = 0;
}

Library::Library(std::size_t size)
	:size{ size }, array{ new Book[size] }
{
}


Library::Library(const Library& other) //Konstruktor kopiujacy 
	: size{ other.size }, array{ new Book[other.size] } {
	for (std::size_t i = 0; i < size; i++)
		array[i] = other.array[i];
}

Library::Library(Library&& other) //konst przenoszacy
{
	array = other.array;
	size = other.size;
	other.array = nullptr;
	other.size = 0;
}

std::size_t Library::GetSize() const {
	return size;
}

Book& Library::operator[](std::size_t i)
{
	return array[i];
}

const Book& Library::operator[](std::size_t index) const {
	return array[index];
}

//konsturkor lista inicjalizacyjna
Library::Library(std::initializer_list<Book> initList)
	: size{ initList.size() }, array{ new Book[initList.size()] }
{
	std::size_t i = 0;
	for ( Book book : initList)
	{
		array[i] = book;
		i++;
	}
}

//operator przypisywania
Library& Library::operator=(const Library& other) {
	Library tmp = other;
	std::swap(array, tmp.array);
	std::swap(size, tmp.size);
	return *this;
}

//przenoszenia
Library& Library::operator=(Library&& right) {
	std::swap(array, right.array); 
	std::swap(size, right.size);
	return *this;
}


Library::~Library()
{
	if (array != nullptr)
	{
		delete[] array;
	}
}
;