#include <iostream>
#include <windows.h>
#include <vector>
#include "Block.h"
#include "StringNumber.h"
#include "HighScore.h"
#include "TempMap.h"
#include "RandomNumber.h"
#include "Direction.h"


const int UP = 72;
const int DOWN = 80;
const int LEFT = 75;
const int RIGHT = 77;
const int ESC = 27;

const int HEAD = 10;
const int MID = 20;
const int END = 30;
const int BLOCKSIZE = 6;
const int printTime = BLOCKSIZE - 2;
const int halfPrintTime = printTime / 2 - 1;



using namespace std;

Block::Block()
{
	int x = RandomNumber::GetRandomNumber(N);
	int y = RandomNumber::GetRandomNumber(N);

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
		{
			if (i == y && j == x)
			{
				SetNumber(j, i, 2);
			}
			else
			{
				SetNumber(j, i, 0);
			}
		}

	score = 0;

	if (HighScore::get() > 999999 || HighScore::get() < 0)
	{
		HighScore::set(*this);
	}




}

Block::~Block()
{
	//dtor
}

bool Block::CheckFail()
{

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if
			(
			    number[x][y] == 0 ||
			    (x > 0 && number[x][y] == number[x - 1][y]) ||
			    (x < 3 && number[x][y] == number[x + 1][y]) ||
			    (y > 0 && number[x][y] == number[x][y - 1]) ||
			    (y < 3 && number[x][y] == number[x][y + 1])
			)
			{
				return  false;
			}
		}
	}

	system("cls"); //清屏

	for (int i = 0; i < N; ++i)
	{
		cout << endl;
	}

	system("cls");

	for (int i = 0; i < 3; ++i)
	{
		cout << endl;
	}

	cout << "                       ███   ███  █  █  ███" << endl;
	cout << "                           █   █  █  █  █  █  █" << endl;
	cout << "                       ███   █  █  ███  ███" << endl;
	cout << "                       █       █  █      █  █  █" << endl;
	cout << "                       ███   ███      █  ███" << endl;

	for (int i = 0; i < 3; ++i)
	{
		cout << endl;
	}

	cout << "                            ╭︿︿︿╮ ╭︿︿︿╮ " << endl;
	cout << "                            {/o　　o/} {/o　　o/} " << endl;
	cout << "                            (　(oo)　) (　(oo)　) " << endl;
	cout << "                                 GAME OVER!" << endl;
	cout << "                               YOU SCORE: " << score << endl;
	cout << "                               PRESS ESC TO EXIT!" << endl;

	while (Direction::GetDirection() != ESC);

	return true;
}

void Block::ScreenPrint()
{
	system("cls"); //清屏


	for (int i = 0; i < 4; ++i)
	{
		LinePrint(HEAD);

		for (int j = 0; j < halfPrintTime; ++j)
		{
			LinePrint(MID);
		}

		LinePrint(i);

		for (int j = 0; j < halfPrintTime; ++j)
		{
			LinePrint(MID);
		}

		LinePrint(END);
	}

	if (score > HighScore::get())
	{
		HighScore::set(*this);
	}



}

void Block::LinePrint(int way)
{
	switch (way)
	{
		case HEAD:
			for (int i = 0; i < 4; ++i)
			{
				cout << "┌";

				for (int j = 0; j < printTime; ++j)
				{
					cout << "─";
				}

				cout << "┐";
			}

			cout << endl;

			break;

		case MID:
			for (int i = 0; i < 4; ++i)
			{
				cout << "│";

				for (int j = 0; j < printTime; ++j)
				{
					cout << "  ";
				}

				cout << "│";
			}

			cout << endl;
			break;

		case END:
			for (int i = 0; i < 4; ++i)
			{
				cout << "└";

				for (int j = 0; j < printTime; ++j)
				{
					cout << "─";
				}

				cout << "┘";
			}

			cout << endl;

			break;

		default:
			for (int i = 0; i < 4; ++i)
			{
				cout << "│";


				cout << "  " << StringNumber::convert(number[way][i]) << "  ";

				cout << "│";
			}

			switch (way)
			{
				case 0:
					cout << "   SCORE:  " << score;
					break;

				case 1:
					cout << "   HIGH:  " << HighScore::get();
					break;

				case 2:

					break;

				default:
				    cout << "   MADE IN XDU  ";
					break;
			}

			cout << endl;

			break;
	}
}

void Block::SetNumber(int x, int y, int data)
{
	number[y][x] = data;
}


void Block::RandomNumber()
{
	int  setLocate, numberOfSet = 2;

	vector<TempMap> zeroTemp;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (number[i][j] == 0)
			{
				TempMap t(j, i);
				zeroTemp.push_back(t);
			}
		}
	}

	setLocate = RandomNumber::GetRandomNumber(zeroTemp.size());

	if (RandomNumber::GetRandomNumber(10) > 8)
	{
		numberOfSet = 4;
	}

	SetNumber(zeroTemp[setLocate].GetX(), zeroTemp[setLocate].GetY(), numberOfSet);
}

