#include "TempMap.h"

TempMap::TempMap(int xTemp, int yTemp)
{
	x = xTemp;
	y = yTemp;
	//ctor
}

TempMap::~TempMap()
{
	//dtor
}

int TempMap::GetX()
{
	return x;
}

int TempMap::GetY()
{
	return y;
}
