#pragma once
#include "PuzzleState.h"
#include <string>

class PuzzleStrategy
{
public:
	unsigned int visitedCount = 0;
	unsigned int maxOpenSize = 0;
	unsigned int solutionLength = 0;
	string name;

	PuzzleStrategy();
	~PuzzleStrategy();

	void reset();
	void printResult();
	virtual bool solvePuzzle(PuzzleState* puzzle);
};

