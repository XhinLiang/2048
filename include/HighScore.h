#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include "Block.h"

class HighScore
{
public:
	HighScore();
	virtual ~HighScore();
	static int set(Block block);//保存最高分
	static int get();//读取
protected:
private:
};

#endif // HIGHSCORE_H
