#pragma once
#include "Controller.h"
class UI
{
private:
	Controller controller;
public:
	UI(Controller cont) : controller(cont) {}

	void uiAddBacteria();
	void printMenu();
	void run();

	~UI();
};

