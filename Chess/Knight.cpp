#include "Knight.h"



Knight::Knight(sf::Texture& texture, Tile* tile, Player& owner) :
	ChessPiece(texture, tile, owner)
{
	_sprite.setTextureRect(sf::IntRect(1001, 0, 248, 265));
	update();
}

Knight::~Knight() {

}
std::vector<Tile*> Knight::possibleMoves() {
	std::vector<Tile*> tempVec;
	return tempVec;
}