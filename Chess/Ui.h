#pragma once
#include "Board.h"
#include "Controls.h"
#include "ChessPiece.h"



class Ui
{
public:
	Ui(Board* boardPtr, Controls &controls);
	~Ui();

	Tile* mouseOnTile();
	void update();
	void render(sf::RenderWindow &window);

private:
	ChessPiece* _draggedPiece;
	Board* _boardPtr;
	Controls& _controls;
};

