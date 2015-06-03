#pragma once
#include "Items.h"
class Chest : Items
{
public:
	Chest(int column, int row);
	~Chest();
	bool opened;
};

