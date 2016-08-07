#pragma once
#include "ChessPiece.h"

class Rook :
	public ChessPiece
{
public:
	Rook(sf::Texture& texture, Tile* tile, Player& owner);
	~Rook();

	CpType identify();
	std::vector<Tile*> possibleMoves();
};


