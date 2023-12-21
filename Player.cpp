#include "Player.h"

Player::Player()
	:GoalHeight_(0), GoalWidth_(0),PlayerHeight_(1),PlayerWidth_(1), HUp_(0),HDown_(0),HLeft_(0),HRight_(0)
	, Cost_(0),table_(15,15), maze_(nullptr)
	,cell_(PlayerHeight_, PlayerWidth_, b_Player)
{

}

void Player::Start(Maze* _maze)
{
	maze_ = _maze;
	maze_->SetCell(cell_);

}

void Player::Move()
{
	Heuristic();
}

void Player::Heuristic()
{
	
	HDown_ = abs(maze_->GetTypeHeight(b_Goal) - abs(maze_->GetTypeHeight(b_Player) + 1))
		+ abs(maze_->GetTypeWidth(b_Goal) - abs(maze_->GetTypeWidth(b_Player)));
	HUp_ = abs(maze_->GetTypeHeight(b_Goal) - abs(maze_->GetTypeHeight(b_Player) - 1))
		+ abs(maze_->GetTypeWidth(b_Goal) - abs(maze_->GetTypeWidth(b_Player)));
	HLeft_ = abs(maze_->GetTypeHeight(b_Goal) - abs(maze_->GetTypeHeight(b_Player)))
		+ abs(maze_->GetTypeWidth(b_Goal) - abs(maze_->GetTypeWidth(b_Player) - 1));
	HRight_ = abs(maze_->GetTypeHeight(b_Goal) - abs(maze_->GetTypeHeight(b_Player)))
		+ abs(maze_->GetTypeWidth(b_Goal) - abs(maze_->GetTypeWidth(b_Player) + 1));
	if (HDown_ <= HUp_)
	{
		cout << "Down" << endl;
		Down();
	}
	else
	{
		cout << "Up" << endl;
		Up();
	}

	if (HLeft_ <= HRight_)
	{
		cout << "Left" << endl;
		Left();
	}
	else
	{
		cout << "Right" << endl;
		Right();
	}
	GoalHeight_ = maze_->GetTypeHeight(b_Goal);
	GoalWidth_ = maze_->GetTypeWidth(b_Goal);
	cout << "Cost           = " << Cost_ << endl;
	cout << "HeuristicUp    = " << HUp_ << endl;
	cout << "HeuristicDown  = " << HDown_ << endl;
	cout << "HeuristicLeft  = " << HLeft_ << endl;
	cout << "HeuristicRight = " << HRight_ << endl;
	cout << "GoalHeight     = " << GoalHeight_ << endl;
	cout << "GoalWidth      = " << GoalWidth_ << endl;
	cout << "PlayerHeight   = " << PlayerHeight_ << endl;
	cout << "PlayerWidth    = " << PlayerWidth_ << endl;
}

int Player::Down()
{
	int CheckNum = PlayerHeight_ + 1;
	if (!maze_->IsWall(CheckNum, PlayerWidth_))
	{
		maze_->SetBlock(PlayerHeight_ += 1, PlayerWidth_,b_Player);
		Cost_++;

		PlayerHeight_ = maze_->GetTypeHeight(b_Player);
		PlayerWidth_ = maze_->GetTypeWidth(b_Player);
		maze_->Output();
		return 0;
	}

	PlayerHeight_ = maze_->GetTypeHeight(b_Player);
	PlayerWidth_ = maze_->GetTypeWidth(b_Player);
	return 0;
}

int Player::Up()
{
	int CheckNum = PlayerHeight_ - 1;
	if (!maze_->IsWall(CheckNum, PlayerWidth_))
	{
		maze_->SetBlock(PlayerHeight_ -= 1, PlayerWidth_, b_Player);
		Cost_++;

		PlayerHeight_ = maze_->GetTypeHeight(b_Player);
		PlayerWidth_ = maze_->GetTypeWidth(b_Player);
		maze_->Output();
		return 0;
	}

	PlayerHeight_ = maze_->GetTypeHeight(b_Player);
	PlayerWidth_ = maze_->GetTypeWidth(b_Player);
	return 0;
}

int Player::Left()
{
	int CheckNum = PlayerWidth_ - 1;
	if (!maze_->IsWall(PlayerHeight_, CheckNum))
	{
		maze_->SetBlock(PlayerHeight_, PlayerWidth_ -= 1, b_Player);
		Cost_++;

		PlayerHeight_ = maze_->GetTypeHeight(b_Player);
		PlayerWidth_ = maze_->GetTypeWidth(b_Player);
		maze_->Output();
		return 0;
	}

	PlayerHeight_ = maze_->GetTypeHeight(b_Player);
	PlayerWidth_ = maze_->GetTypeWidth(b_Player);
	return 0;
}

int Player::Right()
{
	int CheckNum = PlayerWidth_ + 1;
	if (!maze_->IsWall(PlayerHeight_, CheckNum))
	{
		maze_->SetBlock(PlayerHeight_, PlayerWidth_ + 1, b_Player);
		Cost_++;

		PlayerHeight_ = maze_->GetTypeHeight(b_Player);
		PlayerWidth_ = maze_->GetTypeWidth(b_Player);
		maze_->Output();
		return 0;
	}

	PlayerHeight_ = maze_->GetTypeHeight(b_Player);
	PlayerWidth_ = maze_->GetTypeWidth(b_Player);
	return 0;
}

bool Player::IsGoal()
{
	return (PlayerHeight_,PlayerWidth_) == (9,9);
}

int Player::NextPlayerPos()
{
	return 0;
}
