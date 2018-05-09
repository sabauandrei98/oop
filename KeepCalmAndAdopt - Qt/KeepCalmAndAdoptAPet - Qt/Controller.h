#pragma once

#include "Repository.h"
#include "FileAdoptionList.h"

class Controller
{
private:
	Repository repository;
	Repository adoptionRepo;
	FileAdoptionList* fileAdoption;

public:
	Controller(const Repository& r) : repository(r) {}
	Controller(const Repository& r, FileAdoptionList* adoption) : repository(r), fileAdoption(adoption) {}

	/// <summary>
	/// Adds an element into controller
	/// </summary>
	/// <param name="d">The element which will be added</param>
	void addController(const Dog& d);

	/// <summary>
	/// Updates an element into controller
	/// </summary>
	/// <param name="oldDog">The old element</param>
	/// <param name="newDog">The new element</param>
	void updateController(const Dog& oldDog, const Dog& newDog);

	/// <summary>
	/// Deletes an element from controller
	/// </summary>
	/// <param name="d">The element to be deleted</param>
	void deleteController(const Dog& d);

	/// <summary>
	/// Adds an element into controller to adoption list
	/// </summary>
	/// <param name="d">The element to be added</param>
	void addAdoptionController(const Dog& d);

	/// <summary>
	/// Gets the list of specific elements
	/// </summary>
	/// <param name="d">The specifications for the filter</param>
	/// <returns>Returns a list of filtered items</returns>
	DynamicArray<Dog> getSpecificDogs(const Dog& d);
	
	/// <summary>
	/// Gets repository
	/// </summary>
	Repository getRepository() const { return repository; };

	/// <summary>
	/// Gets the adoption repository
	/// </summary>
	Repository getAdoptionRepository() const { return adoptionRepo; };

	void seeTheAdoptionListController();

};

