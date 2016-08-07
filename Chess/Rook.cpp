#include "Rook.h"



Rook::Rook(sf::Texture& texture, Tile* tile, Player& owner) :
	ChessPiece(texture, tile, owner)
{
	_value = 5;
	_sprite.setTextureRect(sf::IntRect(1355, 0, 212, 265));
	update();
}

Rook::~Rook() {

}
std::vector<Tile*> Rook::possibleMoves() {
	std::vector<Tile*> tempVec;
	std::array<std::array<Tile*, 8>, 8> tiles = _currTile->board()->tiles();
	Vector2<int> index = _currTile->index();

	// Left
	Vector2<int> testIndex = Vector2<int>(index.x - 1, index.y);
	while (testIndex.x >= 0 &&
		tiles[testIndex.x][testIndex.y]->holding() == nullptr) {

		tempVec.push_back(tiles[testIndex.x][testIndex.y]);
		testIndex.x--;
	}
	if (testIndex.x >= 0 &&
		tiles[testIndex.x][testIndex.y]->holding() != nullptr &&
		&tiles[testIndex.x][testIndex.y]->holding()->owner() != &_owner) {
		tempVec.push_back(tiles[testIndex.x][testIndex.y]);
	}

	// Right
	testIndex = Vector2<int>(index.x + 1, index.y);
	while (testIndex.x < 8 &&
		tiles[testIndex.x][testIndex.y]->holding() == nullptr) {

		tempVec.push_back(tiles[testIndex.x][testIndex.y]);
		testIndex.x++;
	}
	if (testIndex.x < 8 &&
		tiles[testIndex.x][testIndex.y]->holding() != nullptr &&
		&tiles[testIndex.x][testIndex.y]->holding()->owner() != &_owner) {
		tempVec.push_back(tiles[testIndex.x][testIndex.y]);
	}

	// Top
	testIndex = Vector2<int>(index.x, index.y - 1);
	while (testIndex.y >= 0 &&
		tiles[testIndex.x][testIndex.y]->holding() == nullptr) {

		tempVec.push_back(tiles[testIndex.x][testIndex.y]);
		testIndex.y--;
	}
	if (testIndex.y >= 0 &&
		tiles[testIndex.x][testIndex.y]->holding() != nullptr &&
		&tiles[testIndex.x][testIndex.y]->holding()->owner() != &_owner) {
		tempVec.push_back(tiles[testIndex.x][testIndex.y]);
	}

	// Bottom
	testIndex = Vector2<int>(index.x, index.y + 1);
	while (testIndex.y < 8 &&
		tiles[testIndex.x][testIndex.y]->holding() == nullptr) {

		tempVec.push_back(tiles[testIndex.x][testIndex.y]);
		testIndex.y++;
	}
	if (testIndex.y < 8 &&
		tiles[testIndex.x][testIndex.y]->holding() != nullptr &&
		&tiles[testIndex.x][testIndex.y]->holding()->owner() != &_owner) {
		tempVec.push_back(tiles[testIndex.x][testIndex.y]);
	}

	return tempVec;
}