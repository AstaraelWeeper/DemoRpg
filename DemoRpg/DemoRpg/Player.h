#pragma once
#include "People.h"
class Player :
	public People
{
public:
	Player(int, int);
	~Player();
	void Attack();
};

