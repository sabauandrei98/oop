#pragma once

#include <iostream>
#include <fstream>
#include "Exceptions.h"
#include "DynamicArray.h"
#include "Compare.h"
using namespace std;


class Repository 
{
private:
	DynamicArray<Dog> dynamicArray;

public:

	Repository() {};

	Repository(string type) 
	{ 
		if(type == "file")
			this->getDataFromFile(); 
	};

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

	DynamicArray<Dog> sortArray(const Compare<Dog>& comp);

	void saveDataToFile();
	void getDataFromFile();

};


