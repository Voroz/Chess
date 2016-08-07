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
	Player computer(MoveDir::Down);

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

	Controls controls;
	Ui ui(_board, controls);

	_window = new sf::RenderWindow(sf::VideoMode(1200, 800), "Chess", sf::Style::Titlebar | sf::Style::Close);
	// run the program as long as the window is open
	while (_window->isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (_window->pollEvent(event))
		{
			switch (event.type) {
				// "close requested" event: we close the window
				case sf::Event::Closed: {
					_window->close();
				} break;

				case sf::Event::MouseMoved: {
					controls._mousePos.x = sf::Mouse::getPosition(*_window).x;
					controls._mousePos.y = sf::Mouse::getPosition(*_window).y;
				} break;

				case sf::Event::MouseButtonPressed: {
					switch (event.mouseButton.button) {
						case sf::Mouse::Left: {
							controls._mouseLeft = true;
						} break;
						case sf::Mouse::Right: {
							controls._mouseRight = true;
						} break;
					}
				} break;

				case sf::Event::MouseButtonReleased: {
					switch (event.mouseButton.button) {
						case sf::Mouse::Left: {
							controls._mouseLeft = false;
						} break;
						case sf::Mouse::Right: {
							controls._mouseRight = false;
						} break;
					}
				} break;

				case sf::Event::KeyPressed: {
					switch (event.key.code) {
						
					}
				} break;

				case sf::Event::KeyReleased: {
					switch (event.key.code) {

					}
				} break;
			}
		}

		ui.update();

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