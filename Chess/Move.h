#pragma once
#include "ChessPiece.h"
#include "Tile.h"

class ChessPiece;
class Tile;

struct Move {
	Tile* fromTile = nullptr;
	Tile* toTile = nullptr;
};