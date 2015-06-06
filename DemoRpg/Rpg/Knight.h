#pragma once
#include "enemy.h"
class Knight :
	public Enemy
{
public:
	Knight(short column, short row);
	~Knight(void);
};

