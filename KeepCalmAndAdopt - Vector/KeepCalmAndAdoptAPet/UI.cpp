#include "UI.h"
#include "Exceptions.h"
#include "Validator.h"
#include <iostream>
#include <string>

using namespace std;

#define MENU_ITEMS_ADMIN 4
#define MENU_ITEMS_USER 5
#define USER_MODE "user"
#define ADMIN_MODE "admin"
#define EXIT_ID 0

void UI::printUI()
{
	if (this->APPLICATION_MODE == ADMIN_MODE)
	{
		cout << "Admin mode activated ! \n";
		cout << "===========================\n";
		cout << "Keep Calm And Adopt A Pet ! \n";
		cout << "===========================\n";
		cout << "1. Add a dog\n";
		cout << "2. Update a dog\n";
		cout << "3. Delete a dog\n";
		cout << "4. See list of dogs\n";
		cout << "0. Exit \n\n";
	}

	if (this->APPLICATION_MODE == USER_MODE)
	{
		cout << "User mode activated ! \n";
		cout << "===========================\n";
		cout << "Keep Calm And Adopt A Pet ! \n";
		cout << "===========================\n";
		cout << "1. See the list of dogs\n";
		cout << "2. See the dogs of a given breed\n";
		cout << "3. See the adoption list\n";
		cout << "0. Exit \n\n";
	}
}

void UI::run()
{
	this->printUI();
	bool running = true;

	while (running && APPLICATION_MODE == ADMIN_MODE)
	{
		try {

			int cmd = this->getCommand();
			if (cmd == EXIT_ID)
				running = false;
			else
				runCommand(cmd);

			this->ctrl.getRepository().saveDataToFile();
		}
		catch (Exceptions ex)
		{
			ex.printException();
		}
	}

	while (running && APPLICATION_MODE == USER_MODE)
	{
		try {
			int cmd = this->getCommand();
			if (cmd == EXIT_ID)
				running = false;
			else
				runCommand(cmd);
		}
		catch (Exceptions ex)
		{
			ex.printException();
		}
	}

}

int UI::getCommand()
{
	int cmd = -1;
	while (cmd == -1)
	{
		cout << ">> ";
		cin >> cmd;
		if (cmd > MENU_ITEMS_ADMIN || cmd < 0 && this->APPLICATION_MODE == ADMIN_MODE)
			cmd = -1;
		if (cmd > MENU_ITEMS_USER || cmd < 0 && this->APPLICATION_MODE == USER_MODE)
			cmd = -1;
	}
	return cmd;
}

void UI::runCommand(int cmd)
{
	if (this->APPLICATION_MODE == ADMIN_MODE)
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

	if (this->APPLICATION_MODE == USER_MODE)
	{
		if (cmd == 1)
			this->seeTheDogsUI();
		if (cmd == 2)
			this->seeTheDogsOfBreedUI();
		if (cmd == 3)
			this->seeTheAdoptionListUI();

	}
}

//USER MODE

void UI::iterateListOfDogsUI(const DynamicArray<Dog>& list)
{
	cout << "\nFound: " << list.getSize() << "\n";
	cout << "Seeing the dogs, one by one..\n\n";

	vector<Dog> dogs = list.getAllElems();
	for (int i = 0; i < list.getSize(); i++)
	{
		dogs[i].printDog();
		bool correctAnswer = false;
		while (!correctAnswer)
		{
			cout << "Would you like to adopt this dog ? y/n\n";
			string answer;
			cin >> answer;
			if (answer == "y")
			{
				correctAnswer = true;
				this->ctrl.addAdoptionController(dogs[i]);
				this->ctrl.deleteController(dogs[i]);
				cout << "Added to the adoption list !\n";
				return;
			}
			if (answer == "n")
			{
				correctAnswer = true;
			}
		}
	}

}

void UI::seeTheDogsUI()
{
	this->iterateListOfDogsUI(this->ctrl.getRepository().getDynamicArray());
}

void UI::seeTheDogsOfBreedUI()
{
	string breed; 
	int maxAge;

	cout << "Breed: "; cin >> breed;
	cout << "Max age: "; cin >> maxAge;

	Dog specDog{ breed, "", maxAge, "" };

	this->iterateListOfDogsUI(this->ctrl.getSpecificDogs(specDog));
}

void UI::seeTheAdoptionListUI()
{
	this->ctrl.seeTheAdoptionListController();
}

//ADMINISTRATOR MODE

void UI::printDataBase()
{
	this->ctrl.getRepository().getDynamicArray().printArray();
}

Dog UI::readDog(int cmdType) const {

	string breed;
	string name;
	string age;
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

	Validator validator;
	validator.validateDog(breed, name, age, photograph);

	Dog dog(breed, name, stoi(age), photograph);
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
	int initialSize = this->ctrl.getRepository().getDynamicArray().getSize();
	this->ctrl.deleteController(dog);
	if (initialSize == this->ctrl.getRepository().getDynamicArray().getSize())
		cout << "Entity not found!\n";
}

