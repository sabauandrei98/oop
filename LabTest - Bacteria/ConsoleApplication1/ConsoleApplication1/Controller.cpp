#include "Controller.h"




Controller::~Controller()
{
}

vector<bacteria> Controller::sortByType(vector<bacteria> list)
{
	for (int i = 0; i < list.size(); i++)
		for (int j = i + 1; j < list.size(); j++)
			if (list[i].getName() > list[j].getName())
				swap(list[i], list[j]);
	return list;
}

int Controller::contAdd(bacteria bac)
{
	int pos = this->repo.inRepo(bac);
	if (pos != -1)
	{
		this->repo.updateRepo(pos, bac);
		return 0;
	}
	else
	{
		this->repo.addRepo(bac);
		return 1;
	}
}

void Controller::environmentChange(int id)
{
	vector<bacteria> list = this->getList();
	if (id == 1)
	{
		for (int i = 0; i < list.size(); i++)
			list[i].setNumber(list[i].getNumber() * 2);
	}
	if (id == 2)
	{
		for (int i = 0; i < list.size(); i++)
			if(list[i].isImmune() == false)
				list[i].setNumber(list[i].getNumber() / 2);
	}
	this->repo.setList(list);
}
