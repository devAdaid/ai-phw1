#include "PuzzleStrategy.h"
#include<iostream>

using namespace std;

PuzzleStrategy::PuzzleStrategy()
{
}


PuzzleStrategy::~PuzzleStrategy()
{
}

void PuzzleStrategy::printResult()
{
	cout << "[" << name << "]" << endl;
	cout << "VISIT: \t" << visitedCount << endl
		<< "OPEN: \t" << maxOpenSize << endl
		<< "LEN: \t" << solutionLength << endl;
}

bool PuzzleStrategy::solvePuzzle(PuzzleState* puzzle)
{
	return false;
}