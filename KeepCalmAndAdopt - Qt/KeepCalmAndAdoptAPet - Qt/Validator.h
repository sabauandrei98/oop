#pragma once
#include <iostream>
#include <string>
#include "Dog.h"
#include "Exceptions.h"
using namespace std;

class Validator
{
public:
	Validator();

	bool validateBreed(string breed);
	bool validateName(string name);
	bool validateAge(string age);
	bool validatePhotograph(string photograph);
	bool validateDog(string breed, string name, string age, string photograph);

	~Validator();
};

