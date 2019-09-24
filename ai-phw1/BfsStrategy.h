#pragma once
#include "PuzzleStrategy.h"

class BfsStrategy : 
	public PuzzleStrategy
{
public:
	BfsStrategy();
	~BfsStrategy();

	bool solvePuzzle(PuzzleState& puzzle) override;
};

