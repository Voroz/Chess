#include "Player.h"



Player::Player(MoveDir moveDir) :
	_moveDir(moveDir)
{

}
Player::~Player(){

}

MoveDir Player::moveDir() {
	return _moveDir;
}