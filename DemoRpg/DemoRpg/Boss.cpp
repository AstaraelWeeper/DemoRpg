#include "Boss.h"
#include "Projectile.h"


Boss::Boss(void)
{
	maxHealth = 50;
	damage = 0;
}


Boss::~Boss(void)
{
}

void Boss::CheckAttackRange()
{

}
int Boss::attackCalculation()
{
	int spawnPointX, spawnPointY;
	switch(facingDirection) 
	{
	case 1: //left
		{
			spawnPointX = mapPositionX - 32;
			spawnPointY = mapPositionY;
			break;
		}
	case 2: //up
		{
			spawnPointX = mapPositionX;
			spawnPointY = mapPositionY - 32;
			break;
		}
	case 3://right
		{
			spawnPointX = mapPositionX + 32;
			spawnPointY = mapPositionY;
			break;
		}
	case 4: //down
		{
			spawnPointX = mapPositionX;
			spawnPointY = mapPositionY + 32;
			break;
		}
	}
	Projectile projectile = new Projectile(spawnPointX, spawnPointY); //need correct syntax for this
	return 0;
}
