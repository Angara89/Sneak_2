#pragma once
#include "common.h"
#include "Apple.h"
#include "Sneak.h"



class MyMap
{
private:

	vector<Sneak*> sneaks;
	int height;
	int width;
	coordin leftUpCorrner;



public:
	bool gameContinue;
	Apple* apple;

	MyMap(int height, int width, int colorWall,
		coordin leftUpCorrner, char fillSimbol = ' ');
	~MyMap();

	void pushSneak(Sneak& sneak);
	void putApple();
	bool thisPlaceFree(coordin coord);











	bool getGameContinue();
	coordin getLeftUpCorrner();
	int getWidth();
	int getHeight();

	friend class Sneak;
};

