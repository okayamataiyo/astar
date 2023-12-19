#include "Player.h"

Player::Player()
	:GoalHeight_(0), GoalWidth_(0),PlayerHeight_(1),PlayerWidth_(1), Heuristic_(0)
	, Cost_(0),table_(maze_->GetWidth(),maze_->GetHeight()), maze_(nullptr), cell_(PlayerHeight_, PlayerWidth_, b_Player)
{

}

void Player::Start(Maze* _maze)
{
	maze_ = _maze;
	maze_->SetCell(cell_);

}

void Player::Move()
{
	Dijkstra();
	Heuristic();
}

void Player::Heuristic()
{
	Heuristic_ = abs(maze_->GetTypeHeight(b_Goal) - abs(maze_->GetTypeHeight(b_Player)))
		+abs(maze_->GetTypeWidth(b_Goal) - abs(maze_->GetTypeWidth(b_Player)));
	GoalHeight_ = maze_->GetTypeHeight(b_Goal);
	GoalWidth_ = maze_->GetTypeWidth(b_Goal);
	PlayerHeight_ = maze_->GetTypeHeight(b_Player);
	PlayerWidth_ = maze_->GetTypeWidth(b_Player);
	cout << "Cost         = " << Cost_ << endl;
	cout << "Heuristic    = " << Heuristic_ << endl;
	cout << "GoalHeight   = " << GoalHeight_ << endl;
	cout << "GoalWidth    = " << GoalWidth_ << endl;
	cout << "PlayerHeight = " << PlayerHeight_ << endl;
	cout << "PlayerWidth  = " << PlayerWidth_ << endl;
}

void Player::Dijkstra()
{
	if (maze_->IsWall(PlayerHeight_, PlayerWidth_++) == false)
	{
		Cost_++;
	}

	if (maze_->IsWall(PlayerHeight_++, PlayerWidth_) == false)
	{
		Cost_++;
	}

	if (maze_->IsWall(PlayerHeight_, PlayerWidth_--) == false)
	{
		Cost_++;
	}

	if (maze_->IsWall(PlayerHeight_--, PlayerWidth_) == false)
	{
		Cost_++;
	}
}

bool Player::IsGoal()
{
	return cell_ == maze_->goal_;
}

int Player::NextPlayerPos()
{
	return 0;
}
