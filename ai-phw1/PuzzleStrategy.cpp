#include "PuzzleStrategy.h"
#include <iostream>

using namespace std;

PuzzleStrategy::PuzzleStrategy()
{
}

PuzzleStrategy::PuzzleStrategy(string strategyName)
{
	name = strategyName;
}

PuzzleStrategy::~PuzzleStrategy()
{
}

void PuzzleStrategy::reset()
{
	visitedCount = 0;
	maxOpenSize = 0;
	solutionLength = 0;
}

void PuzzleStrategy::printResult()
{
	cout << "[" << name << "]" << endl;
	cout << "VISIT: \t" << visitedCount << endl
		<< "OPEN: \t" << maxOpenSize << endl
		<< "LEN: \t" << solutionLength << endl << endl;
}

bool PuzzleStrategy::solvePuzzle(PuzzleState& puzzle)
{
	return false;
}