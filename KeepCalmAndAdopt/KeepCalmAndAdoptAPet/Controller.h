#pragma once

#include "Repository.h"

class Controller
{
private:
	Repository repository;

public:
	Controller(const Repository& r) : repository(r) {}

	void addController(const Dog& d);
	void updateController(const Dog& oldDog, const Dog& newDog);
	void deleteController(const Dog& d);
	
	Repository getRepository() const { return repository; };
	
};

