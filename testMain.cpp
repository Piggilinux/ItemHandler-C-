#include "itemhandler.h"
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	ItemHandler ih;

	ih.addGame("Game", "Diablo", "Blizzard", "Computer", 1998, "Computergame");
	ih.addGame("Game","Warcraft", "Blizzard", "Computer", 2001, "Computergame");
	ih.addBook("Book","Angels And Demons", "Dan Brown", "Bookshelf", 2004, 432);
	ih.addBook("Book", "Soreccerers Stone", "JK Rowling", "Bookshelf", 1999, 232);
	ih.addMovie("Movie", "Angels And Demons", "Dan Brown", "Hardisk", 2004, 432);
	ih.addMovie("Movie", "The Return Of The King", "J.R Tolkien / Peter Jackson", "Hardisk", 2002, 8);
	ih.addMovie("Movie", "Star Wars", "George Lucas", "Hardisk", 1972, 8);
	
	std::cout << "*********** SHOW GAMES ***********" << std::endl;
	int nrOf = ih.getNrOfGames();
	std::string *str = new std::string[nrOf];
	if (ih.showAllGames(str, nrOf) != -1)
	{
		std::cout << "\nNr Of Games: " << ih.getNrOfGames() << std::endl;
		for (int i = 0; i < nrOf; i++)
		{
			std::cout << str[i] << std::endl;
		}
	} 
	delete[] str;
	getchar();
	std::cout << "*********** SHOW BOOKS ***********" << std::endl;

	nrOf = ih.getNrOfBooks();
	str = new std::string[nrOf];
	if (ih.showAllBooks(str, nrOf) != -1)
	{
		std::cout << "\n Nr Of Books: " << nrOf << std::endl;
		for (int i = 0; i < nrOf; i++)
		{
			std::cout << str[i] << std::endl;
		}
	}
	delete[] str;
	getchar();
	ih.RemoveItem("Angels And Demons", "Movie");

	std::cout << "*********** SHOW ALL ***********" << std::endl;

	nrOf = ih.getNrOfItems();
	str = new std::string[nrOf];
	if (ih.showAll(str, nrOf) != -1)
	{
		std::cout << "\n Nr Of Items: " << nrOf << std::endl;
		for (int i = 0; i < nrOf; i++)
		{
			std::cout << str[i] << std::endl;
		}
	}
	delete[] str;
	getchar();

	std::cout << "*********** SHOW ALL CONTAINING (FAIL) ***********" << std::endl;

	nrOf = ih.getNrOfItems();
	str = new std::string[nrOf];
	if (ih.showAllContaining("Z", str, nrOf) != 0)
	{
		for (int i = 0; i < nrOf; i++)
		{
			std::cout << str[i] << std::endl;
		}
	}
	else
		std::cout << "\nNo Match.." << std::endl;
	delete[] str;
	getchar();

	std::cout << "*********** SHOW ALL CONTAINING (YAY) ***********" << std::endl;

	nrOf = ih.getNrOfItems();
	str = new std::string[nrOf];
	if (ih.showAllContaining("Blizzard", str, nrOf) != 0)
	{
		for (int i = 0; i < nrOf; i++)
		{
			std::cout << str[i] << std::endl;
		}
	}
	else
		std::cout << "No Match.." << std::endl;
	delete[] str;
	
	system("pause");
}