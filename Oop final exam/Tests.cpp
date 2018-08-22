#include "Tests.h"



Tests::Tests()
{
}


Tests::~Tests()
{
}


//Function that returns all the Answers for a given question:
//in: string (question)
//out: vector<Answer> which contains the answers sorted by the number of votes
void Tests::testGetAnswersForGivenQuestion()
{
	Repository rep{ "users1.txt", "questions1.txt", "answers1.txt" };
	vector<Answer> ans = rep.getAllAnswersForSpecificQuestion("what is my name?");
	assert(ans.size() == 5);
	assert(ans[0].getVotes() == 39);
}

//Function that ads a question to the list
//in:the textBoxQuestion text
//out: the updated list with the question added
void Tests::testAddQuestion()
{
	Repository rep{ "users1.txt", "questions1.txt", "answers1.txt" };
	vector<Question> list;
	Question q{ 1,"what is my name?", "andrei" };
	list.push_back(q);
	assert(list.size() == 1);
	assert(list[0].getId() == 1);
	assert(list[0].getName() == "andrei");
}
