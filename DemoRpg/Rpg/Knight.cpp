#include "Knight.h"


Knight::Knight(short column, short row) :Enemy(column,row)
{
	maxHealth = 30;
	damage = 5;
}


Knight::~Knight(void)
{
}
