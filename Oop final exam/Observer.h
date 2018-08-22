#pragma once
#include<vector>
#include "ExceptionsQt.h"
using namespace std;
class Observer
{
public:
	virtual void refreshDataBase() = 0;
	virtual ~Observer() {}
};

class Observable
{
private:
	vector<Observer*> obs;
public:
	void addObserver(Observer* o)
	{
		obs.push_back(o);
	}
	void notify()
	{
		for (auto i : obs)
			i->refreshDataBase();
	}
};