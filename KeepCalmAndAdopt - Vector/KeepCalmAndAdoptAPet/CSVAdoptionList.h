#pragma once
#include <string>
#include "FileAdoptionList.h"
#include <fstream>
#include <Windows.h>
using namespace std;

class CSVAdoptionList : public FileAdoptionList
{
public:
	CSVAdoptionList(string filename) : FileAdoptionList{ filename } {}

	void writeToFile() override { 
		ofstream g(this->filename);
		for (auto dog : this->getAllElems())
			g << dog << '\n';
	};

	void displayAdoptionList() override {
		string aux = "\"" + this->filename + "\""; 
		ShellExecuteA(NULL, NULL, "C:\\Program Files\\Microsoft Office\\Office16\\EXCEL.EXE", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
	};
};

