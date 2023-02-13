#pragma once
#include "coordin.h"

coordin::coordin()
{
	x = 0;
	y = 0;
}

coordin::coordin(int x, int y)
{
	this->x = x;
	this->y = y;
}

coordin::coordin(const coordin& c)
{
	this->x = c.x;
	this->y = c.y;
}

coordin& coordin::operator=(const coordin& c)
{
	this->x = c.x;
	this->y = c.y;
	return *this;
}

int coordin::getX()
{
	return x;
}

int coordin::getY()
{
	return y;
}

void coordin::setX(int x)
{
	this->x = x;
}

void coordin::setY(int y)
{
	this->y = y;
}

COORD& coordin::coordinToCOORD()
{
	COORD coord;
	coord.X = x;
	coord.Y = y; 
	return coord;
}

bool coordin::operator==(const coordin& c)
{
	if (this->x == c.x && this->y == c.y)
		return 1;
	else
		return 0;
}
