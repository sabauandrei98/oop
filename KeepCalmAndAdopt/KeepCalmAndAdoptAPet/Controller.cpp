#include "Controller.h"


void Controller::addController(const Dog& d)
{
	this->repository.addRepository(d);
}

void Controller::deleteController(const Dog& d)
{
	int pos = this->repository.getElementPosition(d);
	if (pos == -1)
	{

	}
	else
	{
		cout << pos;
		this->repository.deleteRepository(pos);
	}
}

void Controller::updateController(const Dog& oldDog, const Dog& newDog)
{
	int pos = this->repository.getElementPosition(oldDog);
	if (pos == -1)
	{

	}
	else
	{
		this->repository.updateRepository(pos, newDog);
	}
}