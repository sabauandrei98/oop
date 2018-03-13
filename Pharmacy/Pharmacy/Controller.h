#pragma once

#include "Repository.h"

typedef struct {

	DynamicRepo* repository;

}Controller;

Controller createController(DynamicRepo* repository);

int controllerAddElement(Controller* controller, Medication medication);
int controllerUpdateElement(Controller* controller, Medication medication);
int controllerRemoveElement(Controller* controller, Medication medication);
DynamicRepo* controllerSearchElement(Controller* controller, Medication medication);