#include "Projectile.h"


Projectile::Projectile(int positionX, int positionY)
{
	mapPositionX = positionX;
	mapPositionY = positionY;
}


Projectile::~Projectile(void)
{
}

void Projectile::Move()
{
	//towards player.
	if(true)//detect collision. Doesn't need to be over two frames like enemies.
	{
		Projectile::CalculateAttack();
	}

}