#include <iostream>
#include "MyLibrary.h";

int main()
{
	PuzzleState *puzzle = new PuzzleState();
	DfsStrategy *dfs = new DfsStrategy();
	BfsStrategy *bfs = new BfsStrategy();

	while (true)
	{
		cout << "Input puzzles (blank=0): " << endl;
		int inputs[9] = { 0 };
		for (int i = 0; i < 9; i++)
		{
			cin >> inputs[i];
		}
		cout << endl;

		puzzle->reset(inputs);

		dfs->solvePuzzle(puzzle);
		dfs->printResult();

		bfs->solvePuzzle(puzzle);
		bfs->printResult();

		cout << endl;
	}

	delete puzzle;
	delete dfs;
	return 0;
}