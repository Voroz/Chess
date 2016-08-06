#pragma once
#include "Board.h"
#include "Controls.h"



class Ui
{
public:
	Ui(Board* boardPtr, Controls &controls);
	~Ui();

	Tile* mouseOnTile();

private:
	Board* _boardPtr;
	Controls& _controls;
};

