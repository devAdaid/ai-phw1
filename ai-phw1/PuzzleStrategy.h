#pragma once
#include"PuzzleState.h"

class PuzzleStrategy
{
public:
	int visitedCount = 0;
	int maxOpenSize = 0;
	int solutionLength = 0;

	PuzzleStrategy();
	~PuzzleStrategy();
	virtual bool solvePuzzle(PuzzleState* puzzle);
};

