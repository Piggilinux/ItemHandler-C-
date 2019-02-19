#include "items.h"

Item::Item(std::string tag, std::string name, std::string creator, std::string storage, int year)
{
	this->tag = tag;
	this->name = name;
	this->creator = creator;
	this->storage = storage;
	this->year = year;
}

Item::~Item()
{
}

std::string Item::toString() const
{
	return "\nTag: " +this->tag + "\nName: " + this->name + "\nCreator: " + this->creator + "\nYear: " + std::to_string(this->year) + "\nStorage: " + this->storage;
}

bool Item::contains(std::string str) const
{
	bool found = false;
	if (this->getName().find(str) != this->getName().npos || this->getCreator().find(str) != this->getName().npos)
	{
		found = true;
	}
	
	return found;
}

std::string Item::getName() const
{
	return this->name;
}

std::string Item::getTag() const
{
	return this->tag;
}

std::string Item::getCreator() const
{
	return this->creator;
}

std::string Item::getStorage() const
{
	return this->storage;
}
