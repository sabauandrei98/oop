#pragma once
#include "Medication.h"

typedef struct {

	Medication* elements;
	int capacity;
	int length;

} DynamicRepo;


//Dynamic Repository 

/// <summary>
/// Allocates memory for an array of elements
/// </summary>
/// <param name="capacity">The length of the allocated memory</param>
/// <returns>Returns a pointer to a repository allocated in memory with a specific size</returns>
DynamicRepo* createDynamicRepo(int capacity);

/// <summary>
/// Deallocates the memory used for the array
/// </summary>
/// <param name="dr">A pointer to the container</param>
void destroyDynamicRepo(DynamicRepo* dr);

/// <summary>
/// Resize the memory zone used by the repository
/// </summary>
/// <param name="dr">A pointer to the container</param>
void resizeDynamicRepo(DynamicRepo* dr);


//Functionalities

/// <summary>
/// Adds a Medication structure to the container
/// </summary>
/// <param name="dr">A pointer to the container</param>
/// <param name="med">The Medication structure which will be added to the container</param>
void addElement(DynamicRepo* dr, Medication med);

/// <summary>
/// Updates a Medication structure from the container (only the quantitiy and the price)
/// </summary>
/// <param name="dr">A pointer to the container</param>
/// <param name="medPosition">The position in the container of the element which will be updated</param>
/// <param name="med">The Medication structure which will be updated in the container</param>
void updateElement(DynamicRepo* dr, int medPosition, Medication med);

/// <summary>
/// Removes a Medication structure from the container
/// </summary>
/// <param name="dr">A pointer to the container</param>
/// <param name="medPosition">The position in the container of the element which will be removed</param>
void removeElement(DynamicRepo* dr, int position);

/// <summary>
/// Sorts the Repository ascending by name
/// </summary>
/// <param name="dr">A pointer to the container</param>
/// <returns>Returns a pointer to the sorted repository</returns>
DynamicRepo* sortRepository(DynamicRepo* dr);

/// <summary>
/// Sorts the Repository ascending by price
/// </summary>
/// <param name="dr">A pointer to the container</param>
/// <returns>Returns a pointer to the sorted repository</returns>
DynamicRepo* sortRepositoryByPrice(DynamicRepo* dr);


//Others

/// <summary>
/// Checks if an Medication is in the Repository
/// </summary>
/// <param name="dr">A pointer to the container</param>
/// <param name="med">The Medication structure which the function is looking for</param>
/// <returns>The position of the Medication in the Repository, -1, otherwise</returns>
int inRepo(DynamicRepo* dr, Medication med);


//UI

/// <summary>
/// Prints the Repository
/// </summary>
/// <param name="dr">A pointer to the container</param>
void repositoryToString(DynamicRepo* dr);


//Tests
void repositoryTest();