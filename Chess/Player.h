#pragma once
#include <vector>
#include "ChessPiece.h"
#include "MoveDir.h"
#include "Move.h"

class ChessPiece;

class Player
{
public:
	Player(MoveDir moveDir, std::vector<ChessPiece*>& chessPieces);
	~Player();
	MoveDir moveDir();
	std::vector<ChessPiece*> chessPieces();
	std::vector<Move> possibleMoves();

private:
	MoveDir _moveDir;
	std::vector<ChessPiece*>& _chessPieces;
};

