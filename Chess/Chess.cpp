#include "Chess.h"


Chess::Chess(Vector2<float> boardSize) :
	_board(boardSize),
	_draggedPiece(nullptr),
	_player(MoveDir::Up),
	_computer(MoveDir::Down)
{

}
Chess::~Chess(){
	delete _window;
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

	_board._tiles[0][6]->setPiece(new Pawn(textureWhite, _board._tiles[0][6], _player));
	_board._tiles[1][6]->setPiece(new Pawn(textureWhite, _board._tiles[1][6], _player));
	_board._tiles[2][6]->setPiece(new Pawn(textureWhite, _board._tiles[2][6], _player));
	_board._tiles[3][6]->setPiece(new Pawn(textureWhite, _board._tiles[3][6], _player));
	_board._tiles[4][6]->setPiece(new Pawn(textureWhite, _board._tiles[4][6], _player));
	_board._tiles[5][6]->setPiece(new Pawn(textureWhite, _board._tiles[5][6], _player));
	_board._tiles[6][6]->setPiece(new Pawn(textureWhite, _board._tiles[6][6], _player));
	_board._tiles[7][6]->setPiece(new Pawn(textureWhite, _board._tiles[7][6], _player));

	_board._tiles[4][7]->setPiece(new King(textureWhite, _board._tiles[4][7], _player));
	_board._tiles[3][7]->setPiece(new Queen(textureWhite, _board._tiles[3][7], _player));
	_board._tiles[0][7]->setPiece(new Rook(textureWhite, _board._tiles[0][7], _player));
	_board._tiles[7][7]->setPiece(new Rook(textureWhite, _board._tiles[7][7], _player));

	_board._tiles[1][7]->setPiece(new Knight(textureWhite, _board._tiles[1][7], _player));
	_board._tiles[6][7]->setPiece(new Knight(textureWhite, _board._tiles[6][7], _player));
	_board._tiles[2][7]->setPiece(new Bishop(textureWhite, _board._tiles[2][7], _player));
	_board._tiles[5][7]->setPiece(new Bishop(textureWhite, _board._tiles[5][7], _player));

	_board._tiles[0][1]->setPiece(new Pawn(textureBlack, _board._tiles[0][1], _computer));
	_board._tiles[1][1]->setPiece(new Pawn(textureBlack, _board._tiles[1][1], _computer));
	_board._tiles[2][1]->setPiece(new Pawn(textureBlack, _board._tiles[2][1], _computer));
	_board._tiles[3][1]->setPiece(new Pawn(textureBlack, _board._tiles[3][1], _computer));
	_board._tiles[4][1]->setPiece(new Pawn(textureBlack, _board._tiles[4][1], _computer));
	_board._tiles[5][1]->setPiece(new Pawn(textureBlack, _board._tiles[5][1], _computer));
	_board._tiles[6][1]->setPiece(new Pawn(textureBlack, _board._tiles[6][1], _computer));
	_board._tiles[7][1]->setPiece(new Pawn(textureBlack, _board._tiles[7][1], _computer));

	_board._tiles[4][0]->setPiece(new King(textureBlack, _board._tiles[4][0], _computer));
	_board._tiles[3][0]->setPiece(new Queen(textureBlack, _board._tiles[3][0], _computer));
	_board._tiles[0][0]->setPiece(new Rook(textureBlack, _board._tiles[0][0], _computer));
	_board._tiles[7][0]->setPiece(new Rook(textureBlack, _board._tiles[7][0], _computer));

	_board._tiles[1][0]->setPiece(new Knight(textureBlack, _board._tiles[1][0], _computer));
	_board._tiles[6][0]->setPiece(new Knight(textureBlack, _board._tiles[6][0], _computer));
	_board._tiles[2][0]->setPiece(new Bishop(textureBlack, _board._tiles[2][0], _computer));
	_board._tiles[5][0]->setPiece(new Bishop(textureBlack, _board._tiles[5][0], _computer));


	// Debug test
	/*std::vector<Tile*> tiles = _chessPieces.back()->possibleMoves();
	for (auto t : tiles) {
		t->_rectShape.setFillColor(sf::Color::Green);
	}*/


	_window = new sf::RenderWindow(sf::VideoMode(600, 600), "Chess", sf::Style::Titlebar | sf::Style::Close);
	_window->setFramerateLimit(200);
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

		update();
		_window->clear();
		render();
		_window->display();
	}
}

std::vector<Move> Chess::findBestMove(Player& player) {


	
	// Perform simulation and find the best move

	std::vector<Move> bestMoves;

	return bestMoves;
}
Tile* Chess::mouseOnTile() {
	std::array<std::array<Tile*, 8>, 8>& tiles = _board.tiles();
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			if (tiles[x][y]->contains(_controls._mousePos)) {
				return tiles[x][y];
			}
		}
	}
	return nullptr;
}
void Chess::render() {
	_board.render(*_window);
}
void Chess::update() {
	if (_controls._mouseLeft && _draggedPiece == nullptr && mouseOnTile() != nullptr && mouseOnTile()->holding() != nullptr) {
		if (&(mouseOnTile()->holding()->owner()) == &_player) {
			_draggedPiece = mouseOnTile()->holding();
		}
	}
	if (!_controls._mouseLeft && _draggedPiece != nullptr) {
		if (_draggedPiece->move(mouseOnTile(), _board.tiles())) {
			_lastMovedPlayer = &_draggedPiece->owner();
			std::vector<Move> bestMoves = findBestMove(_computer);
			// Randomize among equally strong moves
			//int pickedMove = 0 + (rand() % (int)(bestMoves.size()));
			//bestMoves[pickedMove].fromTile->_currPiece->move(bestMoves[pickedMove].toTile, _board.tiles());
		}
		_draggedPiece = nullptr;
	}
	if (_draggedPiece != nullptr) {
		_draggedPiece->sprite().setPosition(_controls._mousePos.x - _draggedPiece->sprite().getGlobalBounds().width / 2,
			_controls._mousePos.y - _draggedPiece->sprite().getGlobalBounds().height / 2);
	}
}