#pragma once

#include <iostream>
#include "DynamicArray.h"
#include "Compare.h"
using namespace std;


class Repository 
{
private:
	DynamicArray<Dog> dynamicArray;

public:
	Repository() {};

	/// <summary>
	/// Adds an element to the array
	/// </summary>
	/// <param name="d">The generic element</param>
	void addRepository(const Dog& d);

	/// <summary>
	/// Deletes an element from the array
	/// </summary>
	/// <param name="pos">The position of the element which will be deleted</param>
	void deleteRepository(int pos);

	/// <summary>
	/// Updates an element from the array
	/// </summary>
	/// <param name="pos">The position of the element which will be updated</param>
	/// <param name="e">The new information</param>
	void updateRepository(int pos, const Dog& d);

	/// <summary>
	/// Returns the position of an element
	/// </summary>
	/// <param name="d">The element which the function is looking for</param>
	/// <returns>The position of the element in the array</returns>
	int getElementPosition(const Dog& d);

	/// <summary>
	/// Gets the Dynamic Array
	/// </summary>
	/// <returns>A Dynamic Array</returns>
	DynamicArray<Dog> getDynamicArray() { return dynamicArray; };	

	DynamicArray<Dog> sortArray(const Compare<Dog>& comp)
	{
		DynamicArray<Dog> myArray = this->getDynamicArray();
		Dog* elems = myArray.getAllElems();
		for (int i = 0; i < myArray.getSize(); i++)
			for (int j = i + 1; j < myArray.getSize(); j++)
				if (comp.compare(elems[i], elems[j]))
					swap(elems[i], elems[j]);
		return myArray;
	}

};


