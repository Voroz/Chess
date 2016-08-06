#pragma once
#include "ChessPiece.h"

class Knight :
	public ChessPiece
{
public:
	Knight(sf::Texture& texture, Tile* tile, Player& owner);
	~Knight();

	std::vector<Tile*> possibleMoves();
};

