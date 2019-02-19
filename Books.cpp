#include "Books.h"

Books::Books(std::string tag, std::string name, std::string creator, std::string storage,
	int year, int pages)
	:Item(tag, name, creator, storage, year)
{
	this->pages = pages;
}

Books::~Books()
{
}

std::string Books::toStringSpecific() const
{
	return this->toString() + "Pages: " + std::to_string(this->pages);
}


int Books::getPages() const
{
	return this->pages;
}
