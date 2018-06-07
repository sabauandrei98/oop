#pragma once

#include <iostream>
#include <fstream>
#include "DynamicArray.h"
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

	void addRepository(const Dog& d);
	void deleteRepository(int pos);
	void updateRepository(int pos, const Dog& d);
	int getElementPosition(const Dog& d);
	int getSize() { return this->dynamicArray.getSize(); }
	DynamicArray<Dog>& getDynamicArray() { return dynamicArray; };	

	void saveDataToFile();
	void getDataFromFile();
};