void Block::SlideOne(int direction)
{
	bool change = false;

	switch (direction)
	{
		case UP:
			change = CleanBlank(UP);

			for (int i = 0; i < N; ++i)
			{
				if (number[0][i] == number[1][i] && number[2][i] == number[3][i]
				        && number[3][i])
				{
					number[0][i] += number[0][i];
					number[1][i] = number[2][i] + number[2][i];
					number[2][i] = 0;
					number[3][i] = 0;
					score += (number[0][i] + number[1][i]);
					change = true;
				}
				else
					if (number[0][i] == number[1][i]  && number[1][i])
					{
						number[0][i] += number[1][i];
						number[1][i] = number[2][i];
						number[2][i] = number[3][i];
						number[3][i] = 0;
						score += number[0][i];
						change = true;
					}
					else
						if (number[0][i] != number[1][i] && number[1][i] == number[2][i]
						        && number[2][i])
						{
							number[1][i] += number[2][i];
							number[2][i] = number[3][i];
							number[3][i] = 0;
							score += number[1][i];
							change = true;
						}

						else
							if (number[2][i] == number[3][i] && number[3][i])
							{
								number[2][i] += number[3][i] ;
								number[3][i] = 0;
								score += number[2][i];
								change = true;

							}
			}

			break;     // 向上

		case DOWN:

			change = CleanBlank(DOWN);

			for (int i = 0; i < N; ++i)
			{
				if (number[3][i] == number[2][i] && number[1][i] == number[0][i]
				        && number[2][i])
				{
					number[3][i] += number[3][i];
					number[2][i] = number[1][i] + number[1][i];
					number[1][i] = 0;
					number[0][i] = 0;
					score += (number[3][i] + number[2][i]);
					change = true;
				}
				else
					if (number[3][i] == number[2][i] && number[2][i] && number[1][i] != number[0][i])
					{
						number[3][i] += number[2][i];
						number[2][i] = number[1][i];
						number[1][i] = number[0][i];
						number[0][i] = 0;
						score += number[3][i];
						change = true;
					}
					else
						if (number[3][i] != number[2][i] && number[2][i] == number[1][i]
						        && number[1][i])
						{
							number[2][i] += number[1][i];
							number[1][i] = number[0][i];
							number[0][i] = 0;
							score += number[2][i];
							change = true;
						}

						else
							if (number[1][i] == number[0][i] && number[0][i])
							{
								number[1][i] += number[0][i] ;
								number[0][i] = 0;
								score += number[1][i];
								change = true;
							}
			}

			break;      // 向下

		case LEFT:
			change = CleanBlank(LEFT);

			for (int i = 0; i < N; ++i)
			{
				if (number[i][0] == number[i][1] && number[i][2] == number[i][3]
				        && number[i][2])
				{
					number[i][0] += number[i][1];
					number[i][1] = number[i][2] + number[i][2];
					number[i][2] = 0;
					number[i][3] = 0;
					score += (number[i][0] + number[i][1]);
					change = true;
				}
				else
					if (number[i][0] == number[i][1] && number[i][0])
					{
						number[i][0] += number[i][1];
						number[i][1] = number[i][2];
						number[i][2] = number[i][3];
						number[i][3] = 0;
						score += number[i][0];
						change = true;
					}
					else
						if (number[i][0] != number[i][1] && number[i][1] == number[i][2]
						        && number[i][1])
						{
							number[i][1] += number[i][2];
							number[i][2] = number[i][3];
							number[i][3] = 0;
							score += number[i][1];
							change = true;
						}

						else
							if (number[i][2] == number[i][3]
							        && number[i][2])
							{
								number[i][2] += number[i][3] ;
								number[i][3] = 0;
								score += number[i][2];
								change = true;
							}
			}


			break;      // 向左

		case RIGHT:
			change = CleanBlank(RIGHT);

			for (int i = 0; i < N; ++i)
			{
				if (number[i][3] == number[i][2] && number[i][1] == number[i][0]
				        && number[i][3])
				{
					number[i][3] += number[i][3];
					number[i][2] = number[i][1] + number[i][1];
					number[i][1] = 0;
					number[i][0] = 0;
					score += (number[i][3] + number[i][2]);
					change = true;
				}
				else
					if (number[i][3] == number[i][2] && number[i][3])
					{
						number[i][3] += number[i][2];
						number[i][2] = number[i][1];
						number[i][1] = number[0][i];
						number[i][0] = 0;
						score += number[i][3];
						change = true;
					}
					else
						if (number[i][3] != number[i][2] && number[i][2] == number[i][1]
						        && number[i][2])
						{
							number[i][2] += number[i][1];
							number[i][1] = number[i][0];
							number[i][0] = 0;
							score += number[i][2];
							change = true;
						}

						else
							if (number[i][1] == number[i][0] && number[i][1])
							{
								number[i][1] += number[i][0] ;
								number[i][0] = 0;
								score += number[i][1];
								change = true;
							}
			}

			break;	// 向右

		default:

			break;
	}

	if (change)
	{
		RandomNumber();
	}

}



