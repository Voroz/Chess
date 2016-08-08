#include "ChessPiece.h"
#include "Chess.h"



ChessPiece::ChessPiece(sf::Texture& texture, Tile* tile, Player& owner) :
	_currTile(nullptr),
	_startTile(_currTile),
	_owner(owner)
{
	_sprite.setTexture(texture);
	_sprite.setScale(0.25, 0.25);

	if (tile->_currPiece != nullptr) {
		std::cout << "Tile already occupied" << std::endl;
	}
	else {
		tile->_currPiece = this;
		_currTile = tile;
		_startTile = _currTile;
		update();
	}
}

ChessPiece::~ChessPiece(){

}

void ChessPiece::update() {
	_sprite.setPosition(_currTile->_pos.x + _currTile->_size.x / 2 - _sprite.getGlobalBounds().width / 2,
		_currTile->_pos.y + _currTile->_size.y / 2 - _sprite.getGlobalBounds().height / 2);
}
void ChessPiece::render(sf::RenderWindow &window) {
	window.draw(_sprite);
}
int ChessPiece::move(Tile* tile) {
	bool tileFound = false;
	for (auto t : possibleMoves()) {
		if (t == tile) {
			tileFound = true;
			break;
		}
	}
	if (!tileFound) {
		std::cout << "Invalid move" << std::endl;
		update();
		return 0;
	}
	if (tile->holding() != nullptr) {
		std::vector<ChessPiece*>& activeChessPieces = tile->board().chess()->activeChessPieces();
		std::vector<ChessPiece*>& inactiveChessPieces = tile->board().chess()->inactiveChessPieces();
		for (int i = 0; i < activeChessPieces.size(); i++) {
			if (activeChessPieces[i] == tile->holding()) {
				tile->holding()->_currTile = nullptr;
				inactiveChessPieces.push_back(tile->holding());
				activeChessPieces.erase(activeChessPieces.begin() + i);
				break;
			}
		}
	}
	_currTile->_currPiece = nullptr;
	_currTile = tile;
	tile->_currPiece = this;
	update();
	return 1;
}
Player& ChessPiece::owner() {
	return _owner;
}
sf::Sprite& ChessPiece::sprite() {
	return _sprite;
}
int ChessPiece::value() {
	return _value;
}
Tile* ChessPiece::currTile() {
	return _currTile;
}