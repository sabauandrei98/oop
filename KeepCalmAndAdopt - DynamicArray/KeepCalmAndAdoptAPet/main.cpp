#include "UI.h"
#include "Tests.h"
#include <iostream>
#include <Windows.h>
#include <crtdbg.h>

using namespace std;

// "admin" || "user"
#define APPLICATION_MODE "admin"

void InitialDataBase(Repository& repo)
{
	Dog dog1("Breed1", "Name1", 10, "www.google.ro");
	repo.addRepository(dog1);

	Dog dog2("Breed2", "Name2", 20, "www.google.ro");
	repo.addRepository(dog2);

	Dog dog3("Breed3", "Name3", 30, "www.google.ro");
	repo.addRepository(dog3);

	Dog dog4("Breed4", "Name4", 40, "www.google.ro");
	repo.addRepository(dog4);

	Dog dog5("Breed4", "Name5", 40, "www.google.ro");
	repo.addRepository(dog5);

	Dog dog6("Breed4", "Name6", 40, "www.google.ro");
	repo.addRepository(dog6);

	Dog dog7("Breed", "Name4", 5, "www.google.ro");
	repo.addRepository(dog7);

	Dog dog8("Breed", "Name2", 4, "www.google.ro");
	repo.addRepository(dog8);

	Dog dog9("Breed", "Name2", 3, "www.google.ro");
	repo.addRepository(dog9);

	Dog dog10("Breed", "Name1", 2, "www.google.ro");
	repo.addRepository(dog10);
}


void StartProgram()
{
	Repository repository;

	////Initial data
	InitialDataBase(repository);

	Controller controller{ repository };
	UI ui{ controller, APPLICATION_MODE };
	ui.run();
}

void RunTests()
{
	/////Program tests
	Tests test;
	test.runTests();
	system("cls");
}

int main()
{
	RunTests();
	//StartProgram();
	system("pause");

	_CrtDumpMemoryLeaks();
    return 0;
}

