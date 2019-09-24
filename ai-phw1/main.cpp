#include <iostream>
#include <vector>
#include "MyLibrary.h"

using namespace std;

int heuristic1(PuzzleState& puzzle);
int heuristic2(PuzzleState& puzzle);

int main()
{
	// Prepare strategies
	vector<PuzzleStrategy*> strategies;
	strategies.push_back(new DfsStrategy());
	strategies.push_back(new BfsStrategy());
	strategies.push_back(new AStarStrategy(heuristic1, "H1"));
	strategies.push_back(new AStarStrategy(heuristic2, "H2"));

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

// Number of tiles out of place
int heuristic1(PuzzleState& puzzle)
{
	int outTileCount = 0;
	for (int idx = 0; idx < 9; idx++)
	{
		int number = puzzle.board[idx];
		if (number == 0) continue;

		int targetIdx = number - 1;
		if (idx != targetIdx) outTileCount += 1;
	}
	return puzzle.depth + outTileCount;
}

// Summation of the manhattan distance to the place
int heuristic2(PuzzleState& puzzle)
{
	int manhattanDistanceSum = 0;
	for (int idx = 0; idx < 9; idx++)
	{
		int manhattanDistance = 0;

		int number = puzzle.board[idx];
		if (number != 0)
		{
			int targetIdx = number - 1;
			int xDiff = abs((idx % 3) - (targetIdx % 3));
			int yDiff = abs((idx / 3) - (targetIdx / 3));
			manhattanDistance = xDiff + yDiff;
		}

		manhattanDistanceSum += manhattanDistance;
	}
	return puzzle.depth + manhattanDistanceSum;
}