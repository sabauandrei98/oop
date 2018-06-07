#include "MainWindow.h"
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
#include <qcombobox.h>

MainWindow::MainWindow(Controller& cont, QWidget *parent): controller(cont), QMainWindow(parent)
{
	QLabel *labelBreed = new QLabel{ this };
	labelBreed->setText("Breed: ");
	labelBreed->setGeometry(QRect(QPoint(50, 50), QSize(150, 50)));
	textBoxBreed = new QLineEdit{labelBreed};
	

	QLabel *labelName = new QLabel{ this };
	labelName->setText("Name: ");
	labelName->setGeometry(QRect(QPoint(50, 100), QSize(150, 50)));
	textBoxName = new QLineEdit{labelName};


	QLabel *labelAge = new QLabel{ this };
	labelAge->setText("Age: ");
	labelAge->setGeometry(QRect(QPoint(50, 150), QSize(150, 50)));
	textBoxAge = new QLineEdit{labelAge};


	QLabel *labelPhotograph = new QLabel{ this };
	labelPhotograph->setText("Photograph: ");
	labelPhotograph->setGeometry(QRect(QPoint(50, 200), QSize(150, 50)));
	textBoxPhotograph = new QLineEdit{labelPhotograph};


	addButton = new QPushButton{ "Add",this };
	updateButton = new QPushButton{ "Update",this };
	deleteButton = new QPushButton{ "Delete",this };
	undoButton = new QPushButton{ "Undo",this };
	redoButton = new QPushButton{ "Redo",this };

	addButton->setGeometry(QRect(QPoint(50, 300), QSize(200, 50)));
	updateButton->setGeometry(QRect(QPoint(50, 350), QSize(200, 50)));
	deleteButton->setGeometry(QRect(QPoint(50, 400), QSize(200, 50)));
	undoButton->setGeometry(QRect(QPoint(50, 500), QSize(200, 50)));
	redoButton->setGeometry(QRect(QPoint(50, 550), QSize(200, 50)));

	comboBox = new QComboBox{ this };
	comboBox->setGeometry(QRect(QPoint(300, 20), QSize(250, 25)));
	comboBox->addItem("Detailed");
	comboBox->addItem("Short");

	connect(addButton, SIGNAL(released()), this, SLOT(addEvent()));
	connect(updateButton, SIGNAL(released()), this, SLOT(updateEvent()));
	connect(deleteButton, SIGNAL(released()), this, SLOT(deleteEvent()));
	connect(undoButton, SIGNAL(released()), this, SLOT(undoEvent()));
	connect(redoButton, SIGNAL(released()), this, SLOT(redoEvent()));
	connect(comboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(comboChanged(QString)));

	dataBase = new QListWidget{ this };
	dataBase->setGeometry(QRect(QPoint(300, 50), QSize(300, 800)));

	refreshDataBaseContainer();
}

void MainWindow::undoEvent()
{
	ExceptionsQt ex{ "Exec undo !" };
	this->controller.undo();
	this->refreshDataBaseContainer();
}

void MainWindow::redoEvent()
{
	ExceptionsQt ex{ "Exec redo !" };
	this->controller.redo();
	this->refreshDataBaseContainer();
}


void MainWindow::comboChanged(const QString &text)
{
	if (text == "Detailed")
		refreshDataBaseContainer(0);
	if (text == "Short")
		refreshDataBaseContainer(1);
}


void MainWindow::refreshDataBaseContainer(int option)
{
	dataBase->clear();

	vector<Dog> myList = this->controller.getRepository().getDynamicArray().getAllElems();

	for (int i = 0; i < myList.size(); i++)
	{
		string item = "";
		if (option == 0)
			item = myList[i].getBreed() + ",   " + myList[i].getName() + ",   " + to_string(myList[i].getAge()) + ",   " + myList[i].getPhotograph();
		else
			item = myList[i].getBreed();

		char* toChr = new char[item.length()];
		strcpy(toChr, item.c_str());
		new QListWidgetItem(toChr, dataBase);
	}

}

bool MainWindow::noEmptyFields()
{
	if (textBoxBreed->text() == "")
		return false;
	if (textBoxAge->text() == "")
		return false;
	if (textBoxName->text() == "")
		return false;
	if (textBoxPhotograph->text() == "")
		return false;

	return true;
}

void MainWindow::addEvent()
{
	if (noEmptyFields())
	{
		Dog dog{ textBoxBreed->text().toStdString(), textBoxName->text().toStdString(), textBoxAge->text().toInt(), textBoxPhotograph->text().toStdString() };
		int returnType = controller.addController(dog);
		if (returnType == 0)
		{
			this->refreshDataBaseContainer();
			ExceptionsQt ex{ "Element added !" };
		}
		else
			ExceptionsQt ex{ "Already in the dataBase !" };
	}
	else
		ExceptionsQt ex{ "Empty fields !" };	
}

void MainWindow::updateEvent()
{
	if (dataBase->currentRow() != -1 && noEmptyFields())
	{
		Dog dog{ textBoxBreed->text().toStdString(), textBoxName->text().toStdString(), textBoxAge->text().toInt(), textBoxPhotograph->text().toStdString() };
		controller.updateController(dataBase->currentRow(), dog);
		this->refreshDataBaseContainer();
		ExceptionsQt ex{ "Element updated !" };
	}
	else
		ExceptionsQt ex{ "No selected row ! \nOR\nEmpty fields!" };
}

void MainWindow::deleteEvent()
{
	if (dataBase->currentRow() != -1)
	{
		controller.deleteController(dataBase->currentRow());
		this->refreshDataBaseContainer();
		ExceptionsQt ex{ "Element deleted !" };
	}
	else
		ExceptionsQt ex{ "No selected row !" };
}