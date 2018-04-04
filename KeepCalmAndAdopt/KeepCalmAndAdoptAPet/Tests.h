#pragma once
#include "Controller.h"
class Tests
{
public:
	Tests();
	~Tests();

	void runTests();

private:
	void controllerTest();
	void repositoryTest();
	void dynamicArrayTest();
	void dogTest();
};

