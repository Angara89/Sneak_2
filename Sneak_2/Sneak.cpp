#pragma once
#include "Sneak.h"

Sneak::Sneak(MyMap& map)
{
	coordin c;
	c.x = map.leftUpCorrner.x + (map.width / 2);
	c.y = map.leftUpCorrner.y + (map.height / 2);
	this->head = c;
	myMap = &map;
	this->length = 1;
	this->simbolHead = 1;
	this->simbolTail = 176;
	this->color = 5;
	this->dx = 0;
	this->dy = -1;

}

void Sneak::drawSneak()
{
	SetConsoleCursorPosition(h, head.coordinToCOORD());
	SetConsoleTextAttribute(h, color);
	putchar(simbolHead);

	for (auto part : tail)
	{
		SetConsoleCursorPosition(h, part.coordinToCOORD());
		SetConsoleTextAttribute(h, color);
		putchar(simbolTail);
	}
}

void Sneak::moveSneak(bool eatApple)
{
	tail.push_front(head);
	head.x += dx;
	head.y += dy;
	if (!(eatApple))
	{
		SetConsoleCursorPosition(h, tail.back().coordinToCOORD());
		SetConsoleTextAttribute(h, 1);
		putchar(' ');
		tail.pop_back();
	}
	drawSneak();
}

void Sneak::usersDecide(int k)
{
	switch (k) 
	{
	case 80: // если вниз
		dy = 1;
		dx = 0; 
		break;
	case 72: // если вверх
		dy = -1; 
		dx = 0;
		break;
	case 75: // если влево
		dy = 0;
		dx = -1;
		break;
	case 77: // если вправо
		dy = 0;
		dx = 1;
		break;
	}
}














int Sneak::getDY()
{
	return dy;
}

int Sneak::getDX()
{
	return dx;
}

int Sneak::getLength()
{
	return length;
}

coordin Sneak::getHead()
{
	return head;
}

list<coordin> Sneak::getTail()
{
	return tail;
}

