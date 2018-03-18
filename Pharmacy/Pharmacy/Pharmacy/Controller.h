#pragma once

#include "Repository.h"

typedef struct {

	DynamicRepo* repository;

}Controller;

//Controller

/// <summary>
/// Creates a Controller attached to a specific Repository
/// </summary>
/// <param name="repository">Pointer to a repository which the new Controller will be attached</param>
/// <returns>A new controller</returns>
Controller createController(DynamicRepo* repository);


//Functionalities

/// <summary>
/// Adds an element to a specific Repo of this Controller or updates the element values if necessary.
/// </summary>
/// <param name="controller">Pointer to the controller on which the operation will be executed</param>
/// <param name="medication">The Medication structure which will be added to the Controller</param>
/// <returns>-2 for a memory problem, 1 for success, 2 for update</returns>
int controllerAddElement(Controller* controller, Medication medication);

/// <summary>
/// Updates the value of an element in a specific Repo of this Controller
/// </summary>
/// <param name="controller">Pointer to the controller on which the operation will be executed</param>
/// <param name="medication">The Medication structure which will be updated in the Controller</param>
/// <returns>-2 for a memory problem, 1 for success, -1 element not found</returns>
int controllerUpdateElement(Controller* controller, Medication medication);

/// <summary>
/// Removes an element from a specific Repo of this Controller.
/// </summary>
/// <param name="controller">Pointer to the controller on which the operation will be executed</param>
/// <param name="medication">The Medication structure which will be removed from the Controller</param>
/// <returns>-2 for a memory problem, 1 for success, -1 element not found</returns>
int controllerRemoveElement(Controller* controller, Medication medication);

/// <summary>
/// Searches for all elements which contain a specific pattern in their name into a specific Repo of this Controller.
/// </summary>
/// <param name="controller">Pointer to the controller on which the operation will be executed</param>
/// <param name="medication">The Medication structure which the function is looking for</param>
/// <returns>NULL for a memory problem, otherwise, a pointer to a DynamicRepo containing the elements </returns>
DynamicRepo* controllerSearchElement(Controller* controller, Medication medication);

DynamicRepo* controllerShortSupply(Controller* controller, int quantity);


//Tests

void controllerTest();