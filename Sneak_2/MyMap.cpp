#pragma once
#include "MyMap.h"

MyMap::MyMap(int height, int width, int colorWall, coordin leftUpCorrner, char fillSimbol)
{
	this->height = height;
	this->width = width;
	this->leftUpCorrner = leftUpCorrner;
	this->gameContinue = 1;

	char s;
	SetConsoleTextAttribute(h, colorWall);
	coordin tempCoordin = leftUpCorrner;
	for (int y = 0; y < height; y++) 
	{
		tempCoordin = leftUpCorrner;
		tempCoordin.y += y;
		SetConsoleCursorPosition(h, tempCoordin.coordinToCOORD());
		for (int x = 0; x < width; x++)
		{
			if (x == 0 && y == 0)
				s = 218;
			else if (x == 0 && y == height - 1)
				s = 192;
			else if (y == 0 && x == width - 1)
				s = 191;
			else if (y == height - 1 && x == width - 1)
				s = 217;
			else if (y == 0 || y == height - 1)
				s = 196;
			else if (x == 0 || x == width - 1) 
				s = 179;
			else s = fillSimbol;
			putchar(s);
		}
		cout << endl;
	}
	Apple* appl = new Apple();
	this->apple = appl;
	putApple();
}

MyMap::~MyMap()
{
	delete apple;
}



void MyMap::pushSneak(Sneak& sneak)
{
	sneaks.push_back(&sneak);
}

void MyMap::putApple()
{
	coordin c = leftUpCorrner;
	do
	{
		apple->coord.x = randomNumber(c.x + 1 ,c.x + width - 2);
		apple->coord.y = randomNumber(c.y + 1, c.y + height - 2);
	} while (!(thisPlaceFree(apple->coord)));

	apple->drawApple();
}

bool MyMap::thisPlaceFree(coordin coord)
{
	for (auto sneak : sneaks)
	{
		if (sneak->head == coord)
		{
			return false;
		}
		else
		{
			for (auto part : sneak->tail)
			{
				if (part == coord)
				{
					return false;
				}
			}
		}
	}
	return true;
}















bool MyMap::getGameContinue()
{
	return gameContinue;
}

coordin MyMap::getLeftUpCorrner()
{
	return leftUpCorrner;
}

int MyMap::getWidth()
{
	return width;
}

int MyMap::getHeight()
{
	return height;
}
