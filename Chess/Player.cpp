#include "Player.h"



Player::Player(MoveDir moveDir, std::vector<ChessPiece*>& activeChessPieces) :
	_moveDir(moveDir),
	_chessPieces(activeChessPieces)
{

}
Player::~Player(){

}

MoveDir Player::moveDir() {
	return _moveDir;
}
std::vector<ChessPiece*> Player::chessPieces() {
	std::vector<ChessPiece*> tempVec;
	for (auto cp : _chessPieces) {
		if (&cp->owner() == this) {
			tempVec.push_back(cp);
		}
	}
	return tempVec;
}
std::vector<Move> Player::possibleMoves() {
	std::vector<Move> tempVec;
	for (auto cp : chessPieces()) {
		for (auto pm : cp->possibleMoves()) {
			Move move;
			move.fromTile = cp->currTile();
			move.toTile = pm;
			tempVec.push_back(move);
		}
	}
	return tempVec;
}
int Player::score() {
	int score = 0;
	for (auto cp : chessPieces()) {
		score += cp->value();
	}
	return score;
}