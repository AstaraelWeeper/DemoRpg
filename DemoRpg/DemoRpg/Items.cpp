#include "Items.h"

Items::Items(char column, char row)
{
	tilePositionColumn = column;
	tilePositionRow = row;
	mapPosition = { tilePositionColumn * 32, tilePositionRow * 32, 32, 32 };
}

SDL_Rect Items::GetAssetSheetPosition
{
	return assetSheetPosition;
}

SDL_Rect Items::GetMapPosition()
{
	return mapPosition;
}