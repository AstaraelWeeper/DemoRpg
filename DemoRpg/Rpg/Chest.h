#pragma once
#include "Items.h"
class Chest : Items
{
public:
	Chest(short column, short row, bool key);
	~Chest();
	bool opened;
	bool hasKey;
};

