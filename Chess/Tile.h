#pragma once
#include "Board.h"
#include "ChessPiece.h"
#include "Vector2.h"
#include "SFML/Graphics.hpp"

class Board;
class ChessPiece;

class Tile
{
public:
	friend class Board;
	friend class Chess;
	friend class ChessPiece;
	Tile(Board& boardPtr);
	~Tile();
	ChessPiece* holding();
	Board& board();
	Vector2<int> index();
	bool contains(Vector2<float> point);
	void syncShape();
	void render(sf::RenderWindow &window);

private:
	Board& _boardPtr;
	ChessPiece* _currPiece;
	Vector2<int> _index;
	Vector2<float> _pos;
	Vector2<float> _size;
	sf::RectangleShape _rectShape;
};

