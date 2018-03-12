#pragma once

typedef struct {

	char name[20];
	int concentration;
	int quantity;
	int price;

} Medication;

Medication createMedication(char name[], double concentration, double quantity, double price);
void medicationToString(Medication med);