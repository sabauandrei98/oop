#include "WindowB.h"
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
#include <qdesktopwidget.h>

WindowB::WindowB(Repository& repo, QWidget *parent) : repository(repo), QMainWindow(parent)
{
	this->repository.addObserver(this);

	QLabel *labelSearch = new QLabel{ this };
	labelSearch->setText("Search: ");
	labelSearch->setGeometry(QRect(QPoint(50, 50), QSize(150, 50)));
	textBoxSearch = new QLineEdit{ labelSearch };

	connect(textBoxSearch, SIGNAL(textChanged(QString)), this, SLOT(textChangedEvent(QString)));

	dataBase = new QListWidget{ this };
	dataBase->setGeometry(QRect(QPoint(300, 50), QSize(300, 800)));

	resize(QDesktopWidget().availableGeometry(this).size() * 0.7);
}

void WindowB::textChangedEvent(const QString &text)
{

	vector<Question> myList = this->repository.getQuestions();
	int best = 0;
	string s = text.toStdString();
	string q = "";
	

	for (int i = 0; i < myList.size(); i++)
	{
		int b = 0;
		for (int j = 0; j < myList[i].getQuestion().size(); j++)
		{
			if (myList[i].getQuestion()[j] == s[j])
				b++;
			else
				break;
		}
		if (b > best)
		{
			best = b;
			q = myList[i].getQuestion();
		}
	}
	dataBase->clear();
	
	if (q == "")
	{
		vector<Question> myList = this->repository.getQuestions();

		for (int i = 0; i < myList.size(); i++)
		{
			string item = to_string(myList[i].getId()) + " | " + myList[i].getQuestion() + " | " + myList[i].getName();
			char* toChr = new char[item.length()];
			strcpy(toChr, item.c_str());
			new QListWidgetItem(toChr, dataBase);
		}
	}
	else
	{
		string item = q;
		char* toChr = new char[item.length()];
		strcpy(toChr, item.c_str());
		new QListWidgetItem(toChr, dataBase);

		vector<Answer> ans = this->repository.getAllAnswersForSpecificQuestion(q);
		
		for (int i = 0; i <= 2 && i < ans.size(); i++)
		{
			string item = ans[i].getName() + " | " + to_string(ans[i].getVotes());
			char* toChr = new char[item.length()];
			strcpy(toChr, item.c_str());
			new QListWidgetItem(toChr, dataBase);
		}
	}
}


void WindowB::refreshDataBase()
{
	this->textChangedEvent(textBoxSearch->text());
}
