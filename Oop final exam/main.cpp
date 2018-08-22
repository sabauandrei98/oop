#include <QtWidgets/QApplication>
#include "Repository.h"
#include "WindowB.h"
#include "WindowA.h"
#include "Tests.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);


		//Tests t;
		//t.testAddQuestion();
		//t.testGetAnswersForGivenQuestion();
	

		Repository rep{ "users.txt", "questions.txt", "answers.txt" };
		vector<WindowB*> windowListB;
		vector<WindowA*> windowListA;
		windowListB.push_back(new WindowB{ rep });
		windowListB[0]->show();

		int count = 0;
		for (auto x : rep.getUsers())
		{
			windowListA.push_back(new WindowA{ rep });
			windowListA[count]->show();
			windowListA[count]->setWindowTitle(QString::fromStdString(x.getName()));
			count++;
		}
	


	return a.exec();
}
