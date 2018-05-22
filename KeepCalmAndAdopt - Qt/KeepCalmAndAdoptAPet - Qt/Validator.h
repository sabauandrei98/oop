#pragma once
#include <iostream>
#include <string>
#include "Dog.h"
using namespace std;

class Validator
{
public:
	Validator(){}

	bool validateBreed(string breed) {
		if (breed.size() < 3)
			return false;
		return true;
	}
	bool validateName(string name) {
		if (name.size() == 1)
			return false;
		return true;
	}
	bool validateAge(string age) {
		for (int i = 0; i < age.size(); i++)
			if (!isdigit(age[i]))
				return false;
		return true;
	}
	bool validatePhotograph(string photograph) {
		if (photograph.size() < 3)
			return false;
		return true;
	}
	bool validateDog(string breed, string name, string age, string photograph) {
		if (!this->validateBreed(breed) || !this->validateName(name) ||
			!this->validateAge(age) || !this->validatePhotograph(photograph))
			return false;
		return true;
	}
};

