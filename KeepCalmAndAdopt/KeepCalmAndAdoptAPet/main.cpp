// KeepCalmAndAdoptAPet.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <Windows.h>
#include "UI.h"
using namespace std;

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
}

void Tests()
{
	repositoryTest();
	DynamicArrayTest();
}

int main()
{

	Tests();

	Repository repository;
	
	//Initial data
	InitialDataBase(repository);

	Controller controller{ repository };
	UI ui{ controller };
	

	ui.run();

	system("pause");
    return 0;
}

