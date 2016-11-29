#pragma once
#include <vector>
#include "ChessPiece.h"
#include "MoveDir.h"
#include "Move.h"

class ChessPiece;

class Player
{
public:
	Player(MoveDir moveDir);
	~Player();
	MoveDir moveDir();
	std::vector<ChessPiece*> activeChessPieces(std::array<std::array<Tile*, 8>, 8> tiles);
	std::vector<Move> possibleMoves(std::array<std::array<Tile*, 8>, 8> tiles);
	int score(std::array<std::array<Tile*, 8>, 8> tiles);

	// TODO: don't save these here (temp solution to get findBestMove to work)
	int _bestScore;
	Move _bestMove;
	std::vector<Move> _moves;

private:
	MoveDir _moveDir;
};

