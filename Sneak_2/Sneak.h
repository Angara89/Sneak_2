#pragma once
#include "common.h"
#include "MyMap.h"

class Sneak
{
private:

	int length;
	char simbolHead;
	char simbolTail;
	int dx;
	int dy;

	list<string> commands;


	list<string> buildPath();
	bool isPathRight();
public:
	coordin head;
	list<coordin> tail;
	int color;
	string lastMove;
	string lastMoveText;
	void drawSneak();
	MyMap* myMap;
	int count1;
	int count2;
	int count3;
	
	Sneak(MyMap& map);
	Sneak(Sneak& sneak);

	list<coordin> tailMemory;
	void usersDecide(int k);
	void moveSneak(bool eatApple = false);

	void decide();
	bool thisPlaceFreeMe(coordin coord);




	int getDY();
	int getDX();
	int getLength();
	coordin getHead();
	list<coordin> getTail();
	void eraseSneak();
	
	
	class SneakDecideEx
	{
	public:
		int iter1;
		int iter2;
		SneakDecideEx(int f, int s)
		{
			iter1 = f;
			iter2 = s;
		}

	};
	friend class MyMap;
};

