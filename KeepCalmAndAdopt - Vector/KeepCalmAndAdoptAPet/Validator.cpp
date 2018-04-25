#include "Validator.h"



Validator::Validator()
{
}


Validator::~Validator()
{
}

bool Validator::validateBreed(string breed)
{
	if (breed.size() < 3)
		throw Exceptions(typeid(this).name(), "Breed too short");

	return true;
}

bool Validator::validateName(string name)
{
	if (name.size() == 1)
		throw Exceptions(typeid(this).name(), "Name too short");

	return true;
}

bool Validator::validateAge(string age)
{
	for (int i = 0; i < age.size(); i++)
		if (!isdigit(age[i]))
			throw Exceptions(typeid(this).name(), "Invalid age");

	return true;
}

bool Validator::validatePhotograph(string photograph)
{
	if (photograph.size() <3)
		throw Exceptions(typeid(this).name(), "Photograph too short");

	return true;
}

bool Validator::validateDog(string breed, string name, string age, string photograph)
{
	this->validateBreed(breed);
	this->validateName(name);
	this->validateAge(age);
	this->validatePhotograph(photograph);

	return true;
}
