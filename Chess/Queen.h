#pragma once
#include "ChessPiece.h"
#include "Player.h"

class Queen :
	public ChessPiece
{
public:
	Queen(sf::Texture& texture, Tile* tile, Player& owner);
	~Queen();

	CpType identify();
	std::vector<Move> possibleMoves(std::array<std::array<Tile*, 8>, 8> tiles);
};