bool Block::CleanBlank(int direction)
{
	bool change = false;

	switch (direction)
	{
		case UP:
			for (int i = 0; i < N; ++i)
			{
				for (int j = 0; j < N; ++j)
				{
					for (int k = N - 1; k > 0; --k)
					{
						if (number[k][i] != 0 && number[k - 1][i] == 0)
						{
							number[k - 1][i] = number[k][i];
							number[k][i] = 0;
							change = true;
						}
					}
				}
			}

			break;     // 向上

		case DOWN:
			for (int i = 0; i < N; ++i)
			{
				for (int j = 0; j < N; ++j)
				{
					for (int k = 0; k < N - 1; ++k)
					{
						if (number[k][i] != 0 && number[k + 1][i] == 0)
						{
							number[k + 1][i] = number[k][i];
							number[k][i] = 0;
							change = true;
						}
					}
				}
			}

			break;      // 向下

		case LEFT:
			for (int i = 0; i < N; ++i)
			{
				for (int j = 0; j < N; ++j)
				{
					for (int k = N - 1; k > 0; --k)
					{
						if (number[i][k] != 0 && number[i][k - 1] == 0)
						{
							number[i][k - 1] = number[i][k];
							number[i][k] = 0;
							change = true;
						}
					}
				}
			}

			break;      // 向左

		case RIGHT:
			for (int i = 0; i < N; ++i)
			{
				for (int j = 0; j < N; ++j)
				{
					for (int k = 0; k < N - 1; ++k)
					{
						if (number[i][k] != 0 && number[i][k + 1] == 0)
						{
							number[i][k + 1] = number[i][k];
							number[i][k] = 0;
							change = true;
						}
					}
				}
			}

			break;	// 向右

		default:

			break;
	}

	return change;

}



void Block::SlideTwo(int direction)
{
	bool change = false;

	switch (direction)
	{
		case UP:
			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{

					for (int x1 = x + 1; x1 < 4; x1++)
					{
						if (number[x1][y] > 0)
						{

							if (number[x][y] <= 0)
							{
								number[x][y] = number[x1][y];
								number[x1][y] = 0;
								x--;
								change = true;
							}
							else
								if (number[x][y] == number[x1][y])
								{
									number[x][y] = number[x][y] * 2;
									number[x1][y] = 0;
									score += number[x][y];
									change = true;
								}

							break;
						}
					}
				}
			}

			break;     // 向上

		case DOWN:
			for (int y = 0; y < 4; y++)
			{
				for (int x = 3; x >= 0; x--)
				{

					for (int x1 = x - 1; x1 >= 0; x1--)
					{
						if (number[x1][y] > 0)
						{

							if (number[x][y] <= 0)
							{
								number[x][y] = number[x1][y];
								number[x1][y] = 0;
								x++;
								change = true;
							}
							else
								if (number[x][y] == number[x1][y])
								{
									number[x][y] = number[x][y] * 2;
									number[x1][y] = 0;
									score += number[x][y];
									change = true;
								}

							break;
						}
					}
				}
			}

			break;      // 向下

		case LEFT:
			for (int x = 0; x < 4; x++)
			{
				for (int y = 0; y < 4; y++)
				{

					for (int y1 = y + 1; y1 < 4; y1++)
					{
						if (number[x][y1] > 0)
						{

							if (number[x][y] <= 0)
							{
								number[x][y] = number[x][y1];
								number[x][y1] = 0;
								y--;
								change = true;
							}
							else
								if (number[x][y] == number[x][y1])
								{
									number[x][y] = number[x][y] * 2;
									number[x][y1] = 0;
									score += number[x][y];
									change = true;
								}

							break;

						}
					}
				}
			}

			break;      // 向左

		case RIGHT:
			for (int x = 0; x < 4; x++)
			{
				for (int y = 3; y >= 0; y--)
				{

					for (int y1 = y - 1; y1 >= 0; y1--)
					{
						if (number[x][y1] > 0)
						{

							if (number[x][y] <= 0)
							{
								number[x][y] = number[x][y1];
								number[x][y1] = 0;
								y++;
								change = true;
							}
							else
								if (number[x][y] == number[x][y1])
								{
									number[x][y] = number[x][y] * 2;
									number[x][y1] = 0;
									score += number[x][y];
									change = true;
								}

							break;
						}
					}
				}
			}

			break;	// 向右

		default:

			break;
	}

	if (change)
	{
		RandomNumber();
	}
}

void Block::Game()
{
	int direction;

	while (1)
	{
		ScreenPrint();
		direction = Direction::GetDirection();

		if (direction == ESC)
		{
			break;
		}

		SlideTwo(direction);

		if (CheckFail())
		{
			break;
		}

	}
}

void Block::SetNew()
{
	int x = RandomNumber::GetRandomNumber(N);
	int y = RandomNumber::GetRandomNumber(N);

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
		{
			if (i == y && j == x)
			{
				SetNumber(j, i, 2);
			}
			else
			{
				SetNumber(j, i, 0);
			}
		}

	score = 0;

	if (HighScore::get() > 999999 || HighScore::get() < 0)
	{
		HighScore::set(*this);
	}
}
