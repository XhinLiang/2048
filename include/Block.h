#ifndef BLOCK_H
#define BLOCK_H
#define N 4

class Block
{
public:
	Block();
	virtual ~Block();
	void ScreenPrint();//整个屏幕打印
	void LinePrint(int way);//根据参数来打印
	void SetNumber(int x, int y, int data);//设置矩阵中元素的值
	bool CleanBlank(int direction);//清除滑动方向上的零元素
	void RandomNumber();//随机选择零元素赋值,90%为2,10%为4
	bool CheckFail();//判断是否已经游戏结束
	void SlideOne(int direction);//第一种滑动
	void SlideTwo(int direction);//第二种
	void Game();//执行游戏
	void SetNew();//新游戏
	friend class HighScore;//将最高分的类设为友元
	friend class NumberData;//读取进度的类为友元
protected:
private:
	int number[N][N], score;
};

#endif // BLOCK_H
