#include <fstream>
#include "NumberData.h"

using namespace std;

NumberData::NumberData()
{

}

NumberData::~NumberData()
{
	//dtor
}

void NumberData::Save(int SaveNum, Block & block)
{
	ofstream out;

	switch (SaveNum)
	{
		case 0:
			out.open("SaveGame1.ini");
			break;

		case 1:
			out.open("SaveGame2.ini");
			break;

		case 2:
			out.open("SaveGame3.ini");
			break;

		default:
			break;
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			out << block.number[i][j];
			out << " ";
		}
	}
	out<<block.score;
	out.close();
}

void NumberData::Load(int LoadNum, Block & block)
{
	ifstream in;

	switch (LoadNum)
	{
		case 0:
			in.open("SaveGame1.ini");
			break;

		case 1:
			in.open("SaveGame2.ini");
			break;

		case 2:
			in.open("SaveGame3.ini");
			break;

		default:
			break;
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			in >> block.number[i][j];
		}
	}
	in>>block.score;

	in.close();
}


