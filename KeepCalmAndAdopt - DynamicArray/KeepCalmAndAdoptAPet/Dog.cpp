#include "Dog.h"
#include <iostream>
#include <string>
using namespace std;

Dog::Dog()
{
	this->breed = "";
	this->age = 0;
	this->name = "";
	this->photograph = "";
}

Dog::Dog(const string& breed, const string& name, const int age, const string& photohraph) {

	this->breed = breed;
	this->age = age;
	this->name = name;
	this->photograph = photohraph;
}

void Dog::printDog()
{
	cout << this->breed << " " << this->name << " " << this->age << " " << this->photograph << '\n';
}
