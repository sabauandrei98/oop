#include "Tests.h"

#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

Tests::Tests()
{
}


Tests::~Tests()
{
}

void Tests::testAdd()
{
	Repo repo;
	bacteria bac1{ "bac1", 10, true };
	repo.addRepo(bac1);

	vector<bacteria> list = repo.getList();
	assert(list[0].getName() == "bac1");
	assert(list[0].getNumber() == 10);

	Repo repo1;
	Controller cont{ repo1 };
	bacteria bac2{ "bac1", 10, true };
	cont.contAdd(bac2);
	assert(list[0].getNumber() == 10);
	assert(list.size() == 1);
	
}

void Tests::testEnv()
{
	Repo repo;
	Controller cont{ repo };
	bacteria bac1{ "bac1", 10, true };
	bacteria bac2{ "bac2", 10, true };
	bacteria bac3{ "bac3", 10, false };
	bacteria bac4{ "bac4", 10, false};
	cont.contAdd(bac1);
	cont.contAdd(bac2);
	cont.contAdd(bac3);
	cont.contAdd(bac4);
	cont.environmentChange(1);
	vector<bacteria> list = cont.getList();
	assert(list.size() == 4);
	assert(list[0].getNumber() == 20);
	assert(list[1].getNumber() == 20);

	cont.environmentChange(2);
	assert(list[0].getNumber() == 20);
	assert(list[2].getNumber() == 10);
}
