#include "StringNumber.h"


int StringNumber::max(int a, int b)
{
	return a > b ? a : b;
}

StringNumber::StringNumber()
{
	data = "0000";
}

StringNumber::~StringNumber()
{
	//dtor
}

string StringNumber::add(string a, string b)
{
	char next = 0;
	string c("0000");

	for (int i = N - 1; i >= 0; --i)
	{
		int t = a[i] + b[i] + next - 48;

		if (t > 57)
		{
			c[i] = t - 10;
			next = 1;
		}
		else
		{
			c[i] = t;
		}
	}

	return c;
}

string StringNumber::settle(string a)
{
	if (a[N] != '0')
	{
		return a;
	}
	else
	{
		int MoveTime = N - a.size();

		for (int i = 0; i < MoveTime; ++i)
		{
			for (int j = N - 1; j > 0; --j)
			{
				a[j] = a[j - 1];
			}

			for (int j = 0; j < MoveTime; ++j)
			{
				a[j] = '0';
			}
		}

		return a;
	}
}

int StringNumber::convert(string a)
{
	int sum = 0;

	for (int i = 0; i < N; ++i)
	{
		int power = 1;

		for (int j = i; j < N; ++j)
		{
			power *= 10;
		}

		sum += (a[i] - 48) * power;
	}

	return sum;
}

string StringNumber::convert(int a)
{
	string sum("0000");

	if (a)
	{
		for (int i = N - 1; i >= 0; --i)
		{
			int t = a % 10;
			a /= 10;
			sum[i] = t + 48;
		}
	}
	else
	{
		for (int i = 0; i < N; ++i)
		{
			sum[i] = ' ';
		}
	}

	for (int i = 0; i < N && sum[i] == '0'; ++i)
	{
		sum[i] = ' ';
	}


	return sum;
}
