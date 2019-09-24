#include "BfsStrategy.h"
#include <queue>
#include <set>
#include <iostream>

using namespace std;

BfsStrategy::BfsStrategy()
{
	name = "BFS";
}


BfsStrategy::~BfsStrategy()
{
}

bool BfsStrategy::solvePuzzle(PuzzleState* puzzle)
{
	reset();

	bool result = false;
	queue<PuzzleState*> open;
	set<int> visited;

	open.push(new PuzzleState(*puzzle));

	while (visitedCount < INT_MAX)
	{
		// Update max OPEN size
		if (open.size() > maxOpenSize)
		{
			maxOpenSize = open.size();
		}

		// Find v not visited
		PuzzleState* v = nullptr;
		int vId = 0;
		bool alreadyVisited = false;
		do
		{
			// Check for whether Open is empty
			if (open.empty())
			{
				cout << "Fail to find Answer: OPEN is empty" << endl << endl;
				return false;
			}

			v = open.front();
			open.pop();
			vId = v->getId();
			alreadyVisited = visited.find(vId) != visited.end();

		} while (alreadyVisited);

		visitedCount += 1;

		// If answer, return success
		if (v->isAnswer())
		{
			solutionLength = v->depth;
			return true;
		}

		// Insert v into VISITED
		visited.insert(vId);

		// Expand v
		for (int i = 0; i < DIRECTION_MAX; i++)
		{
			if (v->canMove(i))
			{
				open.push(v->getMovedState(i));
			}
		}

		delete v;
		v = nullptr;

	} // Cost is max

	cout << "Fail to find Answer: visit count is max" << endl << endl;
	return false;
}