#pragma once
#include <vector>
#include "Vector2.h"
#include "Board.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Pawn.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

class Chess
{
public:
	Chess(Vector2<float> boardSize);
	~Chess();

	void run();
	int spawnPiece(ChessPiece* piece, Tile* tile);
	void swapPieces(Tile* tile1, Tile* tile2);
	void swapPieces(ChessPiece& piece1, ChessPiece& piece2);

private:
	void render();

	sf::RenderWindow* _window;
	std::vector<ChessPiece*> _chessPieces;
	Board _board;
};

