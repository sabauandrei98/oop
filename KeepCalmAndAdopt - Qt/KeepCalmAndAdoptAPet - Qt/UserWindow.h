#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <qlineedit.h>
#include <qlistwidget.h>
#include "Controller.h"
#include <qlabel.h>

namespace Ui {
	class UserWindow;
}

class UserWindow : public QMainWindow
{
	Q_OBJECT

public:
	UserWindow(const Controller& cont, QWidget *parent = 0);


private slots:
	void seeTheListEvent();
	void adoptDogEvent();
	void nextDogEvent();
	void openListEvent();


private:
	Controller controller;

	QPushButton *seeTheListButton;
	QPushButton *updateButton;
	QPushButton *deleteButton;
	QPushButton *nextButton;
	QPushButton *adoptButton;
	QPushButton *openListButton;

	QLabel *currentDog;
	QListWidget *adoptionList;

	int index = -1;
	vector<Dog> currentList;

};

