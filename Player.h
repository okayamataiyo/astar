#pragma once
#include <vector>
#include "Maze.h"

enum {
	Nown,
	Open,
	Closed
};

class Player
{
private:
	//ƒƒ“ƒo•Ï”
	int GoalHeight_;
	int GoalWidth_;
	int PlayerHeight_;
	int PlayerWidth_;
	int HUp_;
	int HDown_;
	int HLeft_;
	int HRight_;
	int Cost_;
	vector<int> table_;
	Maze* maze_;
	cell cell_;
	
public:
	Player();
	void Start(Maze* _maze);
	void Move();
	void Heuristic();
	int Up();
	int Down();
	int Left();
	int Right();
	bool IsGoal();
	int NextPlayerPos();
};