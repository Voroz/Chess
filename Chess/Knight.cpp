#include "Knight.h"



Knight::Knight(sf::Texture& texture, Tile* tile, Player& owner) :
	ChessPiece(texture, tile, owner)
{
	_value = 3;
	_sprite.setTextureRect(sf::IntRect(1001, 0, 248, 265));
}

Knight::~Knight() {

}

CpType Knight::identify() {
	return CpType::KnightT;
}
std::vector<Move> Knight::possibleMoves(std::array<std::array<Tile*, 8>, 8> tiles) {
	std::vector<Move> tempVec;
	bool found = false;
	Vector2<int> index = _currTile->index();

	std::vector<Vector2<int>> testPositions;
	testPositions.push_back(Vector2<int>(index.x - 2, index.y - 1));
	testPositions.push_back(Vector2<int>(index.x - 2, index.y + 1));
	testPositions.push_back(Vector2<int>(index.x - 1, index.y - 2));
	testPositions.push_back(Vector2<int>(index.x - 1, index.y + 2));
	testPositions.push_back(Vector2<int>(index.x + 2, index.y - 1));
	testPositions.push_back(Vector2<int>(index.x + 2, index.y + 1));
	testPositions.push_back(Vector2<int>(index.x + 1, index.y - 2));
	testPositions.push_back(Vector2<int>(index.x + 1, index.y + 2));
	for (auto tp : testPositions) {
		if (tp.x >= 0 && tp.y >= 0 &&
			tp.x < 8 && tp.y < 8 &&
			tiles[tp.x][tp.y]->holding() == nullptr) {

			tempVec.push_back(Move(tiles[index.x][index.y], tiles[tp.x][tp.y]));
		}
	}
	for (auto tp : testPositions) {
		if (tp.x >= 0 && tp.y >= 0 &&
			tp.x < 8 && tp.y < 8 &&
			tiles[tp.x][tp.y]->holding() != nullptr &&
			&tiles[tp.x][tp.y]->holding()->owner() != &_owner) {

			tempVec.push_back(Move(tiles[index.x][index.y], tiles[tp.x][tp.y]));
		}
	}

	return tempVec;
}