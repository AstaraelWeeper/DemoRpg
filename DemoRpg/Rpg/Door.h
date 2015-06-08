#pragma once
#include "items.h"

class Door :
	public Items
{
public:
	Door(short column, short row,bool boss); //did this have to be defined again in door.cpp?
	~Door(void);
	bool Open();
	bool opened;
	SDL_Rect visibleArea; //unsure how to do this.

protected:
	bool bossDoor;

};