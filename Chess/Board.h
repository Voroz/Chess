#pragma once
#include "Tile.h"
#include <vector>
#include <array>
#include "Vector2.h"
#include "SFML\Graphics.hpp"

class Tile;

class Board
{
public:
	friend class Chess;
	Board(Vector2<float> size);
	~Board();

	void initTiles();
	std::array<std::array<Tile*, 8>, 8> tiles();
	void render(sf::RenderWindow &window);

private:
	std::array<std::array<Tile*, 8>, 8> _tiles;
	Vector2<float> _size;
};

