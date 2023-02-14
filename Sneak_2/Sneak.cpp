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
	this->lastMove = "up";

}

Sneak::Sneak(Sneak& sneak)
{
	this->head = sneak.head;
	this->tail = sneak.tail;
	this->myMap = sneak.myMap;
	this->length = sneak.length;
	this->simbolHead = sneak.simbolHead;
	this->simbolTail = sneak.simbolTail;
	this->color = sneak.color;
	this->dx = sneak.dx;
	this->dy = sneak.dy;
	this->lastMove = sneak.lastMove;
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

void Sneak::decide()
{
	while (commands.empty())
	{
		Sneak sneak(*this);
		commands = sneak.buildPath();
		this->lastMove = sneak.lastMove;
	}
	string command = commands.back();
	commands.pop_back();

	if (command == "down")
	{
		lastMoveText = "down";
		dy = 1;
		dx = 0;
	}
	if (command == "up")
	{
		lastMoveText = "up";

		dy = -1;
		dx = 0;
	}
	if (command == "right")
	{
		lastMoveText = "right";

		dy = 0;
		dx = 1;
	}
	if (command == "left")
	{
		lastMoveText = "left";

		dy = 0;
		dx = -1;
	}

}

list<string> Sneak::buildPath()
{

	string step;
	coordin needCoord = myMap->apple->getCoord();
	coordin lastPartTail;
	if (!(tail.empty()))
	{
		lastPartTail = tail.back();
	}

	string wrongStep1;
	string wrongStep2;
	string wrongStep3;


	list <string> tempList;


	string needDirection;
do
{
	if (needCoord.x == head.x)
		if (needCoord.y > head.y)
			needDirection = "down";		
		else if (needCoord.y < head.y)
			needDirection = "up";

	if (needCoord.y == head.y)
		if (needCoord.x > head.x)
			needDirection = "right";
		else if (needCoord.x < head.x)
			needDirection = "left";

	if (needCoord.x > head.x)
		if (needCoord.y > head.y)
			needDirection = "down-right";
		else if (needCoord.y < head.y)
			needDirection = "up-right";

	if (needCoord.y > head.y)
		if (needCoord.x > head.x)
			needDirection = "down-right";
		else if (needCoord.x < head.x)
			needDirection = "down-left";

	if (needCoord.x < head.x)
		if (needCoord.y > head.y)
			needDirection = "down-left";
		else if (needCoord.y < head.y)
			needDirection = "up-left";

	if (needCoord.y < head.y)
		if (needCoord.x > head.x)
			needDirection = "up-right";
		else if (needCoord.x < head.x)
			needDirection = "up-left";

	if (needDirection == "down-right")
	{
		if ((lastMove != "up" && lastMove != "left") && (wrongStep1 != "down" && wrongStep1 != "right") &&
			(wrongStep2 != "down" && wrongStep2 != "right") && (wrongStep3 != "down" && wrongStep3 != "right"))
		{
			if (randomNumber(1, 2) == 1)
				needDirection = "down";
			else
				needDirection = "right";
		}
		else
		{
			if (wrongStep1 != "down" && wrongStep2 != "down" && wrongStep3 != "down" && lastMove != "up" )
				needDirection = "down";
			else if (wrongStep1 != "right" && wrongStep2 != "right" && wrongStep3 != "right" && lastMove != "left")
				needDirection = "right";
			else if (wrongStep1 != "left" && wrongStep2 != "left" && wrongStep3 != "left" && lastMove != "right")
				needDirection = "left";
			else
				needDirection = "up";
		}
	}

	if (needDirection == "down-left")
	{
		if ((lastMove != "up" && lastMove != "right") && (wrongStep1 != "down" && wrongStep1 != "left") &&
			(wrongStep2 != "down" && wrongStep2 != "left") && (wrongStep3 != "down" && wrongStep3 != "left"))
		{
			if (randomNumber(1, 2) == 1)
				needDirection = "down";
			else
				needDirection = "left";
		}
		else
		{
			if (wrongStep1 != "down" && wrongStep2 != "down" && wrongStep3 != "down" && lastMove != "up")
				needDirection = "down";
			else if (wrongStep1 != "left" && wrongStep2 != "left" && wrongStep3 != "left" && lastMove != "right")
				needDirection = "left";
			else if (wrongStep1 != "right" && wrongStep2 != "right" && wrongStep3 != "right" && lastMove != "left")
				needDirection = "right";
			else
				needDirection = "up";
		}
	}

	if (needDirection == "up-right")
	{
		if ((lastMove != "down" && lastMove != "left") && (wrongStep1 != "up" && wrongStep1 != "right") &&
			(wrongStep2 != "up" && wrongStep2 != "right") && (wrongStep3 != "up" && wrongStep3 != "right"))
		{
			if (randomNumber(1, 2) == 1)
				needDirection = "up";
			else
				needDirection = "right";
		}
		else
		{
			if (wrongStep1 != "up" && wrongStep2 != "up" && wrongStep3 != "up" && lastMove != "down")
				needDirection = "up";
			else if (wrongStep1 != "right" && wrongStep2 != "right" && wrongStep3 != "right" && lastMove != "left")
				needDirection = "right";
			else if (wrongStep1 != "left" && wrongStep2 != "left" && wrongStep3 != "left" && lastMove != "right")
				needDirection = "left";
			else
				needDirection = "down";
		}
	}

	if (needDirection == "up-left")
	{
		if ((lastMove != "down" && lastMove != "right") && (wrongStep1 != "up" && wrongStep1 != "left") &&
			(wrongStep2 != "up" && wrongStep2 != "left") && (wrongStep3 != "up" && wrongStep3 != "left"))
		{
			if (randomNumber(1, 2) == 1)
				needDirection = "up";
			else
				needDirection = "left";
		}
		else
		{
			if (wrongStep1 != "up" && wrongStep2 != "up" && wrongStep3 != "up" && lastMove != "down")
				needDirection = "up";
			else if (wrongStep1 != "left" && wrongStep2 != "left" && wrongStep3 != "left" && lastMove != "right")
				needDirection = "left";
			else if (wrongStep1 != "right" && wrongStep2 != "right" && wrongStep3 != "right" && lastMove != "left")
				needDirection = "right";
			else
				needDirection = "down";
		}
	}



	if (needDirection == "down")
	{
		step = "down";
		dy = 1; dx = 0;
	}
	if (needDirection == "up")
	{
		step = "up";
		dy = -1; dx = 0;
	}

	if (needDirection == "right")
	{
		step = "right";
		dy = 0; dx = 1;
	}
	if (needDirection == "left")
	{
		step = "left";
		dy = 0; dx = -1;
	}

	//tempC.x += dx;
	//tempC.y += dy;
	if (!(tail.empty()))
	{
		tail.push_front(head);
		tail.pop_back();
	}
	head.x += dx;
	head.y += dy;

	if (!(myMap->thisPlaceFree(head)))
	{
		if (wrongStep1.empty())
			wrongStep1 = needDirection;
		else if (wrongStep2.empty())
			wrongStep2 = needDirection;
		else if (wrongStep3.empty())
			wrongStep3 = needDirection;
		else
			return tempList;
	}
	else if (needCoord == head)
	{
		lastMove = needDirection;
		commands.push_back(step);
		return commands;
	}
	else if (!(isPathRight()))
	{
		if (wrongStep1.empty())
			wrongStep1 = needDirection;
		else if (wrongStep2.empty())
			wrongStep2 = needDirection;
		else if (wrongStep3.empty())
			wrongStep3 = needDirection;
		else
			return tempList;
	}
	else
	{
		string t = lastMove;
		lastMove = needDirection;
		tempList = buildPath();
		if (!(tempList.empty()))
		{
			commands.push_back(step);
			return commands;
		}
		else
		{
			if (wrongStep1.empty())
				wrongStep1 = needDirection;
			else if (wrongStep2.empty())
				wrongStep2 = needDirection;
			else if (wrongStep3.empty())
				wrongStep3 = needDirection;
			else
				return tempList;
			lastMove = t;
		}

	}
	head.x -= dx;
	head.y -= dy;
	if (!(tail.empty()))
	{
		tail.push_back(lastPartTail);
		tail.pop_front();
	}

}while (true);
	
}

bool Sneak::isPathRight()
{
	int result = 0;
	coordin c = head;
	c.x += 1;
	result += myMap->thisPlaceFree(c);
	
	c = head;
	c.x -= 1;
	result += myMap->thisPlaceFree(c);

	c = head;
	c.y += 1;
	result += myMap->thisPlaceFree(c);

	c = head;
	c.y -= 1;
	result += myMap->thisPlaceFree(c);

	if (result != 0)
	{
		return 1;
	}
	else
	{
		return 0;
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

