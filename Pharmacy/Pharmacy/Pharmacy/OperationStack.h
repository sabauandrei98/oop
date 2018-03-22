#pragma once

#include "Medication.h"
#include <stdbool.h>

#define OPERATION_STACK_MAX 20

typedef struct {

	Medication* medication;
	char* operation;

} Operation;

/// <summary>
/// Creates an operation type by a given Medication and operation
/// </summary>
/// <param name="med">Pointer to the coresponding Medication</param>
/// <param name="operation">Pointer to the coresponding Operation</param>
/// <returns>Return a pointer to the allcated Operation zone in the memory</returns>
Operation* createOperation(Medication* med, char* operation);

/// <summary>
/// Destroys an operation type
/// </summary>
/// <param name="operation">Pointer to the coresponding Operation</param>
void destroyOperation(Operation* op);

typedef struct {

	Operation* operations[20];
	int length;

} OperationStack;

/// <summary>
/// Creates an operation stack type 
/// </summary>
OperationStack* createOperationStack();

/// <summary>
/// Destroys an operation stack type
/// </summary>
/// <param name="os">Pointer to the coresponding OperationStack</param>
void destroyOperationStack(OperationStack* os);

/// <summary>
/// Pushes an operation into the Operation stack
/// </summary>
/// <param name="operation">Pointer to the coresponding Operation</param>
/// <param name="os">Pointer to the coresponding Operation stack</param>
void pushOperation(OperationStack* os, Operation* op);

/// <summary>
/// Gets the top element then erase it from stack
/// </summary>
/// <param name="os">Pointer to the coresponding Operation stack</param>
/// <returns>Return a pointer to the allcated Operation zone in the memory</returns>
Operation* popOperation(OperationStack* os);

/// <summary>
/// Gets the top element from the Operation Stack
/// </summary>
/// <param name="os">Pointer to the coresponding Operation stack</param>
/// <returns>Return a pointer to the allcated Operation zone in the memory</returns>
Operation* getTopOperation(OperationStack* os);

/// <summary>
/// Checks if the Operation stack is full
/// </summary>
/// <returns>True, if full, false otherwise</returns>
bool isFull(OperationStack* os);

/// <summary>
/// Checks if the Operation stack is empty
/// </summary>
/// <returns>True, if empty, false otherwise</returns>
bool isEmpty(OperationStack* os);

//Tests
void operationsTest();