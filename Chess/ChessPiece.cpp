#include "ChessPiece.h"
#include "Chess.h"



ChessPiece::ChessPiece(sf::Texture& texture, Tile* tile, Player& owner) :
	_currTile(nullptr),
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
void ChessPiece::move(Tile* tile) {
	if (tile->holding() != nullptr) {
		std::vector<ChessPiece*>& chessPieces = tile->board()->chess()->chessPieces();
		for (int i = 0; i < chessPieces.size(); i++) {
			if (chessPieces[i] == tile->holding()) {
				chessPieces.erase(chessPieces.begin() + i);
				delete tile->holding();
				break;
			}
		}
	}
	_currTile->_currPiece = nullptr;
	_currTile = tile;
	tile->_currPiece = this;
	update();
}