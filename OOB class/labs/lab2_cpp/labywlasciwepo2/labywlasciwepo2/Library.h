#pragma once
#include "Book.h"
#include <initializer_list>
class Library {
	Book* array;
	std::size_t size;
public:
	friend std::ostream& operator<<(std::ostream& ostr, const Library& Library);
	Library(); 
	Library(std::size_t size);
	Library(std::initializer_list<Book> list);
	Library(const Library& orig);
	Library(Library&& orig);

	Library& operator=(const Library& other);
	Library& operator=(Library&& right);

	Book& operator[](std::size_t index);
	const Book& operator[](std::size_t index) const;
	std::size_t GetSize() const;


	~Library();
};


