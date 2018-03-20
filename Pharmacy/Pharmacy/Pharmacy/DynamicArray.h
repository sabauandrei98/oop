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
DynamicRepo* createDynamicArray(int capacity);

/// <summary>
/// Deallocates the memory used for the array
/// </summary>
/// <param name="dr">A pointer to the container</param>
void destroyDynamicArray(DynamicRepo* dr);

/// <summary>
/// Resize the memory zone used by the repository
/// </summary>
/// <param name="dr">A pointer to the container</param>
void resizeDynamicArray(DynamicRepo* dr);