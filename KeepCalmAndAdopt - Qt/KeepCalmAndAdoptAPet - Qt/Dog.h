#pragma once
#include <iostream>
#include <string>
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

	friend istream& operator>>(std::istream& is, Dog& d);
	friend ostream& operator<<(std::ostream& os, const Dog& d);

	string toString() { return this->breed + " " + this->name + " " + to_string(this->age) + " " + this->photograph; }
};

