#include <conio.h>
#include "Direction.h"

const int UP = 72;
const int DOWN = 80;
const int LEFT = 75;
const int RIGHT = 77;
const int ENTER = 13;
const int ESC = 27;

Direction::Direction()
{
	//ctor
}

Direction::~Direction()
{
	//dtor
}

int Direction::GetDirection()
{
	int ret = 0;

	do
	{
		int ch = getch();


		switch (ch)
		{
			case UP:
				ret = UP; // top
				break;

			case LEFT:
				ret = LEFT; // left
				break;

			case RIGHT:
				ret = RIGHT; // right
				break;

			case DOWN:
				ret = DOWN; // down
				break;

			case ENTER:
				ret = ENTER;
				break;

			case ESC:
				ret = ESC;
				break;

			default:
				break;
		}
	}
	while (ret == 0);

	return ret;
}
