#include "Chess.h"


Chess::Chess(Vector2<float> boardSize) :
	_board(new Board(boardSize, this)),
	_draggedPiece(nullptr),
	_player(MoveDir::Up, _chessPieces),
	_computer(MoveDir::Down, _chessPieces)
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

	_chessPieces.push_back(new Pawn(textureWhite, _board->_tiles[0][6], _player));
	_chessPieces.push_back(new Pawn(textureWhite, _board->_tiles[1][6], _player));
	_chessPieces.push_back(new Pawn(textureWhite, _board->_tiles[2][6], _player));
	_chessPieces.push_back(new Pawn(textureWhite, _board->_tiles[3][6], _player));
	_chessPieces.push_back(new Pawn(textureWhite, _board->_tiles[4][6], _player));
	_chessPieces.push_back(new Pawn(textureWhite, _board->_tiles[5][6], _player));
	_chessPieces.push_back(new Pawn(textureWhite, _board->_tiles[6][6], _player));
	_chessPieces.push_back(new Pawn(textureWhite, _board->_tiles[7][6], _player));
	_chessPieces.push_back(new King(textureWhite, _board->_tiles[4][7], _player));
	_chessPieces.push_back(new Queen(textureWhite, _board->_tiles[3][7], _player));
	_chessPieces.push_back(new Rook(textureWhite, _board->_tiles[0][7], _player));
	_chessPieces.push_back(new Rook(textureWhite, _board->_tiles[7][7], _player));
	_chessPieces.push_back(new Knight(textureWhite, _board->_tiles[1][7], _player));
	_chessPieces.push_back(new Knight(textureWhite, _board->_tiles[6][7], _player));
	_chessPieces.push_back(new Bishop(textureWhite, _board->_tiles[2][7], _player));
	_chessPieces.push_back(new Bishop(textureWhite, _board->_tiles[5][7], _player));

	_chessPieces.push_back(new Pawn(textureBlack, _board->_tiles[0][1], _computer));
	_chessPieces.push_back(new Pawn(textureBlack, _board->_tiles[1][1], _computer));
	_chessPieces.push_back(new Pawn(textureBlack, _board->_tiles[2][1], _computer));
	_chessPieces.push_back(new Pawn(textureBlack, _board->_tiles[3][1], _computer));
	_chessPieces.push_back(new Pawn(textureBlack, _board->_tiles[4][1], _computer));
	_chessPieces.push_back(new Pawn(textureBlack, _board->_tiles[5][1], _computer));
	_chessPieces.push_back(new Pawn(textureBlack, _board->_tiles[6][1], _computer));
	_chessPieces.push_back(new Pawn(textureBlack, _board->_tiles[7][1], _computer));
	_chessPieces.push_back(new King(textureBlack, _board->_tiles[4][0], _computer));
	_chessPieces.push_back(new Queen(textureBlack, _board->_tiles[3][0], _computer));
	_chessPieces.push_back(new Rook(textureBlack, _board->_tiles[0][0], _computer));
	_chessPieces.push_back(new Rook(textureBlack, _board->_tiles[7][0], _computer));
	_chessPieces.push_back(new Knight(textureBlack, _board->_tiles[1][0], _computer));
	_chessPieces.push_back(new Knight(textureBlack, _board->_tiles[6][0], _computer));
	_chessPieces.push_back(new Bishop(textureBlack, _board->_tiles[2][0], _computer));
	_chessPieces.push_back(new Bishop(textureBlack, _board->_tiles[5][0], _computer));


	// Debug test
	/*std::vector<Tile*> tiles = _chessPieces.back()->possibleMoves();
	for (auto t : tiles) {
		t->_rectShape.setFillColor(sf::Color::Green);
	}*/


	_window = new sf::RenderWindow(sf::VideoMode(1200, 800), "Chess", sf::Style::Titlebar | sf::Style::Close);
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
	return _chessPieces;
}
Move Chess::findBestMove(Player& player) {
	// TODO: Implement this function (there is just test code inside right now).


	Player* opponent = &_player;
	if (&player != &_computer) {
		opponent = &_computer;
	}
	
	// Perform simulation and find the best move

	Move bestMove;

	int bestWorstScore = -4000;
	
	for (auto pm : player.possibleMoves()) {

		// Copy vector of chessPieces, so we can restore everything later.

		std::vector<ChessPiece*> chessPiecesStart;
		for (auto &cp : _chessPieces) {
			switch (cp->identify()) {
				case CpType::PawnT: {
					chessPiecesStart.push_back(new Pawn(*static_cast<Pawn*>(cp)));
				} break;

				case CpType::BishopT: {
					chessPiecesStart.push_back(new Bishop(*static_cast<Bishop*>(cp)));
				} break;

				case CpType::KnightT: {
					chessPiecesStart.push_back(new Knight(*static_cast<Knight*>(cp)));
				} break;

				case CpType::RookT: {
					chessPiecesStart.push_back(new Rook(*static_cast<Rook*>(cp)));
				} break;

				case CpType::QueenT: {
					chessPiecesStart.push_back(new Queen(*static_cast<Queen*>(cp)));
				} break;

				case CpType::KingT: {
					chessPiecesStart.push_back(new King(*static_cast<King*>(cp)));
				} break;
			}
		}

		int worstScore = 100000;
		pm.fromTile->_currPiece->move(pm.toTile);


		for (auto opm : opponent->possibleMoves()) {

			// Copy vector of chessPieces, so we can restore everything later.

			std::vector<ChessPiece*> chessPiecesStart2;
			for (auto &cp : _chessPieces) {
				switch (cp->identify()) {
					case CpType::PawnT: {
						chessPiecesStart2.push_back(new Pawn(*static_cast<Pawn*>(cp)));
					} break;

					case CpType::BishopT: {
						chessPiecesStart2.push_back(new Bishop(*static_cast<Bishop*>(cp)));
					} break;

					case CpType::KnightT: {
						chessPiecesStart2.push_back(new Knight(*static_cast<Knight*>(cp)));
					} break;

					case CpType::RookT: {
						chessPiecesStart2.push_back(new Rook(*static_cast<Rook*>(cp)));
					} break;

					case CpType::QueenT: {
						chessPiecesStart2.push_back(new Queen(*static_cast<Queen*>(cp)));
					} break;

					case CpType::KingT: {
						chessPiecesStart2.push_back(new King(*static_cast<King*>(cp)));
					} break;
				}
			}

			opm.fromTile->_currPiece->move(opm.toTile);


			for (auto pm2 : player.possibleMoves()) {

				// Copy vector of chessPieces, so we can restore everything later.

				std::vector<ChessPiece*> chessPiecesStart3;
				for (auto &cp : _chessPieces) {
					switch (cp->identify()) {
						case CpType::PawnT: {
							chessPiecesStart3.push_back(new Pawn(*static_cast<Pawn*>(cp)));
						} break;

						case CpType::BishopT: {
							chessPiecesStart3.push_back(new Bishop(*static_cast<Bishop*>(cp)));
						} break;

						case CpType::KnightT: {
							chessPiecesStart3.push_back(new Knight(*static_cast<Knight*>(cp)));
						} break;

						case CpType::RookT: {
							chessPiecesStart3.push_back(new Rook(*static_cast<Rook*>(cp)));
						} break;

						case CpType::QueenT: {
							chessPiecesStart3.push_back(new Queen(*static_cast<Queen*>(cp)));
						} break;

						case CpType::KingT: {
							chessPiecesStart3.push_back(new King(*static_cast<King*>(cp)));
						} break;
					}
				}

				pm2.fromTile->_currPiece->move(pm2.toTile);

				for (auto opm2 : opponent->possibleMoves()) {

					// Copy vector of chessPieces, so we can restore everything later.

					std::vector<ChessPiece*> chessPiecesStart4;
					for (auto &cp : _chessPieces) {
						switch (cp->identify()) {
							case CpType::PawnT: {
								chessPiecesStart4.push_back(new Pawn(*static_cast<Pawn*>(cp)));
							} break;

							case CpType::BishopT: {
								chessPiecesStart4.push_back(new Bishop(*static_cast<Bishop*>(cp)));
							} break;

							case CpType::KnightT: {
								chessPiecesStart4.push_back(new Knight(*static_cast<Knight*>(cp)));
							} break;

							case CpType::RookT: {
								chessPiecesStart4.push_back(new Rook(*static_cast<Rook*>(cp)));
							} break;

							case CpType::QueenT: {
								chessPiecesStart4.push_back(new Queen(*static_cast<Queen*>(cp)));
							} break;

							case CpType::KingT: {
								chessPiecesStart4.push_back(new King(*static_cast<King*>(cp)));
							} break;
						}
					}

					opm2.fromTile->_currPiece->move(opm2.toTile);

					if (player.score() - opponent->score() < worstScore) {
						worstScore = player.score() - opponent->score();
						std::cout << worstScore << std::endl;
					}
					

					// Move back everything to the way it was.
					// TODO: This part is making the game crash because possibleMoves() uses old addresses, which we delete here.

					for (auto cp : _chessPieces) {
						delete cp;
					}
					_chessPieces = chessPiecesStart4;

					for (int x = 0; x < 8; x++) {
						for (int y = 0; y < 8; y++) {
							_board->tiles()[x][y]->_currPiece = nullptr;
						}
					}

					for (auto cp : _chessPieces) {
						cp->_currTile->_currPiece = cp;
					}

					for (auto cp : _chessPieces) {
						cp->update();
					}
				}

				// Move back everything to the way it was.
				// TODO: This part is making the game crash because possibleMoves() uses old addresses, which we delete here.

				for (auto cp : _chessPieces) {
					delete cp;
				}
				_chessPieces = chessPiecesStart3;

				for (int x = 0; x < 8; x++) {
					for (int y = 0; y < 8; y++) {
						_board->tiles()[x][y]->_currPiece = nullptr;
					}
				}

				for (auto cp : _chessPieces) {
					cp->_currTile->_currPiece = cp;
				}

				for (auto cp : _chessPieces) {
					cp->update();
				}
			}

			// Move back everything to the way it was.
			// TODO: This part is making the game crash because possibleMoves() uses old addresses, which we delete here.

			for (auto cp : _chessPieces) {
				delete cp;
			}
			_chessPieces = chessPiecesStart2;

			for (int x = 0; x < 8; x++) {
				for (int y = 0; y < 8; y++) {
					_board->tiles()[x][y]->_currPiece = nullptr;
				}
			}

			for (auto cp : _chessPieces) {
				cp->_currTile->_currPiece = cp;
			}

			for (auto cp : _chessPieces) {
				cp->update();
			}
		}

		if (worstScore > bestWorstScore) {
			bestWorstScore = worstScore;
			bestMove = pm;
			std::cout << "Best Worst score: " << bestWorstScore << std::endl;
		}


		// Move back everything to the way it was.
		// TODO: This part is making the game crash because possibleMoves() uses old addresses, which we delete here.

		for (auto cp : _chessPieces) {
			delete cp;
		}
		_chessPieces = chessPiecesStart;

		for (int x = 0; x < 8; x++) {
			for (int y = 0; y < 8; y++) {
				_board->tiles()[x][y]->_currPiece = nullptr;
			}
		}

		for (auto cp : _chessPieces) {
			cp->_currTile->_currPiece = cp;
		}

		for (auto cp : _chessPieces) {
			cp->update();
		}
	}

	return bestMove;
}
Tile* Chess::mouseOnTile() {
	std::array<std::array<Tile*, 8>, 8>& tiles = _board->tiles();
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
	_board->render(*_window);
	for (auto cp : _chessPieces) {
		cp->render(*_window);
	}
	if (_draggedPiece != nullptr) {
		_window->draw(_draggedPiece->sprite());
	}
}
void Chess::update() {
	if (_controls._mouseLeft && _draggedPiece == nullptr && mouseOnTile() != nullptr) {
		_draggedPiece = mouseOnTile()->holding();
	}
	if (!_controls._mouseLeft && _draggedPiece != nullptr) {
		if (_draggedPiece->move(mouseOnTile())) {
			Move bestMove = findBestMove(_computer);
			bestMove.fromTile->_currPiece->move(bestMove.toTile);
		}
		_draggedPiece = nullptr;
	}
	if (_draggedPiece != nullptr) {
		_draggedPiece->sprite().setPosition(_controls._mousePos.x - _draggedPiece->sprite().getGlobalBounds().width / 2,
			_controls._mousePos.y - _draggedPiece->sprite().getGlobalBounds().height / 2);
	}
}