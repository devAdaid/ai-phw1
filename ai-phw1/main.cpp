#include <iostream>
#include <vector>
#include "MyLibrary.h"

using namespace std;

int main()
{
	// Prepare strategies
	vector<PuzzleStrategy*> strategies;
	strategies.push_back(new DfsStrategy());
	strategies.push_back(new BfsStrategy());
	strategies.push_back(new AStarStrategy());

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

		// Make puzzle
		PuzzleState puzzle = PuzzleState(inputs);

		// Solve puzzle by strategies
		for (auto strategy : strategies)
		{
			bool isSuccess = strategy->solvePuzzle(puzzle);
			if (isSuccess)
			{
				strategy->printResult();
			}
		}

		cout << endl;
	}

	// Delete strategies
	for (auto strategy : strategies)
	{
		delete strategy;
	}
	strategies.clear();

	return 0;
}