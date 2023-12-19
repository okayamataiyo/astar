#include "Maze.h"
#include "astar.h"
#include<cmath>

int astar::Heuristic()
{
	Maze* maze;
	maze = nullptr;
	Heuristic_ = abs(maze->GetTypeHeight(b_Goal) - abs(maze->GetTypeHeight(b_Player))) +
		abs(maze->GetTypeWidth(b_Goal) - abs(maze->GetTypeWidth(b_Player)));
	GoalHeight_ = maze->GetTypeHeight(b_Goal);
	GoalWidth_ = maze->GetTypeWidth(b_Goal);
	PlayerHeight_ = maze->GetTypeHeight(b_Player);
	PlayerWidth_ = maze->GetTypeWidth(b_Player);
	cout << "Heuristic = " << Heuristic_ << endl;
	cout << "GoalHeight = " << GoalHeight_ << endl;
	cout << "GoalWidth = " << GoalWidth_ << endl;
	cout << "PlayerHeight = " << PlayerHeight_ << endl;
	cout << "PlayerWidth = " << PlayerWidth_ << endl;

	return 0;
}
