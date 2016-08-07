#pragma once
#include "ChessPiece.h"

class Pawn :
	public ChessPiece
{
public:
	Pawn(sf::Texture& texture, Tile* tile, Player& owner);
	~Pawn();

	CpType identify();
	std::vector<Tile*> possibleMoves();

private:

};

