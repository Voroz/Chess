#include "Bishop.h"



Bishop::Bishop(sf::Texture& texture, Tile* tile, Player& owner) :
	ChessPiece(texture, tile, owner)
{
	_value = 3;
	_sprite.setTextureRect(sf::IntRect(667, 0, 256, 265));
}

Bishop::~Bishop() {

}

CpType Bishop::identify() {
	return CpType::BishopT;
}
std::vector<Move> Bishop::possibleMoves(std::array<std::array<Tile*, 8>, 8> tiles) {
	std::vector<Move> tempVec;
	bool found = false;
	Vector2<int> index;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (tiles[i][j]->holding() == this) {
				index = Vector2<int>(i, j);
			}
		}
	}
	assert(found);

	//Diagonal top left
	Vector2<int> testIndex = Vector2<int>(index.x - 1, index.y - 1);
	while (testIndex.x >= 0 && testIndex.y >= 0 &&
		tiles[testIndex.x][testIndex.y]->holding() == nullptr) {

		tempVec.push_back(Move(tiles[index.x][index.y], tiles[testIndex.x][testIndex.y]));
		testIndex.x--;
		testIndex.y--;
	}
	if (testIndex.x >= 0 && testIndex.y >= 0 &&
		tiles[testIndex.x][testIndex.y]->holding() != nullptr &&
		&tiles[testIndex.x][testIndex.y]->holding()->owner() != &_owner) {
		tempVec.push_back(Move(tiles[index.x][index.y], tiles[testIndex.x][testIndex.y]));
	}

	//Diagonal top right
	testIndex = Vector2<int>(index.x + 1, index.y - 1);
	while (testIndex.x < 8 && testIndex.y >= 0 &&
		tiles[testIndex.x][testIndex.y]->holding() == nullptr) {

		tempVec.push_back(Move(tiles[index.x][index.y], tiles[testIndex.x][testIndex.y]));
		testIndex.x++;
		testIndex.y--;
	}
	if (testIndex.x < 8 && testIndex.y >= 0 &&
		tiles[testIndex.x][testIndex.y]->holding() != nullptr &&
		&tiles[testIndex.x][testIndex.y]->holding()->owner() != &_owner) {
		tempVec.push_back(Move(tiles[index.x][index.y], tiles[testIndex.x][testIndex.y]));
	}

	//Diagonal bottom left
	testIndex = Vector2<int>(index.x - 1, index.y + 1);
	while (testIndex.x >= 0 && testIndex.y < 8 &&
		tiles[testIndex.x][testIndex.y]->holding() == nullptr) {

		tempVec.push_back(Move(tiles[index.x][index.y], tiles[testIndex.x][testIndex.y]));
		testIndex.x--;
		testIndex.y++;
	}
	if (testIndex.x >= 0 && testIndex.y < 8 &&
		tiles[testIndex.x][testIndex.y]->holding() != nullptr &&
		&tiles[testIndex.x][testIndex.y]->holding()->owner() != &_owner) {
		tempVec.push_back(Move(tiles[index.x][index.y], tiles[testIndex.x][testIndex.y]));
	}

	//Diagonal bottom right
	testIndex = Vector2<int>(index.x + 1, index.y + 1);
	while (testIndex.x < 8 && testIndex.y < 8 &&
		tiles[testIndex.x][testIndex.y]->holding() == nullptr) {

		tempVec.push_back(Move(tiles[index.x][index.y], tiles[testIndex.x][testIndex.y]));
		testIndex.x++;
		testIndex.y++;
	}
	if (testIndex.x < 8 && testIndex.y < 8 &&
		tiles[testIndex.x][testIndex.y]->holding() != nullptr &&
		&tiles[testIndex.x][testIndex.y]->holding()->owner() != &_owner) {
		tempVec.push_back(Move(tiles[index.x][index.y], tiles[testIndex.x][testIndex.y]));
	}


	return tempVec;
}