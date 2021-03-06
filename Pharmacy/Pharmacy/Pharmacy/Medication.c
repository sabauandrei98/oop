#include "Medication.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

Medication* createMedication(char name[], double concentration, double quantity, double price)
{
	Medication* med = (Medication*)malloc(sizeof(Medication));
	strcpy(med->name, name);
	med->concentration = concentration;
	med->quantity = quantity;
	med->price = price;

	return med;
}

void destroyMedication(Medication* med)
{
	free(med);
}

void printMedication(Medication* med)
{
	printf("Name: %s, Concentration: %d, Quantity: %d, Price: %d \n",
		med->name, med->concentration, med->quantity, med->price);
}

void medicationTest()
{
	Medication* med = createMedication("Febra", 20, 30, 40);
	assert(strcmp(med->name, "Febra") == 0);
	assert(med->concentration == 20);
	assert(med->quantity == 30);
	assert(med->price == 40);

	free(med);
}