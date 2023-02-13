#pragma once
#include "Apple.h"



Apple::Apple()
{
	this->color = 4;
	this->simbol = 42;
	SetConsoleCursorPosition(h, this->coord.coordinToCOORD());
	SetConsoleTextAttribute(h, this->color);
	putchar(this->simbol);
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
