#pragma once
#include "ChessPiece.h"

class Knight :
	public ChessPiece
{
public:
	Knight(sf::Texture& texture, Tile* tile, Player& owner);
	~Knight();

	CpType identify();
	std::vector<Move> possibleMoves(std::array<std::array<Tile*, 8>, 8> tiles);
};

