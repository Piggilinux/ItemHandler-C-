#include "games.h"

Games::Games(std::string tag, std::string name, std::string creator, std::string storage,
	int year, std::string gameType)
	:Item(tag, name, creator, storage, year)
{
	this->gameType = gameType;
}

Games::~Games()
{
}

std::string Games::toStringSpecific() const
{
	return this->toString() + "\nType of game: " + this->gameType;
}


std::string Games::getGameType() const
{
	return this->gameType;
}
