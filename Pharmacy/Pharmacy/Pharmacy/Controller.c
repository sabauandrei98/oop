#include "Controller.h"
#include "Repository.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

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
		if (strstr(controller->repository->elements[i].name, medication.name) != NULL)
			addElement(dr, controller->repository->elements[i]);
	
	return dr;
}

DynamicRepo* controllerShortSupply(Controller* controller, int quantity)
{
	if (controller->repository == NULL)
		return NULL; //memory problem

	for (int i = 0; i < controller->repository->length; i++)
		if (controller->repository->elements == NULL)
			return NULL; //memory problem

	DynamicRepo* dr = createDynamicRepo(1);

	for (int i = 0; i < controller->repository->length; i++)
		if (controller->repository->elements[i].quantity < quantity)
			addElement(dr, controller->repository->elements[i]);

	return dr;
}


void controllerTest()
{
	DynamicRepo* dr = createDynamicRepo(5);
	Controller con = createController(dr);

	assert(controllerAddElement(&con, createMedication("Raceala1", 10, 0, 150)) == 1);
	assert(controllerAddElement(&con, createMedication("Raceala1", 10, 500, 150)) == 2);

	//tested:
	//controllerAddElement  (add + update)

	assert(controllerUpdateElement(&con, createMedication("Raceala1", 10, 5, 150)) == 1);
	assert(controllerUpdateElement(&con, createMedication("Raceala2", 150, 5, 999)) == -1);

	//tested:
	//controllerUpdateElement (update + not found)

	assert(controllerRemoveElement(&con, createMedication("Raceala1", 10, 5, 150)) == 1);
	assert(controllerRemoveElement(&con, createMedication("Raceala5", 500, 200, 150)) == -1);

	//tested:
	//controllerRemoveElement (remove + not found)
	
	controllerAddElement(&con, createMedication("Raceala5", 10, 0, 150));
	controllerAddElement(&con, createMedication("Nurofen", 10, 0, 150));
	controllerAddElement(&con, createMedication("Raceala6", 10, 0, 150));

	
	DynamicRepo* searchInRepo = controllerSearchElement(&con, createMedication("ace", 0, 0, 0));
	Controller newCon = createController(searchInRepo);

	assert(strcmp(newCon.repository->elements[0].name, "Raceala5") == 0);
	assert(strcmp(newCon.repository->elements[1].name, "Raceala6") == 0);
	assert(newCon.repository->length == 2);

	//tested:
	//controllerSearchElement

	destroyDynamicRepo(dr);
	destroyDynamicRepo(searchInRepo);

}