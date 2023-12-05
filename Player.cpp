#include "Player.h"

Player::Player()
	:maze_(nullptr),cell_(maze_->(b_Player),b_Player)
{

}

void Player::Start(Maze* _maze)
{
	maze_ = _maze;
	maze_->SetCell(cell_);
}

void Player::Move()
{
	Start(maze_);
}

bool Player::IsGoal()
{
	return cell_ == maze_->goal_;
}

int Player::NextPlayerPos()
{
	return 0;
}
