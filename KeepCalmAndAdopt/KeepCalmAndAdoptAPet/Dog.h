#pragma once

#include <iostream>
using namespace std;

class Dog
{
private:
	string breed;
	string name;
	int age;
	string photograph;

public:
	Dog();
	Dog(const string& breed, const string& name, const int age, const string& photohraph);
	
	string getBreed() const { return breed; }
	string getName() const { return name; }
	int getAge() const { return age; }
	string getPhotograph() const { return photograph; }

	void printDog();
};

