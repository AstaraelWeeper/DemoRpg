#pragma once
#include "items.h"

class Door :
	public Items
{
public:
	Door(char column, char row,bool boss) :Items(column, row){}; //did this have to be defined again in door.cpp?
	~Door(void);
	bool Open();
	bool opened;
	SDL_Rect visibleArea; //unsure how to do this.

protected:
	bool bossDoor;

};