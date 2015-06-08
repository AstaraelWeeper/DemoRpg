#include "Door.h"
Door::Door(short column, short row, bool boss) : Items(column,row)
{
    tilePositionColumn = column;
	tilePositionRow = row;
	bossDoor = boss;
	if(!bossDoor)
	{
		assetSheetPosition =
	}
	else
	{
		assetSheetPosition =
	}
}