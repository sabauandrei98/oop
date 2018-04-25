#pragma once

#include "Dog.h"

template<class T>
class Compare
{
public:
	virtual bool compare(const T& a, const T& b) const = 0;
	virtual ~Compare() {};
};

template<class T>
class SortByNameAscending : public Compare<T>
{
public:
	bool compare(const Dog& a, const Dog& b) const override
	{
		return a.getName() > b.getName();
	}
};

template<class T>
class SortByAgeDescending : public Compare<T>
{
public:
	bool compare(const Dog& a, const Dog& b) const override
	{
		return a.getAge() < b.getAge();
	}
};

