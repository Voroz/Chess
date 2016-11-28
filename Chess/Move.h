#pragma once
#include "ChessPiece.h"
#include "Tile.h"

class ChessPiece;
class Tile;

struct Move {
	Move() :
		fromTile(nullptr),
		toTile(nullptr) {

	}
	Move(Tile* from, Tile* to) :
		fromTile(from),
		toTile(to){

	}
	Tile* fromTile;
	Tile* toTile;
};