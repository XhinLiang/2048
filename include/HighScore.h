#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include "Block.h"

class HighScore
{
public:
	HighScore();
	virtual ~HighScore();
	static int set(Block block);//������߷�
	static int get();//��ȡ
protected:
private:
};

#endif // HIGHSCORE_H
