#include "DynamicArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

DynamicRepo* createDynamicArray(int capacity)
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

void destroyDynamicArray(DynamicRepo* dr)
{
	if (dr == NULL)
		return;

	free(dr->elements);
	dr->elements = NULL;

	free(dr);
	dr = NULL;
}


void resizeDynamicArray(DynamicRepo* dr)
{
	if (dr == NULL)
		return;

	dr->capacity *= 2;

	Medication* newDr = (Medication*)realloc(dr->elements, dr->capacity * sizeof(Medication));

	if (newDr == NULL)
		return;

	dr->elements = newDr;
}