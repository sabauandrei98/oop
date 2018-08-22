#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <qlineedit.h>
#include <qlistwidget.h>
#include "Repository.h"

namespace Ui {
	class WindowA;
}

class WindowA : public QMainWindow, Observer
{
	Q_OBJECT

public:
	WindowA(Repository& repo, QWidget *parent = 0);
	private slots:
	void addEvent();
	void onListItemClicked(QListWidgetItem* item);

private:
	Repository & repository;

	QPushButton *addButton;

	QLineEdit *textBoxQuestion;

	QListWidget *dataBase;
	QListWidget *dataBaseDetails;

	void refreshDataBase();
};

