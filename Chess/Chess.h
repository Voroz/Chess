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

class Board;
class ChessPiece;

class Chess
{
public:
	Chess(Vector2<float> boardSize);
	~Chess();

	void run();
	std::vector<ChessPiece*>& chessPieces();
	std::vector<ChessPiece*>& activeChessPieces();
	std::vector<ChessPiece*>& inactiveChessPieces();
	std::vector<Move> findBestMove(Player& player);
	Tile* mouseOnTile();
	void update();

private:
	void render();

	sf::RenderWindow* _window;
	ChessPiece* _draggedPiece;
	Player _player;
	Player _computer;
	std::vector<ChessPiece*> _activeChessPieces;
	std::vector<ChessPiece*> _inactiveChessPieces;
	Board _board;
	Controls _controls;
};

