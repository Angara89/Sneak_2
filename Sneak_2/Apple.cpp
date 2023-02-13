#pragma once
#include "Apple.h"



Apple::Apple()
{
	this->color = 4;
	this->simbol = 42;
}

void Apple::drawApple()
{

	SetConsoleCursorPosition(h, this->coord.coordinToCOORD());
	SetConsoleTextAttribute(h, color);
	putchar(simbol);
}

coordin Apple::getCoord()
{
	return coord;
}
