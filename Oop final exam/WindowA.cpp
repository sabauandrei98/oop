#include "WindowA.h"
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

WindowA::WindowA(Repository& repo, QWidget *parent) : repository(repo), QMainWindow(parent)
{
	this->repository.addObserver(this);

	QLabel *labelQuestion = new QLabel{ this };
	labelQuestion->setText("Question: ");
	labelQuestion->setGeometry(QRect(QPoint(50, 200), QSize(150, 50)));
	textBoxQuestion = new QLineEdit{ labelQuestion };

	addButton = new QPushButton{ "Add question",this };
	addButton->setGeometry(QRect(QPoint(50, 100), QSize(200, 50)));
	connect(addButton, SIGNAL(released()), this, SLOT(addEvent()));

	dataBase = new QListWidget{ this };
	dataBase->setGeometry(QRect(QPoint(300, 50), QSize(300, 800)));

	dataBaseDetails = new QListWidget{ this };
	dataBaseDetails->setGeometry(QRect(QPoint(600, 50), QSize(300, 800)));
	connect(dataBase, SIGNAL(itemClicked(QListWidgetItem*)),
		this, SLOT(onListItemClicked(QListWidgetItem*)));

	refreshDataBase();
	resize(QDesktopWidget().availableGeometry(this).size() * 0.65);
}

void WindowA::onListItemClicked(QListWidgetItem* item)
{

	string str = item->text().toStdString();
	char split_char = '|';

	istringstream split(str);
	vector<string> tokens;
	for (string each; getline(split, each, split_char); tokens.push_back(each));
	
	dataBaseDetails->clear();
	vector<Answer> ans = this->repository.getAnswers();

	for(int i = 0; i < ans.size(); i++)
		if (ans[i].getQuestion() == tokens[1])
		{
			string item = to_string(ans[i].getId()) + "|" + ans[i].getQuestion() + "|" + ans[i].getName() + "|" + ans[i].getAnswer() + "|" + to_string(ans[i].getVotes());
			char* toChr = new char[item.length()];
			strcpy(toChr, item.c_str());
			auto t = new QListWidgetItem(toChr, dataBaseDetails);
			if(this->windowTitle().toStdString() == ans[i].getName())
				t->setForeground(Qt::yellow);
		}

}

void WindowA::refreshDataBase()
{
	dataBase->clear();

	vector<Question> myList = this->repository.getQuestions();
	for (int i = 0; i < myList.size(); i++)
		for (int j = i + 1; j < myList.size(); j++)
			if (this->repository.getQuestionAnswers(myList[i].getQuestion()) < this->repository.getQuestionAnswers(myList[j].getQuestion()))
				swap(myList[i], myList[j]);

	for (int i = 0; i < myList.size(); i++) 
	{
		string item = to_string(myList[i].getId()) + "|" + myList[i].getQuestion() + "|" + myList[i].getName();
		char* toChr = new char[item.length()];
		strcpy(toChr, item.c_str());
		new QListWidgetItem(toChr, dataBase);
	}

}

//Function that ads a question to the list
//in:the textBoxQuestion text
//out: the updated list with the question added
void WindowA::addEvent()
{
	
	if (this->textBoxQuestion->text() != "")
	{
		int sz = this->repository.getQuestions().size();
		Question q{ sz, this->textBoxQuestion->text().toStdString(), this->windowTitle().toStdString() };
		this->repository.addQuestion(q);
		this->repository.notify();
	}
	else
		ExceptionsQt ex{ "Empty field !" };
}
