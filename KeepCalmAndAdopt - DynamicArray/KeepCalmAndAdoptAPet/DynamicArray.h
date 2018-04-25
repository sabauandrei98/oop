#pragma once

#include "Dog.h"

template <typename TElement>
class DynamicArray
{
private:
	TElement * elems;
	int size;
	int capacity;
public:

	/// <summary>
	/// Initial constructor
	/// </summary>
	/// <param name="capacity">Predefinited size</param>
	DynamicArray(int capacity = 4);

	/// <summary>
	/// Secondary constructor
	/// </summary>
	/// <param name="v">DynamicArray as constructor</param>
	DynamicArray(const DynamicArray<TElement>& v);
	~DynamicArray();

	DynamicArray<TElement>& operator=(const DynamicArray<TElement>& v);
	DynamicArray<TElement>& operator+(DynamicArray<TElement>& v);

	/// <summary>
	/// Adds an element to the array
	/// </summary>
	/// <param name="e">The generic element</param>
	void addDynamicArray(const TElement& e);

	/// <summary>
	/// Deletes an element from the array
	/// </summary>
	/// <param name="pos">The position of the element which will be deleted</param>
	void deleteDynamicArray(int pos);

	/// <summary>
	/// Updates an element from the array
	/// </summary>
	/// <param name="pos">The position of the element which will be updated</param>
	/// <param name="e">The new information</param>
	void updateDynamicArray(int pos, const TElement& e);

	/// <summary>
	/// Gets the size of the array
	/// </summary>
	int getSize() const;

	/// <summary>
	/// Gets the capacity of the array
	/// </summary>
	int getCapacity() const;

	/// <summary>
	/// Gets the elements of the array
	/// </summary>
	TElement* getAllElems() const;

	/// <summary>
	/// Prints the array elements
	/// </summary>
	void printArray();

private:
	/// <summary>
	/// Resizes the array of elements
	/// </summary>
	/// <param name="factor">New capacity = factor * oldCapacity</param>
	void resize(double factor = 2);
};

template <typename TElement>
DynamicArray<TElement>::DynamicArray(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elems = new TElement[capacity];
}

template <typename TElement>
DynamicArray<TElement>::DynamicArray(const DynamicArray& v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}
template <typename TElement>
DynamicArray<TElement>::~DynamicArray()
{
	delete[] this->elems;
}

template <typename TElement>
DynamicArray<TElement>& DynamicArray<TElement>::operator=(const DynamicArray& v)
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

template <typename TElement>
DynamicArray<TElement>& DynamicArray<TElement>::operator+(DynamicArray& v) {

	while (this->size + v.getSize() >= this->capacity)
	{
		this->resize();
	}

	for (int i = this->size; i < this->size + v.getSize(); i++)
		this->elems[i] = v.elems[i - this->size];

	this->size += v.getSize();

	return *this;
}

template <typename TElement>
void DynamicArray<TElement>::addDynamicArray(const TElement& e)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;
}

template <typename TElement>
void DynamicArray<TElement>::deleteDynamicArray(int pos)
{
	if (this->size - 1 == pos)
		this->size--;
	else
	{
		this->elems[pos] = this->elems[this->size - 1];
		this->size--;
	}

}

template <typename TElement>
void DynamicArray<TElement>::updateDynamicArray(int pos, const TElement& e) {
	this->elems[pos] = e;
}

template <typename TElement>
void DynamicArray<TElement>::resize(double factor)
{
	this->capacity *= static_cast<int>(factor);

	TElement* els = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		els[i] = this->elems[i];

	delete[] this->elems;
	this->elems = els;
}

template <typename TElement>
TElement* DynamicArray<TElement>::getAllElems() const
{
	return this->elems;
}

template <typename TElement>
int DynamicArray<TElement>::getSize() const
{
	return this->size;
}

template <typename TElement>
int DynamicArray<TElement>::getCapacity() const
{
	return this->capacity;
}

template <typename TElement>
void DynamicArray<TElement>::printArray()
{
	for (int i = 0; i < this->size; i++)
	{
		cout << "Dog" << i + 1 << ": ";
		this->elems[i].printDog();
	}
}

