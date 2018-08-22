#pragma once

#include "User.h"
#include "Question.h"
#include "Answer.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "ExceptionsQt.h"
#include "Observer.h"
#include <algorithm>
using namespace std;

class Repository : public Observable
{
private:
	vector<User> users;
	vector<Question> questions;
	vector<Answer> answers;
	string fUsers, fQuestions, fAnswers;

public:
	Repository(string u, string q, string a) : fUsers(u), fQuestions(q), fAnswers(a) {
		this->readUsers();
		this->readQuestions();
		this->readAnswers();
	};
	~Repository() {
		WriteAnswers();
		WriteUsers();
		WriteQuestions();
	};

	void addUser(User e) { this->users.push_back(e); }
	void addQuestion(Question e) { this->questions.push_back(e); }
	void addAnswer(Answer e) { this->answers.push_back(e); }
	vector<User>& getUsers(){ return this->users; }
	vector<Question>& getQuestions() { return this->questions; }
	vector<Answer>& getAnswers() { return this->answers; }
	void readUsers();
	void readQuestions();
	void readAnswers();
	void WriteAnswers();
	void WriteUsers();
	void WriteQuestions();
	int getQuestionAnswers(string q);
	vector<Answer> getAllAnswersForSpecificQuestion(string q);

};

