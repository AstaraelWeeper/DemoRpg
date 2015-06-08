#include "Player.h"


Player::Player(short column, short row):People(column,row)
{
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


int Player::GetXPosition()
{
	return mapPositionX;
}

int Player::GetYPosition()
{
	return mapPositionY;
}
