#include "Chest.h"


Chest::Chest(short column, short row, bool key) : Items(column,row)
{
	tilePositionColumn = column;
	tilePositionRow = row;
	assetSheetPosition = //check on sheet
    hasKey = key;
	opened = false;
}


Chest::~Chest()
{
}
