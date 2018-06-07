#pragma once

#include "Dog.h"
#include "Repository.h"


class RedoAction
{
public:
	virtual void executeRedo() = 0;
	// virtual destructor!
	virtual ~RedoAction() {};
};


class RedoAdd : public RedoAction
{
private:
	int pos;
	Dog addedDog;
	Repository& repo;
public:
	RedoAdd(Repository& _repo, const Dog& d, int p) : repo{ _repo }, addedDog{ d }, pos{ p } {}
	void executeRedo() override
	{
		this->repo.addRepository(addedDog);
	}
};

class RedoRemove : public RedoAction
{
private:
	int pos;
	Dog removeDog;
	Repository& repo;
public:
	RedoRemove(Repository& _repo, const Dog& d, int p) : repo{ _repo }, removeDog{ d }, pos{ p } {}

	void executeRedo() override
	{
		this->repo.deleteRepository(pos);
	}
};

class RedoUpdate : public RedoAction
{
private:
	int pos;
	Dog updateDog;
	Repository& repo;
public:
	RedoUpdate(Repository& _repo, const Dog& d, int p) : repo{ _repo }, updateDog{ d }, pos{ p } {}

	void executeRedo() override
	{
		this->repo.updateRepository(this->pos, updateDog);
	}
};
