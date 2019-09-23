#include <iostream>
#include"PuzzleState.h"
#include"DfsStrategy.h"

int main()
{
	int inputs[9] = { 0 };
	for (int i = 0; i < 9; i++)
	{
		cin >> inputs[i];
	}

	PuzzleState *puzzle = new PuzzleState(inputs);
	DfsStrategy *dfs = new DfsStrategy();

	dfs->solvePuzzle(puzzle);
	dfs->printResult();

	delete puzzle;
	delete dfs;
	return 0;
}