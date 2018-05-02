#pragma once
#include <string>
#include "DynamicArray.h"
using namespace std;


class FileAdoptionList : public DynamicArray<Dog>
{
protected:
	string filename;

public:
	FileAdoptionList(string file) : filename(file) {};
	virtual ~FileAdoptionList() { }

	virtual void writeToFile() = 0;
	virtual void displayAdoptionList() = 0;
};

