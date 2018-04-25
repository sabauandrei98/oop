#pragma once
#include <string.h>
#include <iostream>
using namespace std;
class bacteria
{
private:
	string name;
	int number;
	bool immune;
public:
	bacteria();
	bacteria(string Name, int Number, bool Immune) : name(Name), number(Number), immune(Immune) {}
	~bacteria();

	string getName() { return this->name; };
	int getNumber() { return this->number; };
	bool isImmune() { return this->immune; };
	void setNumber(int newNumber) { this->number = newNumber; };
};

