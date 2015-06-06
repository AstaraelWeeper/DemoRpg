#pragma once
class Projectile
{
public:
	Projectile(int,int);
	~Projectile(void);
	int mapPositionX;
	int mapPositionY;
	void Move();
	int CalculateAttack();
};

