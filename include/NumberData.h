#ifndef NUMBERDATA_H
#define NUMBERDATA_H

#include "Block.h"
#define N 4

class Block;

class NumberData
{
public:
	NumberData();
	virtual ~NumberData();
	static void Save(int SaveNum, Block & block);//保存进度
	static void Load(int LoadNum, Block & block);//读取进度
protected:
private:
};

#endif // NUMBERDATA_H
