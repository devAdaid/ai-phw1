#pragma once
#include "PuzzleState.h"
#include <string>

class PuzzleStrategy
{
protected:
	unsigned int visitedCount = 0;
	unsigned int maxOpenSize = 0;
	unsigned int solutionLength = 0;
	string name;

	void reset();

public:
	PuzzleStrategy();
	~PuzzleStrategy();

	void printResult();
	virtual bool solvePuzzle(PuzzleState& puzzle);
};

