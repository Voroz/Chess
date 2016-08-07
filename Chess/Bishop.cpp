#include "Bishop.h"



Bishop::Bishop(sf::Texture& texture, Tile* tile, Player& owner) :
	ChessPiece(texture, tile, owner)
{
	_sprite.setTextureRect(sf::IntRect(667, 0, 256, 265));
	update();
}

Bishop::~Bishop() {

}
std::vector<Tile*> Bishop::possibleMoves() {
	std::vector<Tile*> tempVec;
	return tempVec;
}