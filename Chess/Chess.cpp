#include "Chess.h"


Chess::Chess(Vector2<float> boardSize) :
	_board(boardSize, this),
	_draggedPiece(nullptr),
	_player(MoveDir::Up, _activeChessPieces),
	_computer(MoveDir::Down, _activeChessPieces)
{

}
Chess::~Chess(){
	delete _window;
	for (auto cp : _activeChessPieces) {
		delete cp;
	}
	for (auto cp : _inactiveChessPieces) {
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

	_activeChessPieces.push_back(new Pawn(textureWhite, _board._tiles[0][6], _player));
	_activeChessPieces.push_back(new Pawn(textureWhite, _board._tiles[1][6], _player));
	_activeChessPieces.push_back(new Pawn(textureWhite, _board._tiles[2][6], _player));
	_activeChessPieces.push_back(new Pawn(textureWhite, _board._tiles[3][6], _player));
	_activeChessPieces.push_back(new Pawn(textureWhite, _board._tiles[4][6], _player));
	_activeChessPieces.push_back(new Pawn(textureWhite, _board._tiles[5][6], _player));
	_activeChessPieces.push_back(new Pawn(textureWhite, _board._tiles[6][6], _player));
	_activeChessPieces.push_back(new Pawn(textureWhite, _board._tiles[7][6], _player));
	_activeChessPieces.push_back(new King(textureWhite, _board._tiles[4][7], _player));
	_activeChessPieces.push_back(new Queen(textureWhite, _board._tiles[3][7], _player));
	_activeChessPieces.push_back(new Rook(textureWhite, _board._tiles[0][7], _player));
	_activeChessPieces.push_back(new Rook(textureWhite, _board._tiles[7][7], _player));
	_activeChessPieces.push_back(new Knight(textureWhite, _board._tiles[1][7], _player));
	_activeChessPieces.push_back(new Knight(textureWhite, _board._tiles[6][7], _player));
	_activeChessPieces.push_back(new Bishop(textureWhite, _board._tiles[2][7], _player));
	_activeChessPieces.push_back(new Bishop(textureWhite, _board._tiles[5][7], _player));

	_activeChessPieces.push_back(new Pawn(textureBlack, _board._tiles[0][1], _computer));
	_activeChessPieces.push_back(new Pawn(textureBlack, _board._tiles[1][1], _computer));
	_activeChessPieces.push_back(new Pawn(textureBlack, _board._tiles[2][1], _computer));
	_activeChessPieces.push_back(new Pawn(textureBlack, _board._tiles[3][1], _computer));
	_activeChessPieces.push_back(new Pawn(textureBlack, _board._tiles[4][1], _computer));
	_activeChessPieces.push_back(new Pawn(textureBlack, _board._tiles[5][1], _computer));
	_activeChessPieces.push_back(new Pawn(textureBlack, _board._tiles[6][1], _computer));
	_activeChessPieces.push_back(new Pawn(textureBlack, _board._tiles[7][1], _computer));
	_activeChessPieces.push_back(new King(textureBlack, _board._tiles[4][0], _computer));
	_activeChessPieces.push_back(new Queen(textureBlack, _board._tiles[3][0], _computer));
	_activeChessPieces.push_back(new Rook(textureBlack, _board._tiles[0][0], _computer));
	_activeChessPieces.push_back(new Rook(textureBlack, _board._tiles[7][0], _computer));
	_activeChessPieces.push_back(new Knight(textureBlack, _board._tiles[1][0], _computer));
	_activeChessPieces.push_back(new Knight(textureBlack, _board._tiles[6][0], _computer));
	_activeChessPieces.push_back(new Bishop(textureBlack, _board._tiles[2][0], _computer));
	_activeChessPieces.push_back(new Bishop(textureBlack, _board._tiles[5][0], _computer));


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
std::vector<ChessPiece*>& Chess::chessPieces() {
	std::vector<ChessPiece*> tempVec;
	for (auto cp : _activeChessPieces) {
		tempVec.push_back(cp);
	}
	for (auto cp : _inactiveChessPieces) {
		tempVec.push_back(cp);
	}
	return tempVec;
}
std::vector<ChessPiece*>& Chess::activeChessPieces() {
	return _activeChessPieces;
}
std::vector<ChessPiece*>& Chess::inactiveChessPieces() {
	return _inactiveChessPieces;
}
std::vector<Move> Chess::findBestMove(Player& player) {

	Player* opponent = &_player;
	if (&player != &_computer) {
		opponent = &_computer;
	}
	
	// Perform simulation and find the best move

	std::vector<Move> bestMoves;

	int bestWorstScore = -10000;

	struct SavedCpInfo {
		ChessPiece* piece = nullptr;
		Tile* currTile = nullptr;
	};

	// Copy vector of chessPieces, so we can restore everything later.

	std::vector<ChessPiece*> activeChessPiecesStart = _activeChessPieces;
	std::vector<ChessPiece*> inactiveChessPiecesStart = _inactiveChessPieces;
	std::vector<SavedCpInfo> savedCpInfo;
	for (auto cp : _activeChessPieces) {
		SavedCpInfo info;
		info.piece = cp;
		info.currTile = cp->currTile();
		savedCpInfo.push_back(info);
	}
	
	for (auto pm : player.possibleMoves()) {

		int worstScore = 100000;
		
		pm.fromTile->_currPiece->move(pm.toTile);

		// Copy vector of chessPieces, so we can restore everything later.

		std::vector<ChessPiece*> activeChessPiecesStart2 = _activeChessPieces;
		std::vector<ChessPiece*> inactiveChessPiecesStart2 = _inactiveChessPieces;
		std::vector<SavedCpInfo> savedCpInfo2;
		for (auto cp : _activeChessPieces) {
			SavedCpInfo info;
			info.piece = cp;
			info.currTile = cp->currTile();
			savedCpInfo2.push_back(info);
		}

		for (auto opm : opponent->possibleMoves()) {

			opm.fromTile->_currPiece->move(opm.toTile);

			// Copy vector of chessPieces, so we can restore everything later.

			std::vector<ChessPiece*> activeChessPiecesStart3 = _activeChessPieces;
			std::vector<ChessPiece*> inactiveChessPiecesStart3 = _inactiveChessPieces;
			std::vector<SavedCpInfo> savedCpInfo3;
			for (auto cp : _activeChessPieces) {
				SavedCpInfo info;
				info.piece = cp;
				info.currTile = cp->currTile();
				savedCpInfo3.push_back(info);
			}

			for (auto pm2 : player.possibleMoves()) {

				pm2.fromTile->_currPiece->move(pm2.toTile);

				if (player.score() - opponent->score() < worstScore) {
					worstScore = player.score() - opponent->score();
				}
				

				// Move back everything to the way it was.

				_activeChessPieces = activeChessPiecesStart3;
				_inactiveChessPieces = inactiveChessPiecesStart3;

				for (int x = 0; x < 8; x++) {
					for (int y = 0; y < 8; y++) {
						_board.tiles()[x][y]->_currPiece = nullptr;
					}
				}

				for (auto cpi : savedCpInfo3) {
					cpi.piece->_currTile = cpi.currTile;
				}

				for (auto cp : _activeChessPieces) {
					cp->_currTile->_currPiece = cp;
				}

				for (auto cp : _activeChessPieces) {
					cp->update();
				}
			}

			// Move back everything to the way it was.

			_activeChessPieces = activeChessPiecesStart2;
			_inactiveChessPieces = inactiveChessPiecesStart2;

			for (int x = 0; x < 8; x++) {
				for (int y = 0; y < 8; y++) {
					_board.tiles()[x][y]->_currPiece = nullptr;
				}
			}

			for (auto cpi : savedCpInfo2) {
				cpi.piece->_currTile = cpi.currTile;
			}

			for (auto cp : _activeChessPieces) {
				cp->_currTile->_currPiece = cp;
			}

			for (auto cp : _activeChessPieces) {
				cp->update();
			}
		}


		// Move back everything to the way it was.

		_activeChessPieces = activeChessPiecesStart;
		_inactiveChessPieces = inactiveChessPiecesStart;

		for (int x = 0; x < 8; x++) {
			for (int y = 0; y < 8; y++) {
				_board.tiles()[x][y]->_currPiece = nullptr;
			}
		}

		for (auto cpi : savedCpInfo) {
			cpi.piece->_currTile = cpi.currTile;
		}

		for (auto cp : _activeChessPieces) {
			cp->_currTile->_currPiece = cp;
		}

		for (auto cp : _activeChessPieces) {
			cp->update();
		}

		if (worstScore > bestWorstScore) {
			bestWorstScore = worstScore;
			bestMoves.clear();
		}
		if (worstScore >= bestWorstScore) {
			bestMoves.push_back(pm);
		}
	}

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
	for (auto cp : _activeChessPieces) {
		cp->render(*_window);
	}
	if (_draggedPiece != nullptr) {
		_window->draw(_draggedPiece->sprite());
	}
}
void Chess::update() {
	if (_controls._mouseLeft && _draggedPiece == nullptr && mouseOnTile() != nullptr && mouseOnTile()->holding() != nullptr) {
		if (&mouseOnTile()->holding()->owner() == &_player) {
			_draggedPiece = mouseOnTile()->holding();
		}
	}
	if (!_controls._mouseLeft && _draggedPiece != nullptr) {
		if (_draggedPiece->move(mouseOnTile())) {
			std::vector<Move> bestMoves = findBestMove(_computer);
			// Randomize among equally strong moves
			int pickedMove = 0 + (rand() % (int)(bestMoves.size()));
			bestMoves[pickedMove].fromTile->_currPiece->move(bestMoves[pickedMove].toTile);
		}
		_draggedPiece = nullptr;
	}
	if (_draggedPiece != nullptr) {
		_draggedPiece->sprite().setPosition(_controls._mousePos.x - _draggedPiece->sprite().getGlobalBounds().width / 2,
			_controls._mousePos.y - _draggedPiece->sprite().getGlobalBounds().height / 2);
	}
}