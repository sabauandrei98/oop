#include "Controller.h"


void Controller::addController(const Dog& d)
{
	int pos = this->repository.getElementPosition(d);
	if (pos == -1)
		this->repository.addRepository(d);
}

void Controller::addAdoptionController(const Dog& d)
{
	this->adoptionRepo.addRepository(d);
}

void Controller::deleteController(const Dog& d)
{
	int pos = this->repository.getElementPosition(d);
	if (pos != -1)
		this->repository.deleteRepository(pos);
}

void Controller::updateController(const Dog& oldDog, const Dog& newDog)
{
	int pos = this->repository.getElementPosition(oldDog);
	if (pos != -1)
		this->repository.updateRepository(pos, newDog);
}

DynamicArray<Dog> Controller::getSpecificDogs(const Dog& dog)
{
	DynamicArray<Dog> dogs = this->getRepository().getDynamicArray();
	DynamicArray<Dog> result;
	Dog* dogsList = dogs.getAllElems();

	for (int i = 0; i < dogs.getSize(); i++)
		if (dogsList[i].getBreed() == dog.getBreed() && dogsList[i].getAge() <= dog.getAge())
			result.addDynamicArray(dogsList[i]);

	return result;
}
