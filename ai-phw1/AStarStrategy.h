#pragma once
#include "PuzzleStrategy.h"

class AStarStrategy :
	public PuzzleStrategy
{
protected:
	string heuristicName;
	int(*heuristicFuntion)(PuzzleState&) = nullptr;
public:
	AStarStrategy();
	AStarStrategy(int(*hFunc)(PuzzleState&), string hName);
	~AStarStrategy();

	bool solvePuzzle(PuzzleState& puzzle) override;
};

