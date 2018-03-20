#include "OperationStack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

Operation* createOperation(Medication* med, char* operation)
{
	Operation* op = (Operation*)malloc(sizeof(Operation));

	op->medication = med;
	op->operation = (char*)malloc(sizeof(char) * (strlen(operation) + 1));
	strcpy(op->operation, operation);

	return op;
}

void destroyOperation(Operation* op)
{
	free(op->medication);
	free(op->operation);
	free(op);
}


OperationStack* createOperationStack()
{
	OperationStack* os = (OperationStack*)malloc(sizeof(OperationStack));
	os->length = 0;

	return os;
}

void destroyOperationStack(OperationStack* os)
{
	for (int i = 0; i < os->length; i++)
	{
		free(os->operations[i]->operation);
		free(os->operations[i]->medication);
		free(os->operations[i]);
	}

	free(os);
}

void pushOperation(OperationStack* os, Operation* op)
{
	if (isFull(os))
		return;

	os->operations[os->length] = op;
	os->length++;
}

Operation* popOperation(OperationStack* os)
{
	if (isEmpty(os))
		return;

	os->length--;
	return os->operations[os->length];
}

Operation* getTopOperation(OperationStack* os)
{
	if (isEmpty(os))
		return;

	return os->operations[os->length - 1];
}

bool isFull(OperationStack* os)
{
	return os->length == OPERATION_STACK_MAX;
}

bool isEmpty(OperationStack* os)
{
	return os->length == 0;
}