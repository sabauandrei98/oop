#pragma once
#include "Medication.h"

typedef struct {

	Medication* elements;
	int capacity;
	int length;

} DynamicRepo;

//Dynamic Repository 
DynamicRepo* createDynamicRepo(int capacity);
void destroyDynamicRepo(DynamicRepo* dr);
void resizeDynamicRepo(DynamicRepo* dr);

//Functionalities
int addElement(DynamicRepo* dr, Medication med);

int inRepo(DynamicRepo* dr, Medication med);
void repositoryToString(DynamicRepo* dr);