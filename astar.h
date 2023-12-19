#pragma once
#include "Maze.h"


class astar
{
private:
	int GoalHeight_;
	int GoalWidth_;
	int PlayerHeight_;
	int PlayerWidth_;
	int Heuristic_;

public:
	int Heuristic();

};

