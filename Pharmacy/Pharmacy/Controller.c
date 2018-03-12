#include "Controller.h"
#include "Repository.h"

Controller createController(DynamicRepo* repository)
{
	Controller newController;
	newController.repository = repository;

	return newController;
}

int controllerAddElement(Controller* controller, Medication medication)
{
	int inRepoPos = inRepo(controller->repository, medication);
	if (inRepoPos == -1)
	{
		//add new
		int operation = addElement(controller->repository, medication);
		return operation; //1, success or -1, memory error
	}
	else
	{
		//update
		controller->repository->elements[inRepoPos].quantity += medication.quantity;
		int operation = 2;
		return operation; //quantity update
	}
}