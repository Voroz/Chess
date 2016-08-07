#include "Player.h"



Player::Player(MoveDir moveDir, std::vector<ChessPiece*>& chessPieces) :
	_moveDir(moveDir),
	_chessPieces(chessPieces)
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