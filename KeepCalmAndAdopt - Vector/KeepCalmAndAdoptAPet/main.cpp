#include "UI.h"
#include "Tests.h"
#include "FileAdoptionList.h"
#include "CSVAdoptionList.h"
#include "HtmlAdoptionList.h"
#include <iostream>
#include <Windows.h>
#include <crtdbg.h>

using namespace std;

// "admin" || "user"
#define APPLICATION_MODE "user"

string getFileType()
{
	string cmd = "";
	while (cmd != "1" && cmd != "2")
	{
		cout << "1. CSV\n";
		cout << "2. HTML\n";
		cout << ">>";

		cin >> cmd;
	}
	return cmd;
}

void StartProgram()
{
	Repository repository{ "file" };

	FileAdoptionList* file = NULL;
	if (APPLICATION_MODE == "user")
	{
		string cmd = getFileType();
		if (cmd == "1")
		{
			file = new CSVAdoptionList{ "Adoption.csv" };
		}
		else
		{
			file = new HtmlAdoptionList{ "Adoption.html" };
		}
	}
		
	Controller controller{ repository, file };
	UI ui{ controller, APPLICATION_MODE };
	ui.run();

	delete file;
}

void RunTests()
{
	Tests test;
	test.runTests();
	system("cls");
}

int main()
{
	RunTests();
	StartProgram();
	system("pause");

	_CrtDumpMemoryLeaks();
    return 0;
}

