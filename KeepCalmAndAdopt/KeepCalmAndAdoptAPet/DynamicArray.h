#pragma once

#include "Dog.h"
typedef Dog TElement;

class DynamicArray
{
private:
	TElement * elems;
	int size;
	int capacity;
public:
	DynamicArray(int capacity = 10);
	DynamicArray(const DynamicArray& v);
	~DynamicArray();

	DynamicArray& operator=(const DynamicArray& v);
	DynamicArray& operator+(DynamicArray& v);

	void addDynamicArray(const TElement& e);
	void deleteDynamicArray(int pos);
	void updateDynamicArray(int pos, const TElement& e);

	int getSize() const;
	int getCapacity() const;
	TElement* getAllElems() const;

	void printArray();

private:
	void resize(double factor = 2);
};

void DynamicArrayTest();

