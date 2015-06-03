#pragma once

class People
{
public:
	People();
	People(int, int);
	virtual ~People();
	virtual int attackCalculation();
	virtual void Attack();
	void UpdateHealth(int);
	void Move(int);
    int mapPositionX; //pixels, not tiles
	int mapPositionY; //pixels, not tiles



protected:
	
	bool attackState; 
	int hitChance; //int between 0 and 100 to represent % chance of hitting
	int maxHealth;
	int currentHealth;
	int damage;
	int facingDirection; //1=left, 2= up, 3 = right, 4 = down

enum KeyPressDirections
 {
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_LEFT,
    KEY_PRESS_UP,
    KEY_PRESS_RIGHT,
    KEY_PRESS_DOWN,
 };
};

