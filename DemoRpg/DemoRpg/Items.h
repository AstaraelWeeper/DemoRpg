#pragma once
class Items //chests, vases and doors

{

public:

	Items();

	Items(int column,int row);

	~Items(void);

	SDL_Rect GetAssetSheetPosition();
	SDL_Rect GetMapPosition();

protected:
	SDL_Rect assetSheetPosition;
	SDL_Rect mapPosition;

	int tilePositionColumn;//tiles, out of 32 

	int tilePositionRow;//tiles, out of 24
};