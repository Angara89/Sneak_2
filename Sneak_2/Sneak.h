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





	void drawSneak();
public:
	MyMap* myMap;

	Sneak(MyMap& map);



	void usersDecide(int k);
	void moveSneak(bool eatApple = false);






	int getDY();
	int getDX();
	int getLength();
	coordin getHead();
	list<coordin> getTail();
	
	
	
	
	friend class MyMap;
};

