#include "Player.h"


Player::Player(int x, int y)
{
    mapPositionX = x;
	mapPositionY = y;
	damage = 5;
	maxHealth = 35;
}


Player::~Player()
{
}


void Player::Attack()
{
	attackState = true;
}

