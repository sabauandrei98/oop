#pragma once

#include "Repository.h"

typedef struct {

	DynamicRepo* repository;

}Controller;

Controller createController(DynamicRepo* repository);

int controllerAddElement(Controller* controller, Medication medication);