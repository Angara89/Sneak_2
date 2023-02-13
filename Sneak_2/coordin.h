#pragma once
#include "common.h"

class coordin
{
private:
public:
	int x;
	int y;
	coordin();
	coordin(int x, int y);
	coordin(const coordin& c);
	coordin& operator=(const coordin& c);
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	COORD& coordinToCOORD();
	bool operator==(const coordin& c);
};
