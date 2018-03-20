#pragma once

#include "Medication.h"
#include <stdbool.h>

#define OPERATION_STACK_MAX 20

typedef struct {

	Medication* medication;
	char* operation;

} Operation;

Operation* createOperation(Medication* med, char* operation);
void destroyOperation(Operation* op);

typedef struct {

	Operation* operations[20];
	int length;

} OperationStack;

OperationStack* createOperationStack();
void destroyOperationStack(OperationStack* os);
void pushOperation(OperationStack* os, Operation* op);
Operation* popOperation(OperationStack* os);
Operation* getTopOperation(OperationStack* os);
bool isFull(OperationStack* os);
bool isEmpty(OperationStack* os);