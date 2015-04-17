#ifndef STRINGNUMBER_H
#define STRINGNUMBER_H

#include <string>
#define N 4

using namespace std;
class StringNumber
{
public:
	StringNumber();
	virtual ~StringNumber();
	static string convert(int);//将int转成string
	static int convert(string);//将string转成int
	static string add(string , string);//两个string型的数相加
	static string settle(string);//设置数据
	static int max(int, int); //最大值
protected:
private:
	string data;
};

#endif // STRINGNUMBER_H
