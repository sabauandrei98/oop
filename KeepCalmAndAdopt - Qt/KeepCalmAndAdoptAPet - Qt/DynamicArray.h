#pragma once

#include "Dog.h"
#include <vector>

template <typename TElement>
class DynamicArray
{
protected:
	vector<TElement> elems;

public:
	DynamicArray() {};
	virtual ~DynamicArray() {};
	void addDynamicArray(const TElement& e) { this->elems.push_back(e); }
	void deleteDynamicArray(int pos) { this->elems.erase(this->elems.begin() + pos); }
	void updateDynamicArray(int pos, const TElement& e) { this->elems[pos] = e; }
	int getSize() { return this->elems.size(); }
	vector<TElement> getAllElems() const { return this->elems; }
};
