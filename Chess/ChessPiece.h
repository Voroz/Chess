#pragma once
#include "Tile.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Player.h"

class Tile;

class ChessPiece
{
public:
	friend class Board;
	friend class Chess;
	ChessPiece(sf::Texture& texture, Tile* tile, Player& owner);
	~ChessPiece();
	void update();
	void render(sf::RenderWindow &window);
	virtual std::vector<Tile*> possibleMoves() = 0;

protected:
	Player& _owner;
	Tile* _currTile;
	sf::Sprite _sprite;
};

