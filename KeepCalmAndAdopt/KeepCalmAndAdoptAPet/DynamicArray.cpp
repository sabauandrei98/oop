#include "DynamicArray.h"
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

DynamicArray::DynamicArray(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elems = new TElement[capacity];
}


DynamicArray::DynamicArray(const DynamicArray& v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}

DynamicArray::~DynamicArray()
{
	delete[] this->elems;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& v)
{
	if (this == &v)
		return *this;

	this->size = v.size;
	this->capacity = v.capacity;

	delete[] this->elems;
	this->elems = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];

	return *this;
}

DynamicArray& DynamicArray::operator+(DynamicArray& v) {

	while (this->size + v.getSize() >= this->capacity)
	{
		this->resize();
	}
	
	for (int i = this->size; i < this->size + v.getSize(); i++)
		this->elems[i] = v.elems[i - this->size];

	this->size += v.getSize();

	return *this;
}

void DynamicArray::addDynamicArray(const TElement& e)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;
}

void DynamicArray::deleteDynamicArray(int pos)
{
	if (this->size - 1 == pos)
		this->size--;
	else
	{
		this->elems[pos] = this->elems[this->size - 1];
		this->size--;
	}
	
}

void DynamicArray::updateDynamicArray(int pos, const TElement& e) {
	this->elems[pos] = e;
}

void DynamicArray::resize(double factor)
{
	this->capacity *= static_cast<int>(factor);

	TElement* els = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		els[i] = this->elems[i];

	delete[] this->elems;
	this->elems = els;
}

TElement* DynamicArray::getAllElems() const
{
	return this->elems;
}

int DynamicArray::getSize() const
{
	return this->size;
}

int DynamicArray::getCapacity() const
{
	return this->capacity;
}

void DynamicArray::printArray()
{
	for (int i = 0; i < this->size; i++)
	{
		cout << "Dog" << i + 1 << ": "; 
		this->elems[i].printDog();
	}
}

void DynamicArrayTest()
{
	DynamicArray dr1;

	assert(dr1.getSize() == 0);
	
	Dog dog{ "breed1", "name1", 20, "photo1" };
	dr1.addDynamicArray(dog);

	assert(dr1.getSize() == 1);

	Dog dog1{ "breed2", "name2", 40, "photo3" };
	DynamicArray dr2;
	dr2.addDynamicArray(dog1);

	dr1 = dr1 + dr2;

	assert(dr1.getSize() == 2);
	TElement* elems = dr1.getAllElems();
	assert(elems[0].getName() == "name1");
	assert(elems[1].getName() == "name2");
	assert(dr1.getCapacity() == 10);

	dr1.updateDynamicArray(0, dog1);
	elems = dr1.getAllElems();
	assert(elems[0].getName() == "name2");
	dr1.deleteDynamicArray(1);
	dr1.deleteDynamicArray(0);
	assert(dr1.getSize() == 0);
}