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
	MainWindow(Controller& cont, QWidget *parent = 0);


private slots:
	void addEvent();
	void updateEvent();
	void deleteEvent();
	void undoEvent();
	void redoEvent();
	void comboChanged(const QString &text);

private:
	Controller& controller;

	QPushButton *addButton;
	QPushButton *updateButton;
	QPushButton *deleteButton;
	QPushButton *undoButton;
	QPushButton *redoButton;

	QComboBox *comboBox;

	QLineEdit *textBoxBreed;
	QLineEdit *textBoxName;
	QLineEdit *textBoxAge;
	QLineEdit *textBoxPhotograph;

	QListWidget *dataBase;

	void refreshDataBaseContainer(int option = 0);
	bool noEmptyFields();

	
};

