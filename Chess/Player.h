#pragma once
#include <vector>
#include "ChessPiece.h"
#include "MoveDir.h"

class ChessPiece;

class Player
{
public:
	Player(MoveDir moveDir, std::vector<ChessPiece*>& chessPieces);
	~Player();
	MoveDir moveDir();
	std::vector<ChessPiece*> chessPieces();

private:
	MoveDir _moveDir;
	std::vector<ChessPiece*>& _chessPieces;
};

