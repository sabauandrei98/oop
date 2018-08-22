#pragma once

#include <iostream>
#include <string>
using namespace std;

class Question
{
private:
	int id;
	string question;
	string name;

public:
	Question(int i, string q, string n) : id(i), question(q), name(n) {};
	~Question() {};

	int getId() { return this->id; }
	string getQuestion() { return this->question; }
	string getName() { return this->name; }
};

