#pragma once
#include <iostream>
#include <string>
using namespace std;

class Exceptions
{
private:
	string object;
	string message;
	
public:
	Exceptions(string obj, string exception) : object(obj), message(exception) {};

	string getMessage() { return this->message; };
	string getObject() { return this->object; };

	void printException()
	{
		cout << "==========================================================\n";
		cout << "Oops: " << this->object << " -> " << this->message << '\n';
		cout << "==========================================================\n";
	}

	~Exceptions() {};
};

