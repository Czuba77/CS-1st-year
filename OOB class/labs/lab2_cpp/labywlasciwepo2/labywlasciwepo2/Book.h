#pragma once
#include <string>
class Book {
	std::string author, title;
public:
	friend std::ostream& operator<<(std::ostream& ostr, const Book& b);

	Book();

	// l
	Book(const std::string& author, const std::string& title);
	void setAuthor(const std::string& author);
	void setTitle(const std::string& title);
	
	// r
	Book(std::string&& author, std::string&& title);
	void setAuthor(std::string&& author);
	void setTitle(std::string&& title);

	const std::string getAuthor() const;
	const std::string getTitle() const;
	
	Book(const Book& other);
	Book(Book&& other) noexcept;

	//kopiujacy op
	Book& operator=(const Book& other);
	//przenoszacy op
	Book& operator=(Book&& right) noexcept;

	~Book();
};


