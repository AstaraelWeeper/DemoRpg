#pragma once
#include "People.h"
class Enemy :
	public People
{
public:
	Enemy();
	~Enemy();
	void Attack();
	void CompleteAttack();
	void FindMoveDirection(); //strings don't like switch. Translate the move input direction into an int
protected:
	
};

