#pragma once
#include "Controller.h"

class UI
{
private:
	Controller ctrl;
public:
	UI(const Controller& c) : ctrl(c) {}

	void run();

private:
	void addUI(const Dog& d);
	void updateUI(const Dog& oldDog, const Dog& newDog);
	void deleteUI(const Dog& d);

	void printDataBase();
	void printUI();
	Dog readDog(int cmdType) const;
	int getCommand();
	void runCommand(int cmd);
};

