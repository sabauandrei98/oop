#include "UI.h"
#include "Exceptions.h"
#include "Validator.h"
#include <iostream>
#include <string>
#include "KeepCalmAndAdoptAPetQt.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/Qlabel.h>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QHBoxLayout>
#include <QFormLayout>
#include <Windows.h>

using namespace std;

#define USER_MODE "user"
#define ADMIN_MODE "admin"
#define EXIT_ID 0


int UI::QtAdminMode()
{
	QApplication a(this->ARGC, this->ARGV);


	///MASTER WIDGET
	QWidget *masterWidget = new QWidget{};
	QVBoxLayout *masterLayout = new QVBoxLayout{};
	masterWidget->setLayout(masterLayout);




	///REGISTER WIDGET
	QWidget *addWidget = new QWidget{};
	QFormLayout *addLayout = new QFormLayout{};
	addWidget->setLayout(addLayout);

	//LABEL + TEXT_BOX
	QLabel *labelBreed = new QLabel{ "&Breed" };
	QLineEdit *textBoxBreed = new QLineEdit{};
	labelBreed->setBuddy(textBoxBreed);
	addLayout->addRow(labelBreed, textBoxBreed);

	//LABEL + TEXT_BOX
	QLabel *labelName = new QLabel{ "&Name" };
	QLineEdit *textBoxName = new QLineEdit{};
	labelName->setBuddy(textBoxName);
	addLayout->addRow(labelName, textBoxName);

	//LABEL + TEXT_BOX
	QLabel *labelAge = new QLabel{ "&Age" };
	QLineEdit *textBoxAge = new QLineEdit{};
	labelAge->setBuddy(textBoxAge);
	addLayout->addRow(labelAge, textBoxAge);

	//LABEL + TEXT_BOX
	QLabel *labelPhotograph = new QLabel{ "&Photograph" };
	QLineEdit *textBoxPhotograph = new QLineEdit{};
	labelPhotograph->setBuddy(textBoxPhotograph);
	addLayout->addRow(labelPhotograph, textBoxPhotograph);

	///ADD REGISTER TO MASTER
	masterLayout->addWidget(addWidget);




	///ACTION WIDGET
	QWidget* actionsWidget = new QWidget{};
	QHBoxLayout* actionsLayout = new QHBoxLayout{};
	actionsWidget->setLayout(actionsLayout);

	QPushButton *store = new QPushButton{ "&Save" };
	QPushButton *cancel = new QPushButton{ "&Update" };
	QPushButton *remove = new QPushButton{ "&Delete" };
	actionsLayout->addWidget(store);
	actionsLayout->addWidget(cancel);
	actionsLayout->addWidget(remove);

	///ADD ACTION TO MASTER
	masterLayout->addWidget(actionsWidget);



	QListWidget list;
	vector<Dog> myList = this->ctrl.getRepository().getDynamicArray().getAllElems();

	for (int i = 0; i < myList.size(); i++)
	{
		string item = myList[i].getBreed() + " " + myList[i].getName() + " " + myList[i].getPhotograph();
		char* toChr = new char[item.length()];
		strcpy(toChr, item.c_str());
		new QListWidgetItem(toChr, &list);
	}
	list.show();


	masterWidget->show();
	return a.exec();
}

int UI::QtUserMode()
{
	return 0;
}


void UI::run()
{
	if(APPLICATION_MODE == ADMIN_MODE)
	{
		QtAdminMode();
	}

	if (APPLICATION_MODE == USER_MODE)
	{
		QtUserMode();
	}
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

