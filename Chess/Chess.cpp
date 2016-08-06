#include "Chess.h"



Chess::Chess(Vector2<float> boardSize) :
	_board(new Board(boardSize, this))
{

}
Chess::~Chess(){
	delete _window;
	delete _board;
	for (auto cp : _chessPieces) {
		delete cp;
	}
}

void Chess::run() {
	sf::Texture texture;
	std::string textName = "ChessPiecesTexture.png";
	if (!texture.loadFromFile(textName)) {
		std::cout << "Couldn't load " << textName << std::endl;
	}
	Player player(MoveDir::Up);
	_chessPieces.push_back(new Pawn(texture, _board->_tiles[0][6], player));
	_chessPieces.push_back(new Pawn(texture, _board->_tiles[1][6], player));
	_chessPieces.push_back(new Pawn(texture, _board->_tiles[2][6], player));
	_chessPieces.push_back(new Pawn(texture, _board->_tiles[3][6], player));
	_chessPieces.push_back(new Pawn(texture, _board->_tiles[4][6], player));
	_chessPieces.push_back(new Pawn(texture, _board->_tiles[5][6], player));
	_chessPieces.push_back(new Pawn(texture, _board->_tiles[6][6], player));
	_chessPieces.push_back(new Pawn(texture, _board->_tiles[7][6], player));
	_chessPieces.push_back(new King(texture, _board->_tiles[4][7], player));
	_chessPieces.push_back(new Queen(texture, _board->_tiles[3][7], player));
	_chessPieces.push_back(new Rook(texture, _board->_tiles[0][7], player));
	_chessPieces.push_back(new Rook(texture, _board->_tiles[7][7], player));
	_chessPieces.push_back(new Knight(texture, _board->_tiles[1][7], player));
	_chessPieces.push_back(new Knight(texture, _board->_tiles[6][7], player));
	_chessPieces.push_back(new Bishop(texture, _board->_tiles[2][7], player));
	_chessPieces.push_back(new Bishop(texture, _board->_tiles[5][7], player));

	// Debug test
	/*std::vector<Tile*> tiles = _chessPieces.back()->possibleMoves();
	for (auto t : tiles) {
		t->_rectShape.setFillColor(sf::Color::Green);
	}*/

	Player computer(MoveDir::Down);

	_window = new sf::RenderWindow(sf::VideoMode(1200, 800), "Chess", sf::Style::Titlebar | sf::Style::Close);
	// run the program as long as the window is open
	while (_window->isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (_window->pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				_window->close();
		}

		_window->clear();
		render();
		_window->display();
	}
}
std::vector<ChessPiece*>& Chess::chessPieces() {
	return _chessPieces;
}
void Chess::render() {
	_board->render(*_window);
	for (auto cp : _chessPieces) {
		cp->render(*_window);
	}
}