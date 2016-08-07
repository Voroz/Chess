#include "Pawn.h"



Pawn::Pawn(sf::Texture& texture, Tile* tile, Player& owner) :
	ChessPiece(texture, tile, owner)
{
	_value = 1;
	_sprite.setTextureRect(sf::IntRect(1700, 0, 183, 265));
	update();
}

Pawn::~Pawn() {

}

CpType Pawn::identify() {
	return CpType::PawnT;
}
std::vector<Tile*> Pawn::possibleMoves() {
	std::vector<Tile*> tempVec;
	std::array<std::array<Tile*, 8>, 8> tiles = _currTile->board()->tiles();
	Vector2<int> index = _currTile->index();
	MoveDir moveDir = _owner.moveDir();
	// If we havent moved and there is nothing blocking us, we can move forward 1 or 2 steps
	if (_currTile == _startTile) {
		if (index.y + 1 * moveDir < 8 && index.y + 1 * moveDir >= 0 &&
			tiles[index.x][index.y + 1 * moveDir]->holding() == nullptr) {
			tempVec.push_back(tiles[index.x][index.y + 1 * moveDir]);
			if (index.y + 2 * moveDir < 8 && index.y + 2 * moveDir >= 0 &&
				tiles[index.x][index.y + 2 * moveDir]->holding() == nullptr) {
				tempVec.push_back(tiles[index.x][index.y + 2 * moveDir]);
			}
		}
	}

	// If nothing is blocking us and we're not on starting pos, we can move forward 1 step
	else if (index.y + 1 * moveDir < 8 && index.y + 1 * moveDir >= 0 && 
		tiles[index.x][index.y + 1 * moveDir]->holding() == nullptr){
		tempVec.push_back(tiles[index.x][index.y + 1 * moveDir]);
	}

	// If there is an enemy chesspiece moveDir left or moveDir right, we can move there.
	if (index.x - 1 >= 0 && 
		index.y + 1 * moveDir < 8 && index.y + 1 * moveDir >= 0 &&
		tiles[index.x - 1][index.y + 1 * moveDir]->holding() != nullptr &&
		&tiles[index.x - 1][index.y + 1 * moveDir]->holding()->owner() != &_owner) {
		tempVec.push_back(tiles[index.x - 1][index.y + 1 * moveDir]);
	}
	if (index.x + 1 < 8 &&
		index.y + 1 * moveDir < 8 && index.y + 1 * moveDir >= 0 && 
		tiles[index.x + 1][index.y + 1 * moveDir]->holding() != nullptr &&
		&tiles[index.x + 1][index.y + 1 * moveDir]->holding()->owner() != &_owner) {
		tempVec.push_back(tiles[index.x + 1][index.y + 1 * moveDir]);
	}
	/*...*/
	return tempVec;
}