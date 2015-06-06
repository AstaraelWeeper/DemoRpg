#pragma once
#include "items.h"

class Vase :
	public Items
{
public:
	Vase(short column, short row);
	~Vase(void);
	int Update();
	int health;
private:
	int givesHealth;
};