#include "Chess.h"


Chess::Chess(Vector2<float> boardSize) :
	_board(new Board(boardSize, this)),
	_ui(_board, _controls)
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
	sf::Texture textureWhite;
	std::string textWhiteName = "ChessPiecesTextureWhite.png";
	if (!textureWhite.loadFromFile(textWhiteName)) {
		std::cout << "Couldn't load " << textWhiteName << std::endl;
	}

	sf::Texture textureBlack;
	std::string textBlackName = "ChessPiecesTextureBlack.png";
	if (!textureBlack.loadFromFile(textBlackName)) {
		std::cout << "Couldn't load " << textBlackName << std::endl;
	}

	Player player(MoveDir::Up, _chessPieces);
	Player computer(MoveDir::Down, _chessPieces);

	_chessPieces.push_back(new Pawn(textureWhite, _board->_tiles[0][6], player));
	_chessPieces.push_back(new Pawn(textureWhite, _board->_tiles[1][6], player));
	_chessPieces.push_back(new Pawn(textureWhite, _board->_tiles[2][6], player));
	_chessPieces.push_back(new Pawn(textureWhite, _board->_tiles[3][6], player));
	_chessPieces.push_back(new Pawn(textureWhite, _board->_tiles[4][6], player));
	_chessPieces.push_back(new Pawn(textureWhite, _board->_tiles[5][6], player));
	_chessPieces.push_back(new Pawn(textureWhite, _board->_tiles[6][6], player));
	_chessPieces.push_back(new Pawn(textureWhite, _board->_tiles[7][6], player));
	_chessPieces.push_back(new King(textureWhite, _board->_tiles[4][7], player));
	_chessPieces.push_back(new Queen(textureWhite, _board->_tiles[3][7], player));
	_chessPieces.push_back(new Rook(textureWhite, _board->_tiles[0][7], player));
	_chessPieces.push_back(new Rook(textureWhite, _board->_tiles[7][7], player));
	_chessPieces.push_back(new Knight(textureWhite, _board->_tiles[1][7], player));
	_chessPieces.push_back(new Knight(textureWhite, _board->_tiles[6][7], player));
	_chessPieces.push_back(new Bishop(textureWhite, _board->_tiles[2][7], player));
	_chessPieces.push_back(new Bishop(textureWhite, _board->_tiles[5][7], player));

	_chessPieces.push_back(new Pawn(textureBlack, _board->_tiles[0][1], computer));
	_chessPieces.push_back(new Pawn(textureBlack, _board->_tiles[1][1], computer));
	_chessPieces.push_back(new Pawn(textureBlack, _board->_tiles[2][1], computer));
	_chessPieces.push_back(new Pawn(textureBlack, _board->_tiles[3][1], computer));
	_chessPieces.push_back(new Pawn(textureBlack, _board->_tiles[4][1], computer));
	_chessPieces.push_back(new Pawn(textureBlack, _board->_tiles[5][1], computer));
	_chessPieces.push_back(new Pawn(textureBlack, _board->_tiles[6][1], computer));
	_chessPieces.push_back(new Pawn(textureBlack, _board->_tiles[7][1], computer));
	_chessPieces.push_back(new King(textureBlack, _board->_tiles[4][0], computer));
	_chessPieces.push_back(new Queen(textureBlack, _board->_tiles[3][0], computer));
	_chessPieces.push_back(new Rook(textureBlack, _board->_tiles[0][0], computer));
	_chessPieces.push_back(new Rook(textureBlack, _board->_tiles[7][0], computer));
	_chessPieces.push_back(new Knight(textureBlack, _board->_tiles[1][0], computer));
	_chessPieces.push_back(new Knight(textureBlack, _board->_tiles[6][0], computer));
	_chessPieces.push_back(new Bishop(textureBlack, _board->_tiles[2][0], computer));
	_chessPieces.push_back(new Bishop(textureBlack, _board->_tiles[5][0], computer));

	// Debug test
	/*std::vector<Tile*> tiles = _chessPieces.back()->possibleMoves();
	for (auto t : tiles) {
		t->_rectShape.setFillColor(sf::Color::Green);
	}*/


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
					_controls._mousePos.x = sf::Mouse::getPosition(*_window).x;
					_controls._mousePos.y = sf::Mouse::getPosition(*_window).y;
				} break;

				case sf::Event::MouseButtonPressed: {
					switch (event.mouseButton.button) {
						case sf::Mouse::Left: {
							_controls._mouseLeft = true;
						} break;
						case sf::Mouse::Right: {
							_controls._mouseRight = true;
						} break;
					}
				} break;

				case sf::Event::MouseButtonReleased: {
					switch (event.mouseButton.button) {
						case sf::Mouse::Left: {
							_controls._mouseLeft = false;
						} break;
						case sf::Mouse::Right: {
							_controls._mouseRight = false;
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

		_ui.update();

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
	_ui.render(*_window);
}