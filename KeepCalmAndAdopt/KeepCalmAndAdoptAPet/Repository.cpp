#include "Repository.h"

using namespace std;

void Repository::addRepository(const Dog& d)
{
	this->dynamicArray.addDynamicArray(d);
}

void Repository::deleteRepository(int pos)
{
	this->dynamicArray.deleteDynamicArray(pos);
}

void Repository::updateRepository(int pos, const Dog& d)
{
	this->dynamicArray.updateDynamicArray(pos, d);
}

int Repository::getElementPosition(const Dog& d)
{
	Dog* elems = this->dynamicArray.getAllElems();
	for (int i = 0; i < this->dynamicArray.getSize(); i++)
	{
		if (elems[i].getAge() == d.getAge() && elems[i].getBreed() == d.getBreed() &&
			elems[i].getName() == d.getName() && elems[i].getPhotograph() == d.getPhotograph())
			return i;
	}

	return -1;
}
