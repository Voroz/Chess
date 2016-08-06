#pragma once
#include "ChessPiece.h"

class Bishop :
	public ChessPiece
{
public:
	Bishop(sf::Texture& texture, Tile* tile, Player& owner);
	~Bishop();

	std::vector<Tile*> possibleMoves();
};

