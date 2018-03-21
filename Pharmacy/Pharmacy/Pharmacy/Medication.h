#pragma once

typedef struct {

	char name[25];
	int concentration;
	int quantity;
	int price;

} Medication;


/// <summary>
/// Creates a Medication structure.
/// </summary>
/// <param name="name[]">The name of the Medication</param>
/// <param name="concentration">The concentration of the Medication</param>
/// <param name="quantity">The quantity of the Medication</param>
/// <param name="price">The price of the Medication</param>
/// <returns>A medication struct</returns>
Medication* createMedication(char name[], double concentration, double quantity, double price);

void destroyMedication(Medication* med);

//UI
/// <summary>
/// Prints a Medication
/// </summary>
/// <param name="Medication">The medication which will be printed</param>
void printMedication(Medication* med);


//Test
void medicationTest();