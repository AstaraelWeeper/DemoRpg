#include "Vase.h"

Vase::Vase(short column, short row) :Items(column, row)
{
	health = 1;
	tilePositionColumn = column;
	tilePositionRow = row;
	//assetSheetPosition = null;
}

int Vase::Update()
{
	
}