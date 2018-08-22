#include "Repository.h"




void Repository::readUsers()
{
	ifstream f(fUsers);

	while (!f.eof())
	{
		string str;
		getline(f, str);
		char split_char = '|';

		istringstream split(str);
		vector<string> tokens;
		for (string each; getline(split, each, split_char); tokens.push_back(each));
		//for (int i = 0; i < tokens.size(); i++) ExceptionsQt q{ tokens[i] };
		User u{ tokens[0] };
		this->addUser(u);
	}
}

void Repository::readQuestions()
{
	ifstream f(fQuestions);

	while (!f.eof())
	{
		string str;
		getline(f, str);
		char split_char = '|';

		istringstream split(str);
		vector<string> tokens;
		for (string each; getline(split, each, split_char); tokens.push_back(each));
		//for (int i = 0; i < tokens.size(); i++) ExceptionsQt q{ tokens[i] };
		Question q{ stoi(tokens[0]), tokens[1], tokens[2] };
		this->addQuestion(q);
	}
	
}

void Repository::WriteUsers()
{
	ofstream f1(fUsers);
	f1.clear();
	for (int i = 0; i < this->users.size(); i++)
	{
		f1 << users[i].getName();
		if (i + 1 != this->users.size())
			f1 << '\n';
	}
	f1.close();
}

void Repository::WriteQuestions()
{
	ofstream f2(fQuestions);
	f2.clear();
	for (int i = 0; i < this->questions.size(); i++)
	{
		f2 << to_string(this->questions[i].getId()) + "|" + this->questions[i].getQuestion() + "|" + this->questions[i].getName();
		if (i + 1 != this->questions.size())
			f2 << '\n';
	}
	f2.close();

}

void Repository::WriteAnswers()
{
	ofstream f3(fAnswers);
	f3.clear();
	for (int i = 0; i < this->answers.size(); i++)
	{
		f3 << to_string(answers[i].getId()) + "|" + answers[i].getQuestion() + "|" + answers[i].getName() + "|" + answers[i].getAnswer() + "|" + to_string(answers[i].getVotes());
		if (i + 1 != this->answers.size())
			f3 << '\n';
	}
	f3.close();
}


//Function that returns all the Answers for a given question:
//in: string (question)
//out: vector<Answer> which contains the answers sorted by the number of votes
vector<Answer> Repository::getAllAnswersForSpecificQuestion(string q)
{
	vector<Answer> ans;
	for(int i = 0; i < this->answers.size(); i++)
		if (answers[i].getQuestion() == q)
		{
			ans.push_back(answers[i]);
		}
	sort(ans.begin(), ans.end(), [](Answer a, Answer b) {return a.getVotes() > b.getVotes(); });
	return ans;
}

int Repository::getQuestionAnswers(string q)
{
	int ans = 0;
	for (int i = 0; i < this->answers.size(); i++)
		if (answers[i].getQuestion() == q)
			ans++;
	return ans;
}

void Repository::readAnswers()
{
	ifstream f(fAnswers);

	while (!f.eof())
	{
		string str;
		getline(f, str);
		char split_char = '|';

		istringstream split(str);
		vector<string> tokens;
		for (string each; getline(split, each, split_char); tokens.push_back(each));
		//for (int i = 0; i < tokens.size(); i++) ExceptionsQt q{ tokens[i] };
		Answer a{ stoi(tokens[0]), tokens[1], tokens[2], tokens[3], stoi(tokens[4]) };
		this->addAnswer(a);
	}

}

