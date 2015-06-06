#pragma once

#include <SDL.h>

class People
{
public:
	People(short column, short row);
	virtual ~People();
	virtual int attackCalculation();
	virtual void Attack();
	void UpdateHealth(int);
	void Move(int);
    SDL_Rect GetAssetSheetPosition();
	SDL_Rect GetMapPosition();

protected:
	int attackState; 
	int hitChance; //int between 0 and 100 to represent % chance of hitting
	int maxHealth;
	int currentHealth;
	int damage;
	int facingDirection; //1=left, 2= up, 3 = right, 4 = down
	SDL_Rect assetSheetPositionLeft;
	SDL_Rect assetSheetPositionUp;
	SDL_Rect assetSheetPositionRight;
	SDL_Rect assetSheetPositionDown;
	SDL_Rect assetSheetPositionLeftAttack1;
	SDL_Rect assetSheetPositionUpAttack1;
	SDL_Rect assetSheetPositionRightAttack1;
	SDL_Rect assetSheetPositionDownAttack1;
	SDL_Rect assetSheetPositionLeftAttack2;
	SDL_Rect assetSheetPositionUpAttack2;
	SDL_Rect assetSheetPositionRightAttack2;
	SDL_Rect assetSheetPositionDownAttack2;
    int mapPositionX; //pixels, not tiles
	int mapPositionY; //pixels, not tiles
	SDL_Rect mapPosition;

enum KeyPressDirections
 {
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_LEFT,
    KEY_PRESS_UP,
    KEY_PRESS_RIGHT,
    KEY_PRESS_DOWN,
 };
};

