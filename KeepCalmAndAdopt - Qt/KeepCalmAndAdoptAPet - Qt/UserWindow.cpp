#include "UserWindow.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/Qlabel.h>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QHBoxLayout>
#include <QFormLayout>
#include <Windows.h>
#include <QCoreApplication>
#include <QMainWindow>
#include <QPushButton>
#include <qmessagebox.h>
#include <QCoreApplication>
#include "ExceptionsQt.h"
#include "PetsTableWidget.h"

UserWindow::UserWindow(Controller& cont, QWidget *parent) : controller(cont), QMainWindow(parent)
{
	
	currentDog = new QLabel{ this };
	currentDog->setGeometry(QRect(QPoint(50, 50), QSize(500, 50)));
	QFont f("Arial", 15, QFont::Bold);
	currentDog->setFont(f);


	adoptButton = new QPushButton{ "Adopt",this };
	nextButton = new QPushButton{ "Next",this };
	seeTheListButton = new QPushButton{ "Adopt a dog",this };
	openListButton = new QPushButton{ "See the list",this };
	filterButton = new QPushButton{ "Filter",this };

	adoptButton->setGeometry(QRect(QPoint(250, 150), QSize(200, 50)));
	nextButton->setGeometry(QRect(QPoint(50, 150), QSize(200, 50)));
	seeTheListButton->setGeometry(QRect(QPoint(50, 300), QSize(200, 50)));
	openListButton->setGeometry(QRect(QPoint(50, 350), QSize(200, 50)));
	filterButton->setGeometry(QRect(QPoint(50, 550), QSize(200, 50)));

	QLabel *labelBreed = new QLabel{ this };
	labelBreed->setText("Breed: ");
	labelBreed->setGeometry(QRect(QPoint(50, 450), QSize(150, 50)));
	textBoxBreed = new QLineEdit{ labelBreed };

	QLabel *labelAge = new QLabel{ this };
	labelAge->setText("Age: ");
	labelAge->setGeometry(QRect(QPoint(50, 500), QSize(150, 50)));
	textBoxAge = new QLineEdit{ labelAge };

	connect(seeTheListButton, SIGNAL(released()), this, SLOT(seeTheListEvent()));
	connect(nextButton, SIGNAL(released()), this, SLOT(nextDogEvent()));
	connect(adoptButton, SIGNAL(released()), this, SLOT(adoptDogEvent()));
	connect(openListButton, SIGNAL(released()), this, SLOT(openListEvent()));
	connect(filterButton, SIGNAL(released()), this, SLOT(filterEvent()));

	adoptionList = new QListWidget{ this };
	adoptionList->setGeometry(QRect(QPoint(600, 50), QSize(300, 800)));
}


void UserWindow::seeTheListEvent()
{
	this->currentList = this->controller.getRepository().getDynamicArray().getAllElems();
	this->index = 0;
	currentDog->setText(QString::fromStdString(this->currentList[this->index].toString()));
}

void UserWindow::adoptDogEvent()
{
	if (this->index == -1)
	{
		ExceptionsQt ex{ "No list to iterate !" };
		return;
	}

	if (currentList.size() == 0)
	{
		ExceptionsQt ex{ "No dogs to adopt !" };
		return;
	}

	this->controller.addAdoptionController(this->currentList[this->index]);
	this->controller.deleteController(controller.getRepository().getElementPosition(this->currentList[this->index]));

	string item = this->currentList[this->index].getBreed() + ",   " + this->currentList[this->index].getName() + ",   " 
		+ to_string(this->currentList[this->index].getAge()) + ",   " + this->currentList[this->index].getPhotograph();

	char* toChr = new char[item.length()];
	strcpy(toChr, item.c_str());
	new QListWidgetItem(toChr, adoptionList);

	this->index = 0;
	this->currentList = this->controller.getRepository().getDynamicArray().getAllElems();
	this->nextDogEvent();

	ExceptionsQt ex{ "Dog has been adopted !" };
}

void UserWindow::openListEvent()
{
	this->controller.seeTheAdoptionListController();
}
void UserWindow::filterEvent()
{
	if (textBoxAge->text() == "" || textBoxBreed->text() == "")
	{
		ExceptionsQt ex{ "Empty fields !" };
	}
	else
	{
		Dog dog{ textBoxBreed->text().toStdString(), "", stoi(textBoxAge->text().toStdString()), "" };
		this->currentList = controller.getSpecificDogs(dog).getAllElems();
		this->index = 0;
		currentDog->setText(QString::fromStdString(this->currentList[this->index].toString()));
	}
}

void UserWindow::nextDogEvent()
{
	if (currentList.size() == 0)
	{
		ExceptionsQt ex{ "No list !" };
		return;
	}

	this->index++;
	if (this->index == this->currentList.size())
		this->index = 0;
	currentDog->setText(QString::fromStdString(this->currentList[this->index].toString()));
}

