#pragma once

#include "Dog.h"
#include <vector>

template <typename TElement>
class DynamicArray
{
protected:
	vector<TElement> elems;

public:

	/// <summary>
	/// Initial constructor
	/// </summary>
	/// <param name="capacity">Predefinited size</param>
	DynamicArray(){};
	virtual ~DynamicArray() {};

	DynamicArray<TElement>& operator=(const DynamicArray<TElement>& v);
	DynamicArray<TElement>& operator+(DynamicArray<TElement>& v);

	/// <summary>
	/// Adds an element to the array
	/// </summary>
	/// <param name="e">The generic element</param>
	void addDynamicArray(const TElement& e) { this->elems.push_back(e); }

	/// <summary>
	/// Deletes an element from the array
	/// </summary>
	/// <param name="pos">The position of the element which will be deleted</param>
	void deleteDynamicArray(int pos) { this->elems.erase(this->elems.begin() + pos); }

	/// <summary>
	/// Updates an element from the array
	/// </summary>
	/// <param name="pos">The position of the element which will be updated</param>
	/// <param name="e">The new information</param>
	void updateDynamicArray(int pos, const TElement& e) { this->elems[pos] = e; }

	/// <summary>
	/// Gets the size of the array
	/// </summary>
	int getSize() const { return (int)this->elems.size(); }


	/// <summary>
	/// Gets the elements of the array
	/// </summary>
	vector<TElement> getAllElems() const { return this->elems; }

	/// <summary>
	/// Prints the array elements
	/// </summary>
	void printArray();
};



template <typename TElement>
DynamicArray<TElement>& DynamicArray<TElement>::operator=(const DynamicArray& v)
{
	this->elems = v.elems;
	return *this;
}

template <typename TElement>
DynamicArray<TElement>& DynamicArray<TElement>::operator+(DynamicArray& v) {

	for (int i = 0; i < v.getSize(); i++)
		this->elems.push_back(v.elems[i]);
	return *this;
}


template <typename TElement>
void DynamicArray<TElement>::printArray()
{
	for (int i = 0; i < this->elems.size(); i++)
	{
		cout << "Dog" << i + 1 << ": ";
		this->elems[i].printDog();
	}
}

