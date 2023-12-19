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
	int Heuristic_;
	int Cost_;
	vector<vector<int>> table_;
	Maze* maze_;
	cell cell_;
	
public:
	Player();
	void Start(Maze* _maze);
	void Move();
	void Heuristic();
	void Dijkstra();
	bool IsGoal();
	int NextPlayerPos();
};