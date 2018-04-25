#include "Repo.h"

#include <iostream>
#include <string>
using namespace std;

Repo::Repo()
{
}

int Repo::inRepo(bacteria bac) {
	for (int i = 0; i < this->list.size(); i++)
		if (bac.getName() == list[i].getName())
			return i;
	return -1;
}

void Repo::addRepo(bacteria bac)
{
	this->list.push_back(bac);
}

void Repo::updateRepo(int pos, bacteria bac)
{
	int number = this->list[pos].getNumber() + bac.getNumber();
	this->list[pos].setNumber(number);
}


Repo::~Repo()
{
}
