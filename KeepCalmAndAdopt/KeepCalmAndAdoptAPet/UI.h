#pragma once
#include "Controller.h"

class UI
{
private:
	Controller ctrl;
	string APPLICATION_MODE;

public:
	UI(const Controller& c, string mode) : ctrl(c), APPLICATION_MODE(mode) {}
	void run();

private:

	//general
	/// <summary>
	/// Print the menu for user/admin
	/// </summary>
	void printUI();

	/// <summary>
	/// Get the user input
	/// </summary>
	/// <returns>Returns an integer, the command index</returns>
	int getCommand();

	/// <summary>
	/// For a given index, run a specific command
	/// </summary>
	/// <param name="cmd">The index of the command to be executed</param>
	void runCommand(int cmd);

	/// <summary>
	/// Read the info for a dog entity
	/// </summary>
	/// <param name="cmdType">Display different info acording to the executed command</param>
	/// <returns>Returns a dog entity</returns>
	Dog readDog(int cmdType) const;

	/// <summary>
	/// Prints the list of dogs
	/// </summary>
	void printDataBase();

	//admin
	/// <summary>
	/// Adds an element into controller
	/// </summary>
	/// <param name="d">The element which will be added</param>
	void addUI(const Dog& d);

	/// <summary>
	/// Updates an element into controller
	/// </summary>
	/// <param name="oldDog">The old element</param>
	/// <param name="newDog">The new element</param>
	void updateUI(const Dog& oldDog, const Dog& newDog);

	/// <summary>
	/// Deletes an element from controller
	/// </summary>
	/// <param name="d">The element to be deleted</param>
	void deleteUI(const Dog& d);


	//user
	/// <summary>
	/// Sets the UI to display the dataBases for eventual adoptions
	/// </summary>
	void seeTheDogsUI();

	/// <summary>
	/// Gets a list of specific dogs and then sets the UI to display the dataBases for eventual adoptions
	/// </summary>
	void seeTheDogsOfBreedUI();

	/// <summary>
	/// Prints the adoption list
	/// </summary>
	void seeTheAdoptionListUI();

	/// <summary>
	/// Iterate the dogs list and allows the user to decide to adopt a dog or not
	/// </summary>
	/// <param name="list">Dynamic Array representing the list of dogs</param>
	void iterateListOfDogsUI(const DynamicArray<Dog>& list);

};

