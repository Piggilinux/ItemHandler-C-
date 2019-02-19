#ifndef MOVIES_H
#define MOVIES_H

#include "items.h"

class Movies : public Item
{

private:
	int rating;

public:
	Movies(std::string tag = " Empty", std::string name = " Empty", std::string creator = " Empty",
		std::string storage = " Empty", int year = 0, int rating = 0);
	virtual~Movies();

	std::string toStringSpecific()const;

	int getRating()const;
};

#endif 
