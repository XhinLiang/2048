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
	static string convert(int);//��intת��string
	static int convert(string);//��stringת��int
	static string add(string , string);//����string�͵������
	static string settle(string);//��������
	static int max(int, int); //���ֵ
protected:
private:
	string data;
};

#endif // STRINGNUMBER_H
