#include "itemhandler.h"

void ItemHandler::initiate(int from)
{
	for (int i = from; i < this->capacity; i++)
	{
		this->items[i] = nullptr;
	}
}

void ItemHandler::freeMemory()
{
	for (int i = 0; i < this->nrOfItems; i++)
	{
		delete this->items[i];
	}
	delete[] items;
}

void ItemHandler::expand()
{
	this->capacity += 100;
	Item* *temp = new Item*[capacity];
	for (int i = 0; i < this->nrOfItems; i++)
	{
		temp[i] = this->items[i];
	}
	delete[] items;
	this->items = temp;
	this->initiate(this->nrOfItems);
}

int ItemHandler::find(std::string what,std::string tag) const
{
	int pos = -1;
	for (int i = 0; i < this->nrOfItems && pos == -1; i++)
	{
		if (this->items[i]->getName() == what && this->items[i]->getTag() == tag)
		{
			pos = i;
		}
	}
	return pos;
}

void ItemHandler::deepCopy(const ItemHandler & rhs)
{
	this->capacity = rhs.capacity;
	this->nrOfItems = rhs.nrOfItems;
	int nrOfMovies = rhs.nrOfMovies;
	int nrOfGames = rhs.nrOfGames;
	int nrOfBooks = rhs.nrOfBooks;
	this->items = new Item*[rhs.capacity];
	for (int i = 0; i < rhs.nrOfItems; i++)
	{
		if (Games* gamePtr = dynamic_cast<Games*>(rhs.items[i]))
		{
			if (gamePtr != nullptr)
			{
				this->items[i] = new Games(*gamePtr);
			}
		}
		else if (Movies* moviePtr = dynamic_cast<Movies*>(rhs.items[i]))
		{
			if (moviePtr != nullptr)
			{
				this->items[i] = new Movies(*moviePtr);
			}
		}
		else if (Books* bookPtr = dynamic_cast<Books*>(rhs.items[i]))
		{
			if (gamePtr != nullptr)
			{
				this->items[i] = new Books(*bookPtr);
			}
		}
	}
}

ItemHandler::ItemHandler()
{
	this->capacity = 100;
	this->nrOfItems = 0;
	int nrOfMovies = 0;
	int nrOfGames = 0;
	int nrOfBooks = 0;
	this->items = new Item*[capacity];
	this->initiate();
}

ItemHandler::ItemHandler(const ItemHandler & rhs)
{
	this->deepCopy(rhs);

}

ItemHandler::~ItemHandler()
{
	this->freeMemory();
}

void ItemHandler::operator=(const ItemHandler & rhs)
{
	if (this != &rhs)
	{
		this->freeMemory();
		this->deepCopy(rhs);
	}
}

bool ItemHandler::addGame(std::string tag, std::string name, std::string creator, std::string storage, int year, std::string gameType)
{
	bool added = false;
	int check = this->find(name,tag);
	
	if(check != -1)
	{ 
		std::cout << "There is already and object with this name!" << std::endl;
		
	}
	else
	{
		if (this->nrOfItems == this->capacity)
		{
			this->expand();
		}
		this->items[this->nrOfItems++] = new Games(tag, name, creator, storage, year, gameType);
		this->nrOfGames++;
		added = true;
	}
	return added;
}

bool ItemHandler::addMovie(std::string tag, std::string name, std::string creator, std::string storage, int year, int rating)
{
	bool added = false;
	int check = this->find(name, tag);

	if (check != -1)
	{
		std::cout << "There is already and object with this name!" << std::endl;

	}
	else
	{
		if (this->nrOfItems == this->capacity)
		{
			this->expand();
		}
		this->items[this->nrOfItems++] = new Movies(tag, name, creator, storage, year, rating);
		this->nrOfMovies++;
		added = true;
	}
	return added;
}

bool ItemHandler::addBook(std::string tag, std::string name, std::string creator, std::string storage, int year, int pages)
{
	bool added = false;
	int check = this->find(name, tag);

	if (check != -1)
	{
		std::cout << "There is already and object with this name!" << std::endl;

	}
	else
	{
		if (this->nrOfItems == this->capacity)
		{
			this->expand();
		}
		this->items[this->nrOfItems++] = new Books(tag, name, creator, storage, year, pages);
		this->nrOfBooks++;
		added = true;
	}
	return added;
}

bool ItemHandler::RemoveItem(std::string name, std::string tag)
{
	bool deleted = false;
	int found = this->find(name, tag);

	if (found != -1)
	{
		delete this->items[found];
		this->items[found] = this->items[--this->nrOfItems];
		
		if (tag == "Movie")
			this->nrOfMovies--;
		else if (tag == "Book")
			this->nrOfBooks--;
		else  if(tag == "Game")
			this->nrOfGames--;

		deleted = true;
	}

	return deleted;
}

int ItemHandler::showAllContaining(std::string str, std::string arr[], int capOfArr) const
{
	int index = 0;

	for (int i = 0; i < this->nrOfItems; i++)
	{
		if (this->items[i]->contains(str) == true)
		{
			index++;
		}
	}

	if (capOfArr >= index)
	{
		index = 0;
		for (int i = 0; i < this->nrOfItems; i++)
		{
			if (this->items[i]->contains(str) == true)
			{
				arr[index++] = items[i]->toString();
			}
		}
	}
	else
		index = -1;
	
	return index;
}

int ItemHandler::showAllGames(std::string arr[], int capOfArray)const
{
	int index = 0;
	if (capOfArray >= this->nrOfGames)
	{

		for (int i = 0; i < this->nrOfItems; i++)
		{
			Games* gamePtr = dynamic_cast<Games*>(this->items[i]);
			if (gamePtr != nullptr)
			{
				arr[index++] = items[i]->toString();
			}
		}
	}
	else
	{
		index = -1;
	}

	return index;
}

int ItemHandler::showAllMovies(std::string arr[], int capOfArray)const
{
	int index = 0;
	if (capOfArray >= this->nrOfMovies)
	{
		for (int i = 0; i < this->nrOfItems; i++)
		{
			Movies* movieptr = dynamic_cast<Movies*> (this->items[i]);
			if (movieptr != nullptr)
			{
				arr[index++] = this->items[i]->toString();
			}
		}
	}
	return index;
}

int ItemHandler::showAllBooks(std::string arr[], int capOfArray)const
{
	int index = 0;
	if (capOfArray >= this->nrOfBooks)
	{
		for (int i = 0; i < this->nrOfItems; i++)
		{
			Books* bookptr = dynamic_cast<Books*> (this->items[i]);
			if (bookptr != nullptr)
			{
				arr[index++] = this->items[i]->toString();
			}
		}
	}
	return index;
}

int ItemHandler::showAll(std::string arr[], int capOfArray)const
{
	
	if (capOfArray >= this->nrOfItems)
	{
		for (int i = 0; i < this->nrOfItems; i++)
		{
			arr[i] = this->items[i]->toString();
		}
	}
	return this->nrOfItems;
}

int ItemHandler::getNrOfItems() const
{
	return this->nrOfItems;
}

int ItemHandler::getNrOfGames() const
{
	return this->nrOfGames;
}

int ItemHandler::getNrOfMovies() const
{
	return this->nrOfMovies;
}

int ItemHandler::getNrOfBooks() const
{
	return this->nrOfBooks;
}





