#pragma once
#include "common.h"
#include "MyMap.h"

class Sneak
{
private:
	coordin head;
	list<coordin> tail;
	int length;
	char simbolHead;
	char simbolTail;
	int color;
	int dx;
	int dy;

	list<string> commands;


	list<string> buildPath();
	bool isPathRight();
public:
	string lastMove;
	string lastMoveText;
	void drawSneak();
	MyMap* myMap;
	int count1;
	Sneak(MyMap& map);
	Sneak(Sneak& sneak);


	void usersDecide(int k);
	void moveSneak(bool eatApple = false);

	void decide();





	int getDY();
	int getDX();
	int getLength();
	coordin getHead();
	list<coordin> getTail();
	
	
	
	
	friend class MyMap;
};

