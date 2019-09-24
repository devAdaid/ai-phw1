#pragma once
#include "PuzzleStrategy.h"

class AStarStrategy :
	public PuzzleStrategy
{
public:
	AStarStrategy();
	~AStarStrategy();

	bool solvePuzzle(PuzzleState* puzzle) override;
};

