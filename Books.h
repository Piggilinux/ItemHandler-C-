#ifndef BOOKS_H
#define BOOKS_H

#include "items.h"

class Books : public Item
{

private:
	int pages;

public:
	Books(std::string tag = " Empty", std::string name = " Empty", std::string creator = " Empty",
		std::string storage = " Empty", int year = 0, int pages = 0);
	virtual~Books();

	std::string toStringSpecific()const;

	int getPages()const;

};

#endif 
