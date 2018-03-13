#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Repository.h"


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




