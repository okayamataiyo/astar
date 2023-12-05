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
	//メンバ変数
	Maze* maze_;
	cell cell_;
	
public:
	Player();
	void Start(Maze* _maze);
	void Move();
	bool IsGoal();
	int NextPlayerPos();
};