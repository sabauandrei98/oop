#pragma once

#include <iostream>
#include <string>
using namespace std;

class User
{
private:
	string name;
public:
	User(string n) : name(n) {};
	~User() {};

	string getName() { return this->name; }
};

