#pragma once
#include "ChessPiece.h"

class King :
	public ChessPiece
{
public:
	King(sf::Texture& texture, Tile* tile, Player& owner);
	~King();

	CpType identify();
	std::vector<Tile*> possibleMoves();
};

