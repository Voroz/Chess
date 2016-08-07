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
	std::vector<Tile*> possibleMoves();
};

