#include "Board.h"
#include "Chess.h"


Board::Board(Vector2<float> size) :
	_size(size)
{
	initTiles();
}

Board::~Board(){
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			delete _tiles[x][y];
		}
	}
}

void Board::initTiles() {
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			_tiles[x][y] = new Tile(*this, Vector2<int>(x, y));
			_tiles[x][y]->_size = Vector2<float>(_size.x / 8, _size.y / 8);
			_tiles[x][y]->_pos = Vector2<float>(_size.x / 8 * x, _size.y / 8 * y);
			_tiles[x][y]->syncShape();
			switch ((x + y) % 2) {
				case 0: {
					_tiles[x][y]->_rectShape.setFillColor(sf::Color::White);
				} break;

				default: {
					_tiles[x][y]->_rectShape.setFillColor(sf::Color::Red);
				} break;
			}
		}
	}
}
std::array<std::array<Tile*, 8>, 8>& Board::tiles() {
	return _tiles;
}
void Board::render(sf::RenderWindow &window) {
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			Tile* tile = _tiles[x][y];
			tile->render(window);
		}
	}
}