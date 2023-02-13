#pragma once
#include "common.h"



class Apple
{
private:
	coordin coord;
	int color;
	char simbol;

public:
	Apple();

	void drawApple();
	
	
	
	
	
	
	
	coordin getCoord();

	friend class MyMap;
};

