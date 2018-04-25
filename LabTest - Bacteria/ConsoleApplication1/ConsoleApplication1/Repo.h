#pragma once
#include <vector>
#include "bacteria.h"
using namespace std;
class Repo
{
private: 
	vector<bacteria> list;
public:
	Repo();
	
	int inRepo(bacteria bac);

	//Function that ads or updates an bacteria in the database
	//params: bac - type of bacteria which is the element to be added in the list
	//return: void
	void addRepo(bacteria bac);

	void updateRepo(int pos, bacteria bac);
	vector<bacteria> getList() { return this->list; };
	void setList(vector<bacteria> newList) {
		this->list = newList;
	};

	~Repo();
};

