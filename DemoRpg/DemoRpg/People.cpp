#include "People.h"
#include <random>
 
People::People(int x, int y)
{
	mapPositionX = x;
	mapPositionY = y;
}


People::~People()
{
}


int People::attackCalculation()
{
   std::random_device rd;     // only used once to initialise (seed) engine
   std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
   std::uniform_int_distribution<int> uni(0,100); // guaranteed unbiased
   auto random_integer = uni(rng);

   if(random_integer > (100-hitChance))
   {
	   attackState = false;
	   return damage;
   }
   else
   {
	   attackState = false;
	   return 0;
   }
}

void People::UpdateHealth(int damage)
{
	currentHealth -=damage;
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