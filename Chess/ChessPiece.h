#pragma once
#include "Tile.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Player.h"

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
	void move(Tile* tile);
	sf::Sprite& sprite();
	Player& owner();
	virtual std::vector<Tile*> possibleMoves() = 0;

protected:
	Player& _owner;
	Tile* _currTile;
	sf::Sprite _sprite;
	int _value;
};

