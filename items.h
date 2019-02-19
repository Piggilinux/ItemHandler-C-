#ifndef ITEMS_H
#define ITEMS_H

#include <string>
#include <iostream>

class Item
{

private:
	std::string tag;
	std::string name;
	std::string creator;
	std::string storage;
	int year;

public:
	Item(std::string tag = " Empty",std::string name = " Empty", std::string creator = " Empty",
		std::string storage = " Empty", int year = 0);
	virtual~Item();

	std::string toString()const;
	virtual std::string toStringSpecific()const = 0;
	bool contains(std::string str)const;

	std::string getName()const;
	std::string getTag()const;
	std::string getCreator()const;
	std::string getStorage()const;
};




#endif