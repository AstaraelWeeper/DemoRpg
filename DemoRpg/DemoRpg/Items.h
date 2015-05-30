#pragma once
class Items //chests and vases

{

public:

	Items(char column, char row);

	~Items(void);

	bool opened;

	char staticPositionColumn;//out of 32 

	char staticPositionRow;//out of 24

protected:

	int Health;

};