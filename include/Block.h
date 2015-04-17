#ifndef BLOCK_H
#define BLOCK_H
#define N 4

class Block
{
public:
	Block();
	virtual ~Block();
	void ScreenPrint();//������Ļ��ӡ
	void LinePrint(int way);//���ݲ�������ӡ
	void SetNumber(int x, int y, int data);//���þ�����Ԫ�ص�ֵ
	bool CleanBlank(int direction);//������������ϵ���Ԫ��
	void RandomNumber();//���ѡ����Ԫ�ظ�ֵ,90%Ϊ2,10%Ϊ4
	bool CheckFail();//�ж��Ƿ��Ѿ���Ϸ����
	void SlideOne(int direction);//��һ�ֻ���
	void SlideTwo(int direction);//�ڶ���
	void Game();//ִ����Ϸ
	void SetNew();//����Ϸ
	friend class HighScore;//����߷ֵ�����Ϊ��Ԫ
	friend class NumberData;//��ȡ���ȵ���Ϊ��Ԫ
protected:
private:
	int number[N][N], score;
};

#endif // BLOCK_H
