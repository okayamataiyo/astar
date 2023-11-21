#pragma once
#include "Maze.h"

enum {
	Nown,
	Open,
	Closed
};

class Player
{
private:
	Maze* maze_;
	cell nowCell_;
public:
	Player();
	void Start(Maze* _maze);
	void Move();
	bool IsGoal();
};