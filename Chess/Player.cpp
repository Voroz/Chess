#include "Player.h"



Player::Player(MoveDir moveDir) :
	_moveDir(moveDir),
	_bestScore(0){

}
Player::~Player(){

}

MoveDir Player::moveDir() {
	return _moveDir;
}
std::vector<ChessPiece*> Player::activeChessPieces(std::array<std::array<Tile*, 8>, 8> tiles) {
	std::vector<ChessPiece*> tempVec;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			ChessPiece* cp = tiles[i][j]->holding();
			if (cp == nullptr || &(cp->owner()) != this || !cp->active()) {
				continue;
			}
			tempVec.push_back(cp);
		}
	}

	return tempVec;
}
std::vector<Move> Player::possibleMoves(std::array<std::array<Tile*, 8>, 8> tiles) {
	std::vector<Move> tempVec;

	for (auto cp : activeChessPieces(tiles)) {
		for (auto pm : cp->possibleMoves(tiles)) {
			tempVec.push_back(pm);
		}
	}

	return tempVec;
}
int Player::score(std::array<std::array<Tile*, 8>, 8> tiles) {
	int score = 0;
	for (auto cp : activeChessPieces(tiles)) {
		score += cp->value();
	}
	return score;
}