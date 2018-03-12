#include <stdio.h>
#include <stdlib.h>
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

int addElement(DynamicRepo* dr, Medication med)
{
	if (dr == NULL)
		return -1;

	if (dr->elements == NULL)
		return -1;

	if (dr->length == dr->capacity)
		resizeDynamicRepo(dr);

	
	dr->elements[dr->length] = med;
	dr->length++;
	
	return 1;
}

int inRepo(DynamicRepo* dr, Medication med)
{
	for (int i = 0; i < dr->length; i++)
		if (dr->elements[i].name == med.name && dr->elements[i].concentration == med.concentration)
			return i;
	return -1;
}

void repositoryToString(DynamicRepo* dr)
{
	for (int i = 0; i < dr->length; i++)
		printf("Entry: %d: %s, %d, %d, %d\n",
			i,
			dr->elements[i].name,
			dr->elements[i].concentration,
			dr->elements[i].quantity,
			dr->elements[i].price);
}




