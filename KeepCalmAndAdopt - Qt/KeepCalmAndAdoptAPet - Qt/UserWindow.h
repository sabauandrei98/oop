#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <qlineedit.h>
#include <qlistwidget.h>
#include "Controller.h"
#include <qlabel.h>
#include <QtWidgets/QApplication>
#include "PetsTableModel.h"
#include <QSortFilterProxyModel>

namespace Ui {
	class UserWindow;
}

class UserWindow : public QMainWindow
{
	Q_OBJECT

public:
	UserWindow(Controller& cont, QWidget *parent = 0);


private slots:
	void seeTheListEvent();
	void adoptDogEvent();
	void nextDogEvent();
	void openListEvent();
	void filterEvent();


private:
	Controller& controller;

	QPushButton *seeTheListButton;
	QPushButton *updateButton;
	QPushButton *filterButton;
	QPushButton *nextButton;
	QPushButton *adoptButton;
	QPushButton *openListButton;

	QLineEdit *textBoxBreed;
	QLineEdit *textBoxAge;

	QLabel *currentDog;
	QListWidget *adoptionList;

	int index = -1;
	vector<Dog> currentList;

};

