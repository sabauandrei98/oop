#include "KeepCalmAndAdoptAPetQt.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/Qlabel.h>
#include "UI.h"
#include "Tests.h"
#include "FileAdoptionList.h"
#include "CSVAdoptionList.h"
#include "HtmlAdoptionList.h"
#include <iostream>
#include <Windows.h>
#include <crtdbg.h>

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QHBoxLayout>
#include <QFormLayout>


using namespace std;

// "admin" || "user"
#define APPLICATION_MODE "admin"

string getFileType()
{
	string cmd = "";
	while (cmd != "1" && cmd != "2")
	{
		cout << "1. CSV\n";
		cout << "2. HTML\n";
		cout << ">>";

		cin >> cmd;
	}
	return cmd;
}

void StartProgram(int argc, char *argv[])
{
	Repository repository{ "file" };

	FileAdoptionList* file = NULL;
	if (APPLICATION_MODE == "user")
	{
		string cmd = getFileType();
		if (cmd == "1")
		{
			file = new CSVAdoptionList{ "Adoption.csv" };
		}
		else
		{
			file = new HtmlAdoptionList{ "Adoption.html" };
		}
	}

	Controller controller{ repository, file };
	UI ui{ controller, APPLICATION_MODE, argc, argv};
	ui.run();

	delete file;
}

/*
void RunTests()
{
	Tests test;
	test.runTests();
	system("cls");
}
*/

int buttonExample(int argc, char *argv[])
{
	QApplication a(argc, argv);

	// button - example
	QPushButton button("&This is a button.\nPush it!");

	// set tooltip
	button.setToolTip("Look! I'm a button!");
	button.setToolTipDuration(2000);

	// set font
	QFont font("Courier", 50, 10, true);
	button.setFont(font);

	//// set background image
	QIcon icon("Peacock.JPG");
	button.setIcon(icon);
	button.setIconSize(QSize(400, 400));

	button.show();

	return a.exec();
}

int listExample(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QListWidget list;
	new QListWidgetItem("Gone With the Wind", &list);
	new QListWidgetItem("The Three Musketeers", &list);

	// add a QListWidgetItem, with a different font
	QListWidgetItem *item3 = new QListWidgetItem("The Wizard of Oz");
	QFont font("Courier", 20, 10, true);
	item3->setFont(font);
	list.insertItem(0, item3);

	list.show();

	return a.exec();
}

int hBoxLayout(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QWidget wnd{};
	QHBoxLayout hLay{};
	QPushButton btn1{ "Button 1" };
	QPushButton btn2{ "Button 2" };
	QPushButton btn3{ "Button 3" };
	hLay.addWidget(&btn1);
	hLay.addWidget(&btn2);
	hLay.addWidget(&btn3);
	wnd.setLayout(&hLay);
	wnd.show();

	return a.exec();
}

int vBoxLayout(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QWidget *wnd = new QWidget{};
	QVBoxLayout *vLay = new QVBoxLayout{};
	QPushButton *btn1 = new QPushButton{ "Button 1" };
	QPushButton *btn2 = new QPushButton{ "Button 2" };
	QPushButton *btn3 = new QPushButton{ "Button 3" };
	vLay->addWidget(btn1);
	vLay->addWidget(btn2);
	vLay->addWidget(btn3);
	wnd->setLayout(vLay);
	wnd->show();

	return a.exec();
}


int gridLayout(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QGridLayout *gridLayout = new QGridLayout{};

	// add some buttons
	gridLayout->addWidget(new QPushButton("Add"), 0, 0);
	gridLayout->addWidget(new QPushButton("Delete"), 0, 1);
	gridLayout->addWidget(new QPushButton("Update"), 0, 2);
	gridLayout->addWidget(new QPushButton("Filter"), 1, 1);
	gridLayout->addWidget(new QPushButton("Sort"), 2, 0, 1, 3); // row span = 1, column span = 3

	QWidget *wnd = new QWidget{};
	wnd->setLayout(gridLayout);
	wnd->show();

	return a.exec();
}

int multipleLayouts(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QWidget *wnd = new QWidget{};
	QVBoxLayout *vL = new QVBoxLayout{};
	wnd->setLayout(vL);

	//create an information widget, with a QFormLayout
	QWidget *details = new QWidget{};
	QFormLayout *fL = new QFormLayout{};
	details->setLayout(fL);
	QLabel *labelName = new QLabel{ "&Name" };
	QLineEdit *textBoxName = new QLineEdit{};
	labelName->setBuddy(textBoxName);

	fL->addRow(labelName, textBoxName);

	QLabel *labelAge = new QLabel{ "&Age" };
	QLineEdit *textBoxAge = new QLineEdit{};
	labelAge->setBuddy(textBoxAge);
	fL->addRow(labelAge, textBoxAge);

	//add the information widget to the window
	vL->addWidget(details);

	// create a widget with two buttons for two possible actions: Save or Cancel
	// this widget will have a QHBoxLayout
	QWidget* actions = new QWidget{};
	QHBoxLayout* hL = new QHBoxLayout{};
	QPushButton *store = new QPushButton{ "&Save" };
	QPushButton *cancel = new QPushButton{ "&Cancel" };
	hL->addWidget(store);
	hL->addWidget(cancel);
	actions->setLayout(hL);

	// add the actions widget to the window
	vL->addWidget(actions);

	//show window
	wnd->show();

	return a.exec();
}




int main(int argc, char *argv[])
{

	//return buttonExample(argc, argv);
	//return listExample(argc, argv);

	//return hBoxLayout(argc, argv);
	//return vBoxLayout(argc, argv);
	
	//return gridLayout(argc, argv);
	//return multipleLayouts(argc, argv);

	StartProgram(argc, argv);

}
