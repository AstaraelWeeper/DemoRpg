#include "Door.h"
Door::Door(char column, char row, bool boss) : Items(column,row)
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