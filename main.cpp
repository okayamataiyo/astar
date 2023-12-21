#include <iostream>
#include "Maze.h"
#include "Player.h"
#include "astar.h"

using namespace std;

namespace {
	const int MAP_HEIGHT = 11;
	const int MAP_WIDTH = 11;
}

int main()
{
	//srand((unsigned)time(NULL));

	Maze* pMaze = new Maze(MAP_HEIGHT, MAP_WIDTH);
	if (pMaze->Create()) {
		pMaze->Output();
	}

	Player* pPlayer = new Player;
	pPlayer->Start(pMaze);
	int turn = 0;
	while (turn <= 50)
	{
		pPlayer->Move();

		cout << endl << "nextData :" << endl;

		if (pPlayer->IsGoal())break;

		turn++;
	}

	cout << "Goal" << endl;
	return 0;
}
