#pragma once
#include "People.h"
class Player :
	public People
{
public:
	Player(short column, short row);
	~Player();
	void Attack();
	int GetXPosition();
	int GetYPosition();
};

