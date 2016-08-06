#include "Queen.h"



Queen::Queen(sf::Texture& texture, Tile* tile, Player& owner) :
	ChessPiece(texture, tile, owner)
{
	_sprite.setTextureRect(sf::IntRect(318, 0, 287, 261));
	update();
}

Queen::~Queen() {

}
std::vector<Tile*> Queen::possibleMoves() {
	std::vector<Tile*> tempVec;
	return tempVec;
}