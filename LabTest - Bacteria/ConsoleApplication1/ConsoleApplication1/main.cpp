// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "UI.h"
#include "Tests.h"

int main()
{
	Tests test;
	test.testAdd();

	Repo repository;
	Controller controller{ repository };
	bacteria bac1{ "bac1", 10, true };
	bacteria bac2{ "bac5", 10, true };
	bacteria bac3{ "bac3", 10, true };
	bacteria bac4{ "bac7", 10, true };
	bacteria bac5{ "bac9", 10, false };
	bacteria bac6{ "bac2", 10, false };
	bacteria bac7{ "bac1", 10, true };
	controller.contAdd(bac1);
	controller.contAdd(bac2);
	controller.contAdd(bac3);
	controller.contAdd(bac4);
	controller.contAdd(bac5);
	controller.contAdd(bac6);
	controller.contAdd(bac7);
	UI ui{ controller };

	ui.run();

	system("pause");
    return 0;
}

