#pragma once
#include <iostream>
#include <assert.h>
#include "WindowB.h"
#include "WindowA.h"
using namespace std;

class Tests
{
public:
	Tests();
	~Tests();

	void testAddQuestion();
	void testGetAnswersForGivenQuestion();
};

