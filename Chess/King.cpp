#include "King.h"



King::King(sf::Texture& texture, Tile* tile, Player& owner) :
	ChessPiece(texture, tile, owner)
{
	_sprite.setTextureRect(sf::IntRect(0, 0, 256, 265));
	update();
}

King::~King(){

}
std::vector<Tile*> King::possibleMoves() {
	std::vector<Tile*> tempVec;
	return tempVec;
}