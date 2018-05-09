#pragma once
#include <string>
#include "FileAdoptionList.h"
#include <fstream>
#include <Windows.h>
using namespace std;

class HtmlAdoptionList : public FileAdoptionList
{
public:
	HtmlAdoptionList(string filename) : FileAdoptionList{ filename } {}

	void writeToFile() override {
		ofstream g(this->filename);

		g << "<!DOCTYPE html>\n<html>\n<head>\n<title>Playlist</title>\n</head>\n<body>\n<table border = \"1\">\n";
		
		g << "<tr>\n";
		g << "<td>Breed</td>\n";
		g << "<td>Name</td>\n";
		g << "<td>Age</td>\n";
		g << "<td>Photograph</td>\n";
		g << "</tr>\n";

		for (auto dog : this->getAllElems())
		{
			g << "<tr>\n";
			g << "<td>" << dog.getBreed() << "</td>\n";
			g << "<td>" << dog.getName() << "</td>\n";
			g << "<td>" << dog.getAge() << "</td>\n";
			g << "<td><a href =\"" << dog.getPhotograph() << "\">Click</a></td>\n";
			g << "</tr>\n";
		}

		g << "</table>\n</body>\n</html>";
	};

	void displayAdoptionList() override {
		string aux = "\"" + this->filename + "\"";
		ShellExecuteA(NULL, NULL, "C:\\Program Files\\Opera\\launcher.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
	};
};

