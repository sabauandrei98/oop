#include "Medication.h"
#include <stdio.h>
#include <string.h>

Medication createMedication(char name[], double concentration, double quantity, double price)
{
	Medication med;
	strcpy(med.name, name);
	med.concentration = concentration;
	med.quantity = quantity;
	med.price = price;

	return med;
}


void medicationToString(Medication med)
{
	printf("Name: %s, Concentration: %d, Quantity: %d, Price: %d \n",
		med.name, med.concentration, med.quantity, med.price);
}