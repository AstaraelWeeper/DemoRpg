#pragma once
#include "Enemy.h"
class Boss :
	public Enemy
{
public:
	Boss(void);
	~Boss(void);
	void CheckAttackRange();
	void FacePlayer();
	void Move();

	int attackCalculation();
};

