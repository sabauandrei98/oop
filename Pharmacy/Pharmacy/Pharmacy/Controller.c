#include "Controller.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

Controller createController(DynamicRepo* repository)
{
	Controller newController;
	newController.repository = repository;
	newController.operationStack = createOperationStack();

	return newController;
}

int controllerAddElement(Controller* controller, Medication* medication)
{
	int inRepoPos = inRepo(controller->repository, medication);

	if (inRepoPos == -2)
		return -2; //memory problem
	

	if (inRepoPos == -1)
	{
		Operation* newOperation = createOperation(medication, "add");
		pushOperation(controller->operationStack, newOperation);

		//add new
		addElement(controller->repository, medication);
		return 1; //success
	}
	else
	{

		Operation* newOperation = createOperation(&controller->repository->elements[inRepoPos], "update");
		pushOperation(controller->operationStack, newOperation);

		//update
		medication->quantity += controller->repository->elements[inRepoPos].quantity;
		updateElement(controller->repository, inRepoPos, medication);
		
		return 2; //quantity update
	}
}

int controllerUpdateElement(Controller* controller, Medication* medication)
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
		Operation* newOperation = createOperation(&controller->repository->elements[inRepoPos], "update");
		pushOperation(controller->operationStack, newOperation);

		//update
		updateElement(controller->repository, inRepoPos, medication);
		return 1; //successful update
	}
}

int controllerRemoveElement(Controller* controller, Medication* medication)
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
		Operation* newOperation = createOperation(medication, "remove");
		pushOperation(controller->operationStack, newOperation);

		//delete
		removeElement(controller->repository, inRepoPos);
		return 1; //successful delete
	}
}

DynamicRepo* controllerSearchElement(Controller* controller, Medication* medication)
{
	if (controller->repository == NULL)
		return NULL; //memory problem

	for(int i = 0; i < controller->repository->length; i++)
		if (controller->repository->elements == NULL)
			return NULL; //memory problem

	DynamicRepo* dr = createDynamicArray(1);
	
	for (int i = 0; i < controller->repository->length; i++)
		if (strstr(controller->repository->elements[i].name, medication->name) != NULL)
			addElement(dr, &controller->repository->elements[i]);
	
	free(medication);
	return dr;
}

DynamicRepo* controllerShortSupply(Controller* controller, int quantity)
{
	if (controller->repository == NULL)
		return NULL; //memory problem

	for (int i = 0; i < controller->repository->length; i++)
		if (controller->repository->elements == NULL)
			return NULL; //memory problem

	DynamicRepo* dr = createDynamicArray(1);

	for (int i = 0; i < controller->repository->length; i++)
		if (controller->repository->elements[i].quantity < quantity)
			addElement(dr, &controller->repository->elements[i]);

	return dr;
}

int controllerUndo(Controller* controller)
{
	int size = controller->operationStack->length;
	if (size == 0)
		return -3; //nothing to undo

	OperationStack* os = controller->operationStack;
	Operation* op = popOperation(os);

	printMedication(op->medication);

	if (strcmp(op->operation, "add") == 0)
	{
		int pos = inRepo(controller->repository, op->medication);
		removeElement(controller->repository, pos);
	}
	else if (strcmp(op->operation, "remove") == 0)
	{
		printf(op->medication->name);
		addElement(controller->repository, op->medication);
	}
	else if (strcmp(op->operation, "update") == 0)
	{
		int pos = inRepo(controller->repository, op->medication);
		updateElement(controller->repository, pos, op->medication);
	}
}

int controllerRedo(Controller* controller)
{
	int size = controller->operationStack->length;
	if (size == 0)
		return -4; //nothing to redo


	OperationStack* os = controller->operationStack;
	Operation* op = getTopOperation(os);

	if (strcmp(op->operation, "add") == 0)
	{
		int pos = inRepo(controller->repository, op->medication);
		Medication* med = &controller->repository->elements[pos];
		med->quantity += op->medication->quantity;
		updateElement(controller->repository, pos, med);

	}
	else if (strcmp(op->operation, "remove") == 0)
	{
		int pos = inRepo(controller->repository, op->medication);
		if(pos != -1)
			removeElement(controller->repository, pos);
	}
}


void controllerTest()
{
	DynamicRepo* dr = createDynamicArray(5);
	Controller con = createController(dr);

	Medication* med = createMedication("Raceala1", 10, 0, 150);

	assert(controllerAddElement(&con, med) == 1);
	free(med);

	med = createMedication("Raceala1", 10, 500, 150);
	assert(controllerAddElement(&con, med) == 2);
	free(med);

	//tested:
	//controllerAddElement  (add + update)
	med = createMedication("Raceala1", 10, 5, 150);
	assert(controllerUpdateElement(&con, med) == 1);
	free(med);

	med = createMedication("Raceala2", 150, 5, 999);
	assert(controllerUpdateElement(&con, med) == -1);
	free(med);

	//tested:
	//controllerUpdateElement (update + not found)

	med = createMedication("Raceala1", 10, 5, 150);
	assert(controllerRemoveElement(&con, med) == 1);
	free(med);

	med = createMedication("Raceala5", 500, 200, 150);
	assert(controllerRemoveElement(&con, med) == -1);
	free(med);

	//tested:
	//controllerRemoveElement (remove + not found)
	
	med = createMedication("Raceala5", 10, 0, 150);
	controllerAddElement(&con, med);
	free(med);

	med = createMedication("Nurofen", 10, 0, 150);
	controllerAddElement(&con, med);
	free(med);

	med = createMedication("Raceala6", 10, 0, 150);
	controllerAddElement(&con, med);
	free(med);
	
	DynamicRepo* searchInRepo = controllerSearchElement(&con, createMedication("ace", 0, 0, 0));
	Controller newCon = createController(searchInRepo);

	assert(strcmp(newCon.repository->elements[0].name, "Raceala5") == 0);
	assert(strcmp(newCon.repository->elements[1].name, "Raceala6") == 0);
	assert(newCon.repository->length == 2);

	//tested:
	//controllerSearchElement


	destroyDynamicArray(dr);
	destroyDynamicArray(searchInRepo);


	OperationStack* os = con.operationStack;

	for (int i = 0; i < os->length; i++)
	{
		free(os->operations[i]->operation);
		free(os->operations[i]);
	}
	free(os);

	os = newCon.operationStack;

	for (int i = 0; i < os->length; i++)
	{
		free(os->operations[i]->operation);
		free(os->operations[i]->medication);
		free(os->operations[i]);
	}
	free(os);

}