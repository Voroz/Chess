#pragma once
#include <vector>
#include "Vector2.h"
#include "Board.h"
#include "Controls.h"
#include "ChessPiece.h"
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
#include "Move.h"
#include <vector>

class Board;
class ChessPiece;

class Chess
{
public:
	Chess(Vector2<float> boardSize);
	~Chess();

	void run();
	void findBestMove(Player* player, int depth);
	Tile* mouseOnTile();
	void update();

private:
	void render();

	std::vector<ChessPiece*> _chessPieces;
	sf::RenderWindow* _window;
	ChessPiece* _draggedPiece;
	Player _player;
	Player _computer;
	Player* _lastMovedPlayer;
	Board _board;
	Controls _controls;
};

