#include <iostream>
#include "Maze.h"
#include "Player.h"

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
	pMaze->Output();

	while (true)
	{
		pPlayer->Move();

		cout << endl << "nextData :" << endl;
		pMaze->Output();

		if (pPlayer->IsGoal())break;
	}

	cout << "Goal" << endl;
	return 0;
}
