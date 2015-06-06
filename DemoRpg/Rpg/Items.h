#pragma once

#include <SDL.h>
class Items //chests, vases and doors
{
public:
	
	Items(short column,short row);
	~Items(void);
	SDL_Rect GetAssetSheetPosition();
	SDL_Rect GetMapPosition();

protected:
	SDL_Rect assetSheetPosition;
	SDL_Rect mapPosition;

	short tilePositionColumn;//tiles, out of 32 
	short tilePositionRow;//tiles, out of 24
};