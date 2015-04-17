#include <fstream>
#include "HighScore.h"

using namespace std;

HighScore::HighScore()
{
	//ctor
}

HighScore::~HighScore()
{
	//dtor
}

int HighScore::set(Block block)
{
	ofstream out;
	out.open("score.ini");
	out << block.score;
	out.close();
	return 0;
}

int HighScore::get()
{
	int score;
	ifstream in;
	in.open("score.ini");
	in >> score;
	in.close();
	return score;
}
