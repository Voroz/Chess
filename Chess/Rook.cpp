#include "Rook.h"



Rook::Rook(sf::Texture& texture, Tile* tile, Player& owner) :
	ChessPiece(texture, tile, owner)
{
	_sprite.setTextureRect(sf::IntRect(1355, 0, 212, 265));
	update();
}

Rook::~Rook() {

}
std::vector<Tile*> Rook::possibleMoves() {
	std::vector<Tile*> tempVec;
	return tempVec;
}