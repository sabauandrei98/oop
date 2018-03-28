#include "UI.h"
#include <iostream>
#include <string>

using namespace std;

#define MENU_ITEMS 4
#define EXIT_ID 0

void UI::run()
{
	this->printUI();

	bool running = true;
	while (running)
	{
		int cmd = this->getCommand();
		if (cmd == EXIT_ID)
			running = false;
		else
			runCommand(cmd);
	}
}

void UI::runCommand(int cmd)
{
	if (cmd == 1)
		this->addUI(this->readDog(1));
	if (cmd == 2)
	{
		Dog oldDog = this->readDog(2);
		Dog newDog = this->readDog(3);
		this->updateUI(oldDog, newDog);
	}
	if (cmd == 3)
		this->deleteUI(this->readDog(1));
	if (cmd == 4)
		this->printDataBase();
}

int UI::getCommand()
{
	int cmd = -1;
	while (cmd == -1)
	{
		cout << ">> ";
		cin >> cmd;
		if (cmd > MENU_ITEMS || cmd < 0)
			cmd = -1;
	}
	return cmd;
}

void UI::printUI()
{
	cout << "===========================\n";
	cout << "Keep Calm And Adopt A Pet ! \n";
	cout << "===========================\n";
	cout << "1. Add a dog\n";
	cout << "2. Update a dog\n";
	cout << "3. Delete a dog\n";
	cout << "4. See list of dogs\n";
	cout << "0. Exit \n\n";
}

void UI::printDataBase()
{
	this->ctrl.getRepository().getDynamicArray().printArray();
}

Dog UI::readDog(int cmdType) const {

	string breed;
	string name;
	int age;
	string photograph;

	if (cmdType == 1)
	{
		cout << "Breed: "; cin >> breed;
		cout << "Name: "; cin >> name;
		cout << "Age: "; cin >> age;
		cout << "Photograph: "; cin >> photograph;
	}

	if (cmdType == 2)
	{
		cout << "oldBreed: "; cin >> breed;
		cout << "oldName: "; cin >> name;
		cout << "oldAge: "; cin >> age;
		cout << "oldPhotograph: "; cin >> photograph;
	}

	if (cmdType == 3)
	{
		cout << "newBreed: "; cin >> breed;
		cout << "newName: "; cin >> name;
		cout << "newAge: "; cin >> age;
		cout << "newPhotograph: "; cin >> photograph;
	}

	Dog dog(breed, name, age, photograph);
	return dog;
}

void UI::addUI(const Dog& dog)
{
	this->ctrl.addController(dog);
}

void UI::updateUI(const Dog& oldDog, const Dog& newDog)
{
	this->ctrl.updateController(oldDog, newDog);
}

void UI::deleteUI(const Dog& dog)
{
	this->ctrl.deleteController(dog);
}