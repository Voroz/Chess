#pragma once
#include "ChessPiece.h"

class Bishop :
	public ChessPiece
{
public:
	Bishop(sf::Texture& texture, Tile* tile, Player& owner);
	~Bishop();

	CpType identify();
	std::vector<Move> possibleMoves(std::array<std::array<Tile*, 8>, 8> tiles);
};

