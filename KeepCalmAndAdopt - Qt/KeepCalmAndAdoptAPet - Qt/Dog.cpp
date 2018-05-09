#include "Dog.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "Validator.h"
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

vector<string> tokenize(string str, char delimiter)
{
	vector <string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);

	return result;
}


istream& operator>>(std::istream & is, Dog & dog)
{
	string line;
	getline(is, line);

	vector<string> tokens = tokenize(line, ' ');
	if (tokens.size() != 4)
		return is;

	Validator validate;
	try {
		validate.validateDog(tokens[0], tokens[1], tokens[2], tokens[3]);
	}
	catch (Exceptions ex)
	{
		ex.printException();
	}

	dog.breed = tokens[0];
	dog.name = tokens[1];
	dog.age = stoi(tokens[2]);
	dog.photograph = tokens[3];

	return is;
}

ostream& operator<<(std::ostream & os, const Dog & dog)
{
	os << dog.breed << " " << dog.name << " " << dog.age << " " << dog.photograph;
	return os;
}