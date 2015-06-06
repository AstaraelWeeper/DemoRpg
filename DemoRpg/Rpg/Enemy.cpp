#include "Enemy.h"


Enemy::Enemy()
{
	maxHealth = 30;
	damage = 5;
}


Enemy::~Enemy()
{
}

void Enemy::Attack() //expect you are colliding if in an attack state but best to check!
{
	
		Enemy::attackState = true;
}

void Enemy::CompleteAttack()
{

bool colliding; 
	//best way to test? rectangle? 
	if(colliding)
	{
        int damageGiven = Enemy::attackCalculation();//need to ensure it returns the enemy damage not people damage
		Player::UpdateHealth(damageGiven);		//do this in the game loop.
		attackState = false;
	}
}

