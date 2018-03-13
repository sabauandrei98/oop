#include "Controller.h"
#include "Repository.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Controller createController(DynamicRepo* repository)
{
	Controller newController;
	newController.repository = repository;

	return newController;
}

int controllerAddElement(Controller* controller, Medication medication)
{
	int inRepoPos = inRepo(controller->repository, medication);

	if (inRepoPos == -2)
		return -2; //memory problem

	if (inRepoPos == -1)
	{
		//add new
		addElement(controller->repository, medication);
		return 1; //success
	}
	else
	{
		//update
		medication.quantity += controller->repository->elements[inRepoPos].quantity;
		updateElement(controller->repository, inRepoPos, medication);
		return 2; //quantity update
	}
}

int controllerUpdateElement(Controller* controller, Medication medication)
{
	int inRepoPos = inRepo(controller->repository, medication);

	if (inRepoPos == -2)
		return -2; //memory problem

	if (inRepoPos == -1)
	{
		return -1; //not found
	}
	else
	{
		//update
		updateElement(controller->repository, inRepoPos, medication);
		return 1; //successful update
	}
}

int controllerRemoveElement(Controller* controller, Medication medication)
{
	int inRepoPos = inRepo(controller->repository, medication);

	if (inRepoPos == -2)
		return -2; //memory problem

	if (inRepoPos == -1)
	{
		return -1; //not found
	}
	else
	{
		//delete
		removeElement(controller->repository, inRepoPos);
		return 1; //successful delete
	}
}

DynamicRepo* controllerSearchElement(Controller* controller, Medication medication)
{
	if (controller->repository == NULL)
		return NULL; //memory problem

	for(int i = 0; i < controller->repository->length; i++)
		if (controller->repository->elements == NULL)
			return NULL; //memory problem

	DynamicRepo* dr = createDynamicRepo(1);
	
	for (int i = 0; i < controller->repository->length; i++)
		if (strcmp(controller->repository->elements[i].name, medication.name) == 0)
			addElement(dr, controller->repository->elements[i]);
	
	return dr;
}