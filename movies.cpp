#include "movies.h"

Movies::Movies(std::string tag, std::string name, std::string creator, std::string storage,
	int year, int rating)
	:Item(tag, name, creator, storage, year)
{
	this->rating = rating;
}

Movies::~Movies()
{
}

std::string Movies::toStringSpecific() const
{
	return this->toString() + "Rating: " + std::to_string(this->rating);
}


int Movies::getRating() const
{
	return this->rating;
}




