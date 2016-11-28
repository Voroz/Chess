#pragma once
#include "Tile.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Player.h"
#include <assert.h>
#include "Move.h"
#include "Vector2.h"

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
	void render(sf::RenderWindow &window, Vector2<int> pos, Vector2<int> size);
	bool move(Tile* tile, std::array<std::array<Tile*, 8>, 8> tiles);
	sf::RectangleShape& sprite();
	Player& owner();
	int value();
	virtual std::vector<Move> possibleMoves(std::array<std::array<Tile*, 8>, 8> tiles) = 0;
	virtual CpType identify() = 0;
	bool active();
	void setActive(bool active);

protected:
	Player& _owner;
	sf::RectangleShape _sprite;
	int _value;
	bool _active;
	Tile* _startTile;
	// Todo: Add _currentTile back again (for performance)
};

