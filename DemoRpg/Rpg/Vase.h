#pragma once
#include "items.h"

class Vase :
	public Items
{
public:
	Vase(char column, char row) :Items(column, row){};
	~Vase(void);
	int Update();
	int health;
private:
	int givesHealth;
};