#pragma once

#include <iostream>
#include <string>
using namespace std;

class Answer
{
private:
	int id;
	string question;
	string name;
	string answer;
	int votes;
public:
	Answer(int i, string q, string n, string a, int v) : id(i), question(q), name(n), answer(a), votes(v){};
	~Answer() {};

	int getId() { return this->id; }
	string getQuestion() { return this->question; }
	string getName() { return this->name; }
	string getAnswer() { return this->answer; }
	int getVotes() { return this->votes; }
};

