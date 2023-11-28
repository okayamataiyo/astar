#include "Player.h"

Player::Player()
	:maze_(nullptr),nowCell_(1,1,b_Player)
{
}

void Player::Start(Maze* _maze)
{
	nowCell_()
	maze_ = _maze;
	maze_->SetCell(nowCell_);
}

void Player::Move()
{
	
	Start(maze_);

	
}

bool Player::IsGoal()
{
	return nowCell_ == maze_->goal_;
}

int Player::NextPlayerPos()
{
	return 0;
}
