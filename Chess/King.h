#pragma once
#include "ChessPiece.h"

class King :
	public ChessPiece
{
public:
	King(sf::Texture& texture, Tile* tile, Player& owner);
	~King();

	std::vector<Tile*> possibleMoves();
};

