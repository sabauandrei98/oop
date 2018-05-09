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
	
	/// <summary>
	/// Initial constructor
	/// </summary>
	Dog();

	/// <summary>
	/// Gets the breed
	/// </summary>
	/// <param name="breed">Dog's breed</param>
	/// <param name="name">Dog's name</param>
	/// <param name="age">Dog's age</param>
	/// <param name="photograph">Dog's photograph</param>
	Dog(const string& breed, const string& name, const int age, const string& photohraph);
	
	/// <summary>
	/// Gets the breed
	/// </summary>
	string getBreed() const { return breed; }

	/// <summary>
	/// Gets the name
	/// </summary>
	string getName() const { return name; }

	/// <summary>
	/// Gets the age
	/// </summary>
	int getAge() const { return age; }

	/// <summary>
	/// Gets the photograph
	/// </summary>
	string getPhotograph() const { return photograph; }

	/// <summary>
	/// Prints the attributes of a dog
	/// </summary>
	void printDog();

	friend istream& operator>>(std::istream& is, Dog& d);
	friend ostream& operator<<(std::ostream& os, const Dog& d);
};

