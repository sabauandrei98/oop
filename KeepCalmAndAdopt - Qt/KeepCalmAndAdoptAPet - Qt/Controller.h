#pragma once

#include "Repository.h"
#include "FileAdoptionList.h"

class Controller
{
private:
	Repository repository;
	Repository adoptionRepo;
	FileAdoptionList* fileAdoption;

public:
	Controller(const Repository& r) : repository(r) {}
	Controller(const Repository& r, FileAdoptionList* adoption) : repository(r), fileAdoption(adoption) {}

	int addController(const Dog& d);
	void updateController(int pos, const Dog& newDog);
	void deleteController(int pos);
	void addAdoptionController(Dog d);
	DynamicArray<Dog> getSpecificDogs(const Dog& d);
	Repository getRepository() const { return repository; };
	Repository getAdoptionRepository() const { return adoptionRepo; };

	void seeTheAdoptionListController();

};

