#pragma once
#include "ChessPiece.h"

class Pawn :
	public ChessPiece
{
public:
	Pawn(sf::Texture& texture, Tile* tile, Player& owner);
	~Pawn();

	std::vector<Tile*> possibleMoves();

private:
	Tile* _startTile;
};

