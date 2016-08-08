#pragma once
#include "Tile.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Player.h"

enum CpType {
	PawnT = 0,
	BishopT,
	KnightT,
	RookT,
	QueenT,
	KingT,
};

class Tile;
class Player;

class ChessPiece
{
public:
	friend class Board;
	friend class Chess;
	ChessPiece(sf::Texture& texture, Tile* tile, Player& owner);
	~ChessPiece();
	void update();
	void render(sf::RenderWindow &window);
	int move(Tile* tile);
	sf::Sprite& sprite();
	Player& owner();
	int value();
	Tile* currTile();
	virtual std::vector<Tile*> possibleMoves() = 0;
	virtual CpType identify() = 0;

protected:
	Player& _owner;
	Tile* _currTile;
	Tile* _startTile;
	sf::Sprite _sprite;
	int _value;
};

