#pragma once
#include <vector>
#include "Vector2.h"
#include "Board.h"
#include "Ui.h"
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

struct Move {
	ChessPiece* piece = nullptr;
	Tile* newTile = nullptr;
};

class Board;
class ChessPiece;

class Chess
{
public:
	Chess(Vector2<float> boardSize);
	~Chess();

	void run();
	std::vector<ChessPiece*>& chessPieces();
	Move findBestMove(Player& player);

private:
	void render();

	sf::RenderWindow* _window;
	Player _player;
	Player _computer;
	std::vector<ChessPiece*> _chessPieces;
	Board* _board;
	Controls _controls;
	Ui _ui;
};

