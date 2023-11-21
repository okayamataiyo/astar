#include "Player.h"

Player::Player()
	:maze_(nullptr),nowCell_()
{

}

void Player::Start(Maze* _maze)
{
	maze_ = _maze;
	maze_->SetBlock(1,1,b_Player);
}

void Player::Move()
{

}

bool Player::IsGoal()
{
	return nowCell_ == maze_->goal_;
}