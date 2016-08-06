#pragma once
#include <vector>

enum MoveDir {
	Up = -1,
	Down = 1,
};

class Player
{
public:
	Player(MoveDir moveDir);
	~Player();
	MoveDir moveDir();

private:
	MoveDir _moveDir;
};

