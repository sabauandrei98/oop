#pragma once

#include "Dog.h"
#include "Repository.h"


class UndoAction
{
public:
	virtual void executeUndo() = 0;
	// virtual destructor!
	virtual ~UndoAction() {};
};


class UndoAdd : public UndoAction
{
private:
	int pos;
	Dog addedDog;
	Repository& repo;	
public:
	UndoAdd(Repository& _repo, const Dog& d, int p) : repo{ _repo }, addedDog{ d }, pos{ p } {}
	void executeUndo() override
	{
		this->repo.deleteRepository(this->pos);
	}
};

class UndoRemove : public UndoAction
{
private:
	int pos;
	Dog removeDog;
	Repository& repo;
public:
	UndoRemove(Repository& _repo, const Dog& d, int p) : repo{ _repo }, removeDog{ d }, pos{ p } {}

	void executeUndo() override
	{
		this->repo.addRepository(removeDog);
	}
};

class UndoUpdate : public UndoAction
{
private:
	int pos;
	Dog updateDog;
	Repository& repo;
public:
	UndoUpdate(Repository& _repo, const Dog& d, int p) : repo{ _repo }, updateDog{ d }, pos{ p } {}

	void executeUndo() override
	{
		this->repo.updateRepository(this->pos, updateDog);
	}
};
