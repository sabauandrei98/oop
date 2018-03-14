#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Repository.h"
#include <assert.h>


DynamicRepo* createDynamicRepo(int capacity)
{
	DynamicRepo* dr = (DynamicRepo*)malloc(sizeof(DynamicRepo));

	if (dr == NULL)
		return NULL;

	dr->capacity = capacity;
	dr->length = 0;

	dr->elements = (Medication*)malloc(capacity * sizeof(Medication));

	if (dr->elements == NULL)
		return NULL;

	return dr;
}

void destroyDynamicRepo(DynamicRepo* dr)
{
	if (dr == NULL)
		return;

	free(dr->elements);
	dr->elements = NULL;

	free(dr);
	dr = NULL;
}


void resizeDynamicRepo(DynamicRepo* dr)
{
	if (dr == NULL)
		return;

	dr->capacity *= 2;

	Medication* newDr = (Medication*)realloc(dr->elements, dr->capacity * sizeof(Medication));

	if (newDr == NULL)
		return;

	dr->elements = newDr;
}

void addElement(DynamicRepo* dr, Medication med)
{
	if (dr->length == dr->capacity)
		resizeDynamicRepo(dr);

	dr->elements[dr->length] = med;
	dr->length++;
}

void removeElement(DynamicRepo* dr, int position)
{
	if (position == dr->length - 1)
		dr->length--;
	else
	{
		dr->elements[position] = dr->elements[dr->length - 1];
		dr->length--;
	}
}

void updateElement(DynamicRepo* dr, int medPosition, Medication med)
{
	dr->elements[medPosition].quantity = med.quantity;
	dr->elements[medPosition].price = med.price;
}

int inRepo(DynamicRepo* dr, Medication med)
{
	if (dr == NULL)
		return -2;

	if (dr->elements == NULL)
		return -2;

	for (int i = 0; i < dr->length; i++)
		if (strcmp(dr->elements[i].name, med.name) == 0 && dr->elements[i].concentration == med.concentration)
			return i;

	return -1;
}

DynamicRepo* sortRepository(DynamicRepo* dr)
{
	for(int i = 0; i < dr->length; i++)
		for (int j = i + 1; j < dr->length; j++)
		if (strcmp(dr->elements[i].name, dr->elements[j].name) > 0)
		{
			Medication med = dr->elements[i];
			dr->elements[i] = dr->elements[j];
			dr->elements[j] = med;
		}

	return dr;
}

void repositoryToString(DynamicRepo* dr)
{
	for (int i = 0; i < dr->length; i++)
		printf("Entry %d: %s, %d, %d, %d\n",
			i,
			dr->elements[i].name,
			dr->elements[i].concentration,
			dr->elements[i].quantity,
			dr->elements[i].price);
}

void repositoryTest()
{
	DynamicRepo* dr = createDynamicRepo(2);
	Medication med = createMedication("med1", 20, 20, 20);
	addElement(dr, med);

	assert(dr->length == 1);

	//tested: 
	//createDynamicRepo
	//addElement

	med = createMedication("med2", 20, 20, 20);
	addElement(dr, med);
	med = createMedication("med3", 20, 20, 20);
	addElement(dr, med);

	assert(strcmp(dr->elements[2].name, "med3") == 0);

	//tested:
	//resizeDynamicRepo

	med = createMedication("med3", 20, 50, 40);
	updateElement(dr, 2, med);

	assert(dr->elements[2].quantity == 50 && dr->elements[2].price == 40);

	//tested:
	//updateElement

	removeElement(dr, 2);
	assert(dr->length == 2);

	removeElement(dr, 0);
	assert(dr->length == 1);
	assert(strcmp(dr->elements[0].name, "med2") == 0);

	//tested:
	//removeElement

	med = createMedication("med2", 20, 20, 20);
	assert(inRepo(dr, med) == 0);
	med = createMedication("med1", 20, 20, 20);
	assert(inRepo(dr, med) == -1);

	//tested:
	//inRepo

	addElement(dr, med);
	med = createMedication("med3", 20, 20, 20);
	sortRepository(dr);

	assert(strcmp(dr->elements[0].name, "med1") == 0);
	assert(strcmp(dr->elements[1].name, "med2") == 0);
	assert(strcmp(dr->elements[2].name, "med3") == 0);

	//tested:
	//sortRepository
}




