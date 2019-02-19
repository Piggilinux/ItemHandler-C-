#ifndef GAMES_H
#define GAMES_H

#include "items.h"

class Games : public Item
{

private:
	std::string gameType;

public:
	Games(std::string tag = " Empty", std::string name = " Empty", std::string creator = " Empty",
		std::string storage = " Empty", int year = 0, std::string gameType = " Empty");
	virtual~Games();

	std::string toStringSpecific()const;

	std::string getGameType()const;
};

#endif 
