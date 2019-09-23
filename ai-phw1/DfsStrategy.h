#pragma once
#include"PuzzleStrategy.h"
class DfsStrategy : public PuzzleStrategy
{
public:
	DfsStrategy();
	~DfsStrategy();

	bool solvePuzzle(PuzzleState* puzzle) override;
};

