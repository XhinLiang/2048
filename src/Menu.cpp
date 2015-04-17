#include <windows.h>
#include <iostream>
#include "Menu.h"
#include "Direction.h"

const int UP = 72;
const int DOWN = 80;
const int LEFT = 75;
const int RIGHT = 77;
const int ENTER = 13;
const int ESC = 27;

using namespace std;

Menu::Menu()
{
	selectNum = 0;
}

Menu::~Menu()
{
	//dtor
}

int Menu::MainSelect()
{
	selectNum = 0;
	MainPrint();
	int direction = Direction::GetDirection();

	while (direction != ENTER)
	{

		if (direction == UP)
		{
			selectNum--;
		}
		else
			if (direction == DOWN)
			{
				selectNum++;
			}

		if (selectNum > 4)
		{
			selectNum = 0;
		}
		else
			if (selectNum < 0)
			{
				selectNum = 4;
			}

		MainPrint();
		direction = Direction::GetDirection();
	}

	return selectNum;
}

void Menu::SavePrint()
{
	system("cls");

	for (int i = 0; i < 3; ++i)
	{
		cout << endl;
	}

	cout << "                       ¨€¨€¨€   ¨€¨€¨€  ¨€  ¨€  ¨€¨€¨€" << endl;
	cout << "                           ¨€   ¨€  ¨€  ¨€  ¨€  ¨€  ¨€" << endl;
	cout << "                       ¨€¨€¨€   ¨€  ¨€  ¨€¨€¨€  ¨€¨€¨€" << endl;
	cout << "                       ¨€       ¨€  ¨€      ¨€  ¨€  ¨€" << endl;
	cout << "                       ¨€¨€¨€   ¨€¨€¨€      ¨€  ¨€¨€¨€" << endl;

	for (int i = 0; i < 3; ++i)
	{
		cout << endl;
	}

	if (selectNum == 0)
	{
		cout << "                              " << "  *  " << "Data1" << endl;
		cout << "                              " << "     " << "Data2" << endl;
		cout << "                              " << "     " << "Data3" << endl;
	}
	else
		if (selectNum == 1)
		{
			cout << "                              " << "     " << "Data1" << endl;
			cout << "                              " << "  *  " << "Data2" << endl;
			cout << "                              " << "     " << "Data3" << endl;
		}
		else
		{
			cout << "                              " << "     " << "Data1" << endl;
			cout << "                              " << "     " << "Data2" << endl;
			cout << "                              " << "  *  " << "Data3" << endl;
		}
}

void Menu::MainPrint()
{
	system("cls");

	for (int i = 0; i < 3; ++i)
	{
		cout << endl;
	}

	cout << "                       ¨€¨€¨€   ¨€¨€¨€  ¨€  ¨€  ¨€¨€¨€" << endl;
	cout << "                           ¨€   ¨€  ¨€  ¨€  ¨€  ¨€  ¨€" << endl;
	cout << "                       ¨€¨€¨€   ¨€  ¨€  ¨€¨€¨€  ¨€¨€¨€" << endl;
	cout << "                       ¨€       ¨€  ¨€      ¨€  ¨€  ¨€" << endl;
	cout << "                       ¨€¨€¨€   ¨€¨€¨€      ¨€  ¨€¨€¨€" << endl;


	for (int i = 0; i < 3; ++i)
	{
		cout << endl;
	}

	if (selectNum == 0)
	{
		cout << "                              " << "  *  " << "RESUME" << endl;
		cout << "                              " << "     " << "NEW" << endl;
		cout << "                              " << "     " << "LOAD" << endl;
		cout << "                              " << "     " << "SAVE" << endl;
		cout << "                              " << "     " << "EXIT" << endl;
	}
	else
		if (selectNum == 1)
		{
			cout << "                              " << "     " << "RESUME" << endl;
			cout << "                              " << "  *  " << "NEW" << endl;
			cout << "                              " << "     " << "LOAD " << endl;
			cout << "                              " << "     " << "SAVE" << endl;
			cout << "                              " << "     " << "EXIT" << endl;
		}
		else
			if (selectNum == 2)
			{
				cout << "                              " << "     " << "RESUME" << endl;
				cout << "                              " << "     " << "NEW" << endl;
				cout << "                              " << "  *  " << "LOAD" << endl;
				cout << "                              " << "     " << "SAVE" << endl;
				cout << "                              " << "     " << "EXIT" << endl;
			}
			else
				if (selectNum == 3)
				{
					cout << "                              " << "     " << "RESUME" << endl;
					cout << "                              " << "     " << "NEW" << endl;
					cout << "                              " << "     " << "LOAD" << endl;
					cout << "                              " << "  *  " << "SAVE" << endl;
					cout << "                              " << "     " << "EXIT" << endl;
				}
				else
				{
					cout << "                              " << "     " << "RESUME" << endl;
					cout << "                              " << "     " << "NEW" << endl;
					cout << "                              " << "     " << "LOAD" << endl;
					cout << "                              " << "     " << "SAVE" << endl;
					cout << "                              " << "  *  " << "EXIT" << endl;
				}
}

int Menu::SaveSelect()
{
	selectNum = 0;
	SavePrint();
	int direction = Direction::GetDirection();

	while (direction != ENTER)
	{
		if (direction == 27)
		{
			return 27;
		}

		else
			if (direction == UP)
			{
				selectNum--;
			}
			else
				if (direction == DOWN)
				{
					selectNum++;
				}

		if (selectNum > 2)
		{
			selectNum = 0;
		}
		else
			if (selectNum < 0)
			{
				selectNum = 2;
			}

		SavePrint();
		direction = Direction::GetDirection();
	}

	return selectNum;
}
