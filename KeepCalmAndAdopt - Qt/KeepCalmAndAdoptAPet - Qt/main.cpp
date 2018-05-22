#include "FileAdoptionList.h"
#include "CSVAdoptionList.h"
#include "HtmlAdoptionList.h"
#include <iostream>
#include <Windows.h>
#include <crtdbg.h>

//qt
#include "MainWindow.h"
#include "UserWindow.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/Qlabel.h>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QHBoxLayout>
#include <QFormLayout>
#include <qdebug.h>
#include <qmessagebox.h>
#include "ExceptionsQt.h"

using namespace std;

string APPLICATION_MODE = "USER";

string getFileType()
{
	QMessageBox msgBox;
	msgBox.setWindowTitle("Saving format");
	msgBox.setText("Which format do you want to save your changes?");
	QPushButton *csv = msgBox.addButton("CSV", QMessageBox::ActionRole);
	QPushButton *html = msgBox.addButton("HTML", QMessageBox::ActionRole);

	msgBox.exec();
	if (msgBox.clickedButton() == csv) {
		return "CSV";
	}
	else if (msgBox.clickedButton() == html) {
		return "HTML";
	}
	return "";
}

int ADMIN_MODE(int argc, char *argv[])
{
	QApplication app(argc, argv);

	Repository repository{ "file" };
	Controller controller{ repository };
	MainWindow mainWindow{ controller };
	mainWindow.showMaximized();

	return app.exec();
}

int USER_MODE(int argc, char *argv[])
{
	QApplication app(argc, argv);

	Repository repository{ "file" };
	FileAdoptionList* file = NULL;

	string cmd = getFileType();
	if (cmd == "CSV")
	{
		file = new CSVAdoptionList{ "Adoption.csv" };
	}
	else
		if (cmd == "HTML")
		{
			file = new HtmlAdoptionList{ "Adoption.html" };
		}
		else
			return 0;

	Controller controller{ repository, file };
	UserWindow userWindow{ controller };
	userWindow.showMaximized();

	return app.exec();
}

int main(int argc, char *argv[])
{
	if (APPLICATION_MODE == "USER")
	{
		USER_MODE(argc, argv);
	}
	if (APPLICATION_MODE == "ADMIN")
	{
		ADMIN_MODE(argc, argv);
	}
}
