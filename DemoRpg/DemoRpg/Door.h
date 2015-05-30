#pragma once
#include "items.h"

class Door :
	public Items
{
public:
	Door(char column, char row) :Items(column, row){};
	~Door(void);
	bool Open();
};