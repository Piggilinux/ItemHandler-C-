#ifndef ITEMHANDLER_H
#define ITEMHANDLER_H

#include "books.h"
#include "movies.h"
#include "games.h"

class ItemHandler
{

private:
	int capacity;
	int nrOfItems;
	int nrOfMovies;
	int nrOfGames;
	int nrOfBooks;
	Item* *items;
	void initiate(int from = 0);
	void freeMemory();
	void expand();
	int find(std::string what, std::string tag)const;
	void deepCopy(const ItemHandler & rhs);

public:
	ItemHandler();
	ItemHandler(const ItemHandler &rhs);
	virtual~ItemHandler();
	void operator=(const ItemHandler &rhs);

	bool addGame(std::string tag, std::string name, std::string creator, std::string storage, int year, std::string gameType);
	bool addMovie(std::string tag, std::string name, std::string creator, std::string storage, int year, int rating);
	bool addBook(std::string tag, std::string name, std::string creator, std::string storage, int year, int pages);
	bool RemoveItem(std::string tag, std::string name);

	int showAllContaining(std::string str, std::string arr[], int capOfArr)const;
	int showAllGames(std::string arr[], int capOfArray)const;
	int showAllMovies(std::string arr[], int capOfArray)const;
	int showAllBooks(std::string arr[], int capOfArray)const;
	int showAll(std::string arr[], int capOfArray)const;

	int getNrOfItems()const;
	int getNrOfGames()const;
	int getNrOfMovies()const;
	int getNrOfBooks()const;

};




#endif