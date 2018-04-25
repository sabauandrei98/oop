#include "UI.h"

#include <iostream>
#include <string>

using namespace std;




UI::~UI()
{
}

void UI::printMenu()
{
	cout << "1.Add bacteria\n";
	cout << "2.See the list \n";
	cout << "3.Environment\n";

}

void UI::uiAddBacteria()
{
	string name;
	int number;
	bool immune;

	cout << "Name:"; cin >> name;
	cout << "Number:"; cin >> number;
	cout << "Immune:"; cin >> immune;

	bacteria bac{ name, number, immune };

	int res = this->controller.contAdd(bac);
	if (res == 0)
		cout << "Updated !";
	else
		cout << "New record added !";
}

void UI::run()
{
	this->printMenu();

	while (true)
	{
		string cmd = "";
		cin >> cmd;

		if (cmd == "1")
		{
			this->uiAddBacteria();
		}
		else
			if (cmd == "2")
			{
				vector<bacteria> list = this->controller.getList();
				list = this->controller.sortByType(list);
				for (int i = 0; i < list.size(); i++)
					cout << list[i].getName() << " " << list[i].getNumber() << " " << list[i].isImmune() << '\n';
			}
			else
				if (cmd == "3")
				{
					string t;
					cout << "Env:";
					cin >> t;
					if (t == "sugar")
					{
						this->controller.environmentChange(1);
					}
					else if (t == "antibiotic")
					{
						this->controller.environmentChange(2);
					}
					else
						cout << "Invalid";
				}
				else
					cout << "Invalid command";
	}

}