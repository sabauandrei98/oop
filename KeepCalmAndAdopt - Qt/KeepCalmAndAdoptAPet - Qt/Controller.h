#pragma once

#include "Repository.h"
#include "FileAdoptionList.h"
#include <memory>
#include "Undo.h"
#include "Redo.h"

class Controller
{
private:
	Repository repository;
	Repository adoptionRepo;
	FileAdoptionList* fileAdoption;
	std::vector<std::unique_ptr<UndoAction>> undoActions;
	std::vector<std::unique_ptr<RedoAction>> redoActions;
	int redoFlags = 0;

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
	Repository& getRefRepository() { return repository; }

	void seeTheAdoptionListController();
	void undo();
	void redo();
};

