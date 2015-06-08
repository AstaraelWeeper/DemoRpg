#pragma once
#include "People.h"
class Enemy :
	public People
{
public:
	Enemy(short column, short row);
	~Enemy();
	void Attack();
	void CompleteAttack();
	void FindMoveDirection(); //strings don't like switch. Translate the move input direction into an int
	bool visible; //translate to an alpha value in main
protected:
	int attackRange; //proximity needed to attack
};

