#pragma once
#include "Tile.h"
#include <vector>
#include <array>
#include "Vector2.h"
#include "SFML\Graphics.hpp"

class Chess;
class Tile;

class Board
{
public:
	friend class Chess;
	Board(Vector2<float> size, Chess* chessPtr);
	~Board();

	void initTiles();
	Chess* chess();
	std::array<std::array<Tile*, 8>, 8>& tiles();
	void render(sf::RenderWindow &window);

private:
	Chess* _chessPtr;
	std::array<std::array<Tile*, 8>, 8> _tiles;
	Vector2<float> _size;
};

