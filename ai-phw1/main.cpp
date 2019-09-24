#include <iostream>
#include <vector>
#include "MyLibrary.h";

using namespace std;

int main()
{
	PuzzleState *puzzle = new PuzzleState();

	DfsStrategy *dfs = new DfsStrategy();
	BfsStrategy *bfs = new BfsStrategy();
	AStarStrategy *astar = new AStarStrategy();

	vector<PuzzleStrategy*> strategies;
	strategies.push_back(dfs);
	strategies.push_back(bfs);
	strategies.push_back(astar);

	while (true)
	{
		// Get inputs
		cout << "Input puzzles (blank=0): " << endl;
		int inputs[9] = { 0 };
		for (int i = 0; i < 9; i++)
		{
			cin >> inputs[i];
		}
		cout << endl;

		// Initialize puzzle data
		puzzle->reset(inputs);

		// Solve puzzle by strategies
		for (auto strategy : strategies)
		{
			strategy->solvePuzzle(puzzle);
			strategy->printResult();
		}

		cout << endl;
	}

	delete puzzle;
	delete dfs;
	return 0;
}