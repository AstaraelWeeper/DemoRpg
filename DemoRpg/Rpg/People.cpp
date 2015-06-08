#include "People.h"
#include <random>
 
People::People(short x, short y)
{
	attackState = 0;
	mapPositionX = x*32;
	mapPositionY = y*32;
	mapPosition = { mapPositionX, mapPositionY, 32, 32 };
}


People::~People()
{
}

int People::GetFacingDirection()
{
	return facingDirection;
}
int People::attackCalculation()
{
   std::random_device rd;     // only used once to initialise (seed) engine
   std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
   std::uniform_int_distribution<int> uni(0,100); // guaranteed unbiased
   auto random_integer = uni(rng);

   if(random_integer > (100-hitChance))
   {
	   return damage;
   }
   else
   {
	   return 0;
   }
}

void People::UpdateHealth(int damage)
{
	currentHealth -=damage;
}

SDL_Rect People::GetAssetSheetPosition()
{
	if (attackState==0)
	{
		switch (facingDirection)
		{
		case 1:
			return assetSheetPositionLeft;
		case 2:
			return assetSheetPositionUp;
		case 3:
			return assetSheetPositionRight;
		case 4:
			return assetSheetPositionDown;
		}
	}
	else if(attackState ==1) //sword up
	{
		switch (facingDirection)
		{
		case 1:
			return assetSheetPositionLeftAttack1;
		case 2:
			return assetSheetPositionUpAttack1;
		case 3:
			return assetSheetPositionRightAttack1;
		case 4:
			return assetSheetPositionDownAttack1;
		}
	}
	else if (attackState == 2) 
	{
		switch (facingDirection)
		{
		case 1:
			return assetSheetPositionLeftAttack2;
		case 2:
			return assetSheetPositionUpAttack2;
		case 3:
			return assetSheetPositionRightAttack2;
		case 4:
			return assetSheetPositionDownAttack2;
		}
	}
}

SDL_Rect People::GetMapPosition()
{
	return mapPosition;
}

void People::Move(int direction)
{
	facingDirection = direction;
	if(!attackState) //shouldn't move while attacking
	{
		switch(direction)
		{
		case 1: //left
			People::mapPositionX -= 3;
			break;
		case 2: //up
			People::mapPositionY -=3;
			break;
		case 3: //right
			People::mapPositionX += 3;
			break;
		case 4: //down
			People::mapPositionY += 3;
			break;
		}

	}
}