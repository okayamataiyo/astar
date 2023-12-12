#include "Maze.h"
#include "astar.h"
#include<cmath>

int astar::Heuristic()
{
	Maze maze;
	maze.Create();
	abs(maze.GetWidth())- abs(maze.GetHeight());
	return 0;
}
