#pragma once
#include "Enemy.h"
class Boss :
	public Enemy
{
public:
	Boss(short column, short row);
	~Boss(void);
	void CheckAttackRange();
	void FacePlayer();
	void Move();

	int attackCalculation();
};

