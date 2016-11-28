#pragma once
#include "ChessPiece.h"
#include "Tile.h"

class ChessPiece;
class Tile;

struct Move {
	Move(Tile* from, Tile* to) :
		fromTile(from),
		toTile(to){

	}
	Tile* fromTile = nullptr;
	Tile* toTile = nullptr;
};