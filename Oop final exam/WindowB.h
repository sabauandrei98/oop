#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <qlineedit.h>
#include <qlistwidget.h>
#include "Repository.h"
#include "ExceptionsQt.h"

namespace Ui {
	class WindowB;
}

class WindowB : public QMainWindow, Observer
{
	Q_OBJECT

public:
	WindowB(Repository& repo, QWidget *parent = 0);
	private slots:
	void textChangedEvent(const QString &text);

private:
	Repository& repository;

	QListWidget *dataBase;

	QLineEdit *textBoxSearch;

	void refreshDataBase();
};

