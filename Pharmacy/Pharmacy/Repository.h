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
void addElement(DynamicRepo* dr, Medication med);
void updateElement(DynamicRepo* dr, int medPosition, Medication med);
void removeElement(DynamicRepo* dr, int position);

//Others
int inRepo(DynamicRepo* dr, Medication med);
void repositoryToString(DynamicRepo* dr);