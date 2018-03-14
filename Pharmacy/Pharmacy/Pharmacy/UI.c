#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "UI.h"

#define MAX_MENU_INDEX 7
#define EXIT_MENU_INDEX 7

UI createUI(Controller* controller)
{
	UI newUI;
	newUI.controller = controller;
	return newUI;
}


void printMenu()
{
	printf("1. Add a new product or update it's quantity\n");
	printf("2. Update the quantity or the price of a product\n");
	printf("3. Delete a product\n");
	printf("4. Find a product\n");
	printf("7. Exit the program and free the memory.\n");
	printf("\n");
}


int getCommand(char* message)
{
	char cmd[15];
	int successfullCmd = 0;
	printf(message);

	while (successfullCmd == 0)
	{
		scanf("%s", cmd);
		sscanf(cmd, "%d", &successfullCmd);

		if (successfullCmd <= 0)
		{
			printf("Invalid input !!!\n");
			printf(message);
		}
	}

	return successfullCmd;
}

void printMessage(int operation)
{
	if (operation == 1)
		printf("====Success !!!====\n");
	else if (operation == 2)
		printf("====The quantity was updated====\n");
	else if (operation == -1)
		printf("====Product not found !!!====\n");
	else if (operation == -2)
		printf("====Memory error !!!====\n");
	else if (operation == 4)
		printf("====Dealocating memory====\n");
}

void uiAddElement(UI* ui)
{
	printf("Enter the name of the product: ");
	char name[20];
	scanf("%s", name);

	int concentration = getCommand("Enter the concentration of the product: ");
	int quantity = getCommand("Enter the quantity of the product: ");
	int price = getCommand("Enter the price of the product: ");

	Medication medication = createMedication(name, concentration, quantity, price);
	int operation = controllerAddElement(ui->controller, medication);
	
	printMessage(operation);
}

void uiUpdateElement(UI* ui)
{
	printf("Enter oldProductName: ");
	char oldName[20];
	scanf("%s", oldName);

	int oldConcentration = getCommand("Enter the oldProductConcentration: ");
	int newQuantity = getCommand("Enter the newProductQuantity: ");
	int newPrice = getCommand("Enter the newProductprice: ");

	Medication medication = createMedication(oldName, oldConcentration, newQuantity, newPrice);
	int operation = controllerUpdateElement(ui->controller, medication);

	printMessage(operation);
}

void uiRemoveElement(UI* ui)
{
	printf("Enter the name of the product: ");
	char name[20];
	scanf("%s", name);

	int concentration = getCommand("Enter the concentration of the product: ");

	Medication medication = createMedication(name, concentration, 0, 0);
	int operation = controllerRemoveElement(ui->controller, medication);

	printMessage(operation);
}

void uiSearchElement(UI* ui)
{
	printf("Enter the product name or sequence from it: ");
	char name[20];
	scanf("%s", name);

	DynamicRepo* dr;

	if (strcmp(name, "\"") == 0)
	{
		dr = ui->controller->repository;
	}
	else
	{
		Medication medication = createMedication(name, 0, 0, 0);
		dr = controllerSearchElement(ui->controller, medication);
	}

	if (dr->length == 0 || dr == NULL)
	{
		printf("Product not found or memory error !!!\n");
	}
	else
	{
		sortRepository(dr);
		for (int i = 0; i < dr->length; i++)
			medicationToString(dr->elements[i]);
	}

	destroyDynamicRepo(dr);
}



void executeCommand(int cmdIndex, UI* ui)
{
	if (cmdIndex == 1)
		uiAddElement(ui);
	if (cmdIndex == 2)
		uiUpdateElement(ui);
	if (cmdIndex == 3)
		uiRemoveElement(ui);
	if (cmdIndex == 4)
		uiSearchElement(ui);
}

void startUI(UI* ui)
{
	printMenu();

	while (true)
	{
		int cmdIndex = getCommand("Enter menu option: ");

		if (cmdIndex < 0 || cmdIndex > MAX_MENU_INDEX)
			printf("====Invalid input !!!====");
		else
		{
			if (EXIT_MENU_INDEX == cmdIndex)
			{
				destroyDynamicRepo(ui->controller->repository);
				printMessage(4);
				return;
			}

			executeCommand(cmdIndex, ui);
		}

		repositoryToString(ui->controller->repository);
	}
}