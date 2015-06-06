#pragma once
#include "Items.h"
class Chest : Items
{
public:
	Chest(short column, short row);
	~Chest();
	bool opened;
};

