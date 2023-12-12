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
	int walk_H;
	int walk_W;
	Maze* maze_;
	cell cell_;
	
public:
	Player();
	void Start(Maze* _maze);
	void Move();
	bool IsGoal();
	int NextPlayerPos();
};