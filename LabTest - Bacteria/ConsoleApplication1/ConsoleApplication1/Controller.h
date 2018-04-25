#pragma once
#include "Repo.h"
class Controller
{
private:
	Repo repo;
public:
	Controller(Repo repository) : repo(repository) {}

	//Function that ads or updates an bacteria in the database
	//params: bac - type of bacteria which is the element to be added in the list
	//return: 0 - if the number of bacterias was updated
	//		  1 - if a new bacteria was added to the list
	int contAdd(bacteria bac);

	vector<bacteria> getList() { return this->repo.getList(); };
	vector<bacteria> sortByType(vector<bacteria> list);

	//Function that grows or cuts the population of bacterias
	//params: id - the number that represents the type of the environment
	//return: void
	void environmentChange(int id);

	~Controller();
};

