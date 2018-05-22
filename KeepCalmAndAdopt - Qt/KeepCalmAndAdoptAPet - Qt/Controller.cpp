#include "Controller.h"
#include "ExceptionsQt.h"

int Controller::addController(const Dog& d)
{
	int pos = this->repository.getElementPosition(d);
	if (pos == -1)
	{
		this->repository.addRepository(d);
		return 0;
	}
	return 1;
}

void Controller::addAdoptionController(Dog d)
{
	this->fileAdoption->addDynamicArray(d);
	this->fileAdoption->writeToFile();
}

void Controller::deleteController(int pos)
{
	this->repository.deleteRepository(pos);
}

void Controller::updateController(int pos, const Dog& newDog)
{
	this->repository.updateRepository(pos, newDog);
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

void Controller::seeTheAdoptionListController()
{
	this->fileAdoption->displayAdoptionList();
}


