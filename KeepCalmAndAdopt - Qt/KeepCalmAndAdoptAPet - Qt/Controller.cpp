#include "Controller.h"
#include "ExceptionsQt.h"

int Controller::addController(const Dog& d)
{
	int pos = this->repository.getElementPosition(d);
	if (pos == -1)
	{
		this->repository.addRepository(d);

		int pos = this->repository.getElementPosition(d);
		this->undoActions.push_back(std::make_unique<UndoAdd>(this->repository, d, pos));
		this->redoActions.push_back(std::make_unique<RedoAdd>(this->repository, d, pos));

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
	Dog d = this->repository.getDynamicArray().getAllElems()[pos];
	this->repository.deleteRepository(pos);

	this->undoActions.push_back(std::make_unique<UndoRemove>(this->repository, d, pos));
	this->redoActions.push_back(std::make_unique<RedoRemove>(this->repository, d, pos));
}

void Controller::updateController(int pos, const Dog& newDog)
{
	Dog d = this->repository.getDynamicArray().getAllElems()[pos];
	this->repository.updateRepository(pos, newDog);

	this->undoActions.push_back(std::make_unique<UndoUpdate>(this->repository, d, pos));
	this->redoActions.push_back(std::make_unique<RedoUpdate>(this->repository, newDog, pos));
}

void Controller::undo()
{
	
	if (undoActions.empty())
	{
		ExceptionsQt ex{ "No more actions to undo !" };
		return;
	}
	
	unique_ptr<UndoAction> last = move(undoActions.back());
	last->executeUndo();
	undoActions.pop_back();
	this->redoFlags++;
}

void Controller::redo()
{

	if (this->redoFlags == 0)
	{
		ExceptionsQt ex{ "No more actions to redo !" };
		return;
	}

	unique_ptr<RedoAction> last = move(redoActions.back());
	last->executeRedo();
	redoActions.pop_back();
	this->redoFlags--;
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




