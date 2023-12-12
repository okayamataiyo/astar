#include "Player.h"

Player::Player()
	:walk_H(1),walk_W(1),maze_(nullptr),cell_(walk_H, walk_W, b_Player)
{

}

void Player::Start(Maze* _maze)
{
	maze_ = _maze;
	maze_->SetCell(cell_);

}

void Player::Move()
{
	cout << "プレイヤーの位置は y = " << maze_->GetTypeHeight(b_Player) << endl;
	cout << "                   x = " << maze_->GetTypeWidth(b_Player) << endl;
}

bool Player::IsGoal()
{
	return cell_ == maze_->goal_;
}

int Player::NextPlayerPos()
{
	return 0;
}
