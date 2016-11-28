#include "Tile.h"



Tile::Tile(Board& boardPtr, Vector2<int> index) :
	_currPiece(nullptr),
	_boardPtr(boardPtr),
	_index(index){

}

Tile::~Tile(){

}

ChessPiece* Tile::holding() {
	return _currPiece;
}
void Tile::setPiece(ChessPiece* cp) {
	_currPiece = cp;
}
Board& Tile::board() {
	return _boardPtr;
}
Vector2<int> Tile::index() {
	return _index;
}
bool Tile::contains(Vector2<float> point) {
	return (point.x > _pos.x && point.x < _pos.x + _size.x &&
		point.y > _pos.y && point.y < _pos.y + _size.y);
}
void Tile::syncShape() {
	_rectShape.setSize(sf::Vector2<float>(_size.x, _size.y));
	_rectShape.setPosition(sf::Vector2<float>(_pos.x, _pos.y));
}
void Tile::render(sf::RenderWindow &window) {
	window.draw(_rectShape);
}