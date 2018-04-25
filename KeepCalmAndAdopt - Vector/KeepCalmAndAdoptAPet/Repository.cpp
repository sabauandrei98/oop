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
	vector<Dog> elems = this->dynamicArray.getAllElems();
	for (int i = 0; i < this->dynamicArray.getSize(); i++)
	{
		if (elems[i].getAge() == d.getAge() && elems[i].getBreed() == d.getBreed() &&
			elems[i].getName() == d.getName() && elems[i].getPhotograph() == d.getPhotograph())
			return i;
	}
	return -1;
}

DynamicArray<Dog> Repository::sortArray(const Compare<Dog>& comp)
{
	DynamicArray<Dog> myArray = this->getDynamicArray();
	vector<Dog> elems = myArray.getAllElems();
	for (int i = 0; i < myArray.getSize(); i++)
		for (int j = i + 1; j < myArray.getSize(); j++)
			if (comp.compare(elems[i], elems[j]))
				swap(elems[i], elems[j]);

	DynamicArray<Dog> result;
	for (int i = 0; i < myArray.getSize(); i++)
		result.addDynamicArray(elems[i]);

	return result;
}

void Repository::saveDataToFile()
{
	ofstream g("data.txt");
	vector<Dog> dogsList = this->getDynamicArray().getAllElems();
	for (int i = 0; i < dogsList.size(); i++)
	{
		g << dogsList[i];
		if (i + 1!= dogsList.size())
			g << "\n";
	}
}

void Repository::getDataFromFile()
{
	ifstream f("data.txt");
	while (!f.eof())
	{
		Dog dog {};
		f >> dog;
		this->addRepository(dog);
	}
}
