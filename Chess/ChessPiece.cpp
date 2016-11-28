#include "ChessPiece.h"


ChessPiece::ChessPiece(sf::Texture& texture, Tile* tile, Player& owner) :
	_owner(owner),
	_active(true),
	_startTile(tile),
	_currTile(tile){

	_sprite.setTexture(&texture);
	_sprite.setOrigin(tile->_size.x / 2, tile->_size.y / 2);
	_sprite.setScale(0.9, 0.9);

	if (tile->_currPiece != nullptr) {
		std::cout << "Tile already occupied" << std::endl;
	}
	else {
		tile->_currPiece = this;
	}
}

ChessPiece::~ChessPiece(){

}
void ChessPiece::render(sf::RenderWindow &window, Vector2<int> pos, Vector2<int> size) {
	_sprite.setSize(sf::Vector2f(size.x, size.y));
	_sprite.setPosition(pos.x, pos.y);
	window.draw(_sprite);
}
bool ChessPiece::move(Tile* moveTo, std::array<std::array<Tile*, 8>, 8> tiles) {
	bool movePossible = false;
	std::vector<Move> moves;
	moves = possibleMoves(tiles);

	for (auto pm : possibleMoves(tiles)) {
		if (pm.toTile == moveTo) {
			movePossible = true;
			break;
		}
	}
	if (!movePossible) {
		std::cout << "Invalid move" << std::endl;
		return false;
	}

	if (moveTo->_currPiece != nullptr) {
		moveTo->_currPiece->setActive(false);
	}

	_currTile = moveTo;
	moveTo->_currPiece = this;
	return true;
}
Player& ChessPiece::owner() {
	return _owner;
}
sf::RectangleShape& ChessPiece::sprite() {
	return _sprite;
}
int ChessPiece::value() {
	return _value;
}
bool ChessPiece::active() {
	return _active;
}
void ChessPiece::setActive(bool active) {
	_active = active;
}