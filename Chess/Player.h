#pragma once
#include <vector>
#include "ChessPiece.h"
#include "MoveDir.h"
#include "Move.h"

class ChessPiece;

class Player
{
public:
	Player(MoveDir moveDir, std::vector<ChessPiece*>& activeChessPieces);
	~Player();
	MoveDir moveDir();
	std::vector<ChessPiece*> chessPieces();
	std::vector<Move> possibleMoves();
	int score();

private:
	MoveDir _moveDir;
	std::vector<ChessPiece*>& _chessPieces;
};

