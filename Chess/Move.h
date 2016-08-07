#pragma once
#include "ChessPiece.h"
#include "Tile.h"

class ChessPiece;
class Tile;

struct Move {
	ChessPiece* piece = nullptr;
	Tile* newTile = nullptr;
};