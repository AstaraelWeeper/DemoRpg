#include "Enemy.h"


Enemy::Enemy(short column, short row) :People(column,row)
{
	attackRange = 32;
	visible = true;
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

bool colliding=false; 
	//best way to test? rectangle? 
	if(colliding)
	{
        int damageGiven = Enemy::attackCalculation();//need to ensure it returns the enemy damage not people damage
		//Player::UpdateHealth(damageGiven);		//do this in the game loop.
		attackState = false;
	}
}

