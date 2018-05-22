#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <qlineedit.h>
#include <qlistwidget.h>
#include "Controller.h"

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(Controller cont, QWidget *parent = 0);


private slots:
	void addEvent();
	void updateEvent();
	void deleteEvent();

private:
	Controller controller;

	QPushButton *addButton;
	QPushButton *updateButton;
	QPushButton *deleteButton;

	QLineEdit *textBoxBreed;
	QLineEdit *textBoxName;
	QLineEdit *textBoxAge;
	QLineEdit *textBoxPhotograph;

	QListWidget *dataBase;

	void refreshDataBaseContainer();
	bool noEmptyFields();

	
};

