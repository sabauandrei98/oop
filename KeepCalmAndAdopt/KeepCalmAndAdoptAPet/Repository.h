#pragma once

#include <iostream>
#include "DynamicArray.h"
using namespace std;


class Repository 
{
private:
	DynamicArray dynamicArray;
public:
	Repository() {};

	void addRepository(const Dog& d);
	void deleteRepository(int pos);
	void updateRepository(int pos, const Dog& d);
	int getElementPosition(const Dog& d);

	DynamicArray getDynamicArray() { return dynamicArray; };
};

void repositoryTest();

