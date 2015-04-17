#ifndef TEMPMAP_H
#define TEMPMAP_H


class TempMap
{
public:
	TempMap(int, int);
	virtual ~TempMap();
	int GetX();
	int GetY();
protected:
private:
	int x, y;
};

#endif // TEMPMAP_H
