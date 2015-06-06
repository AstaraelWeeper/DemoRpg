#include "Knight.h"


Knight::Knight(short column, short row) :Enemy(column,row)
{
	maxHealth = 30;
	damage = 5;
	attackRange = 32;
}


Knight::~Knight(void)
{
}
