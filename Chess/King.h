#pragma once
#include "ChessPiece.h"

class King :
	public ChessPiece
{
public:
	King(sf::Texture& texture, Tile* tile, Player& owner);
	~King();

	CpType identify();
	std::vector<Move> possibleMoves(std::array<std::array<Tile*, 8>, 8> tiles);
};

