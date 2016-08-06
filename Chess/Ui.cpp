#include "Ui.h"



Ui::Ui(Board* boardPtr, Controls &controls) :
	_boardPtr(boardPtr),
	_controls(controls)
{

}
Ui::~Ui(){

}

Tile* Ui::mouseOnTile() {
	std::array<std::array<Tile*, 8>, 8>& tiles = _boardPtr->tiles();
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			if (tiles[x][y]->contains(_controls._mousePos)) {
				return tiles[x][y];
			}
		}
	}
	return nullptr;
}