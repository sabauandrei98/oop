#include "Controller.h"

void Controller::addController(const Dog& d)
{
	int pos = this->repository.getElementPosition(d);
	if (pos == -1)
	{
		this->repository.addRepository(d);
		throw Exceptions(typeid(this).name(), "Element added");
	}
	else
		throw Exceptions(typeid(this).name(), "Already in the repository");
}

void Controller::addAdoptionController(const Dog& d)
{
	this->adoptionRepo.addRepository(d);
}

void Controller::deleteController(const Dog& d)
{
	int pos = this->repository.getElementPosition(d);
	if (pos != -1)
	{
		this->repository.deleteRepository(pos);
		throw Exceptions(typeid(this).name(), "Element deleted");
	}
	else
		throw Exceptions(typeid(this).name(), "No such element");
}

void Controller::updateController(const Dog& oldDog, const Dog& newDog)
{
	int pos = this->repository.getElementPosition(oldDog);
	if (pos != -1)
	{
		this->repository.updateRepository(pos, newDog);
		throw Exceptions(typeid(this).name(), "Element updated");
	}
	else
		throw Exceptions(typeid(this).name(), "No such element");
}

DynamicArray<Dog> Controller::getSpecificDogs(const Dog& dog)
{
	DynamicArray<Dog> dogs = this->getRepository().getDynamicArray();
	DynamicArray<Dog> result;
	vector<Dog> dogsList = dogs.getAllElems();

	for (int i = 0; i < dogs.getSize(); i++)
		if (dogsList[i].getBreed() == dog.getBreed() && dogsList[i].getAge() <= dog.getAge())
			result.addDynamicArray(dogsList[i]);

	return result;
}


