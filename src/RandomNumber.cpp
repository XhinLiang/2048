#include <ctime>
#include <cstdlib>
#include "RandomNumber.h"

RandomNumber::RandomNumber()
{
	//ctor
}

RandomNumber::~RandomNumber()
{
	//dtor
}

int RandomNumber::GetRandomNumber(int x)
{
	srand((unsigned)time(0));
	return rand() % x;
}
