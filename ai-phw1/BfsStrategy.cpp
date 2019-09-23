#include "BfsStrategy.h"
#include <queue>
#include <set>

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
	bool result = false;
	queue<PuzzleState*> openQueue;
	set<int> visited;

	openQueue.push(new PuzzleState(*puzzle));

	while (visitedCount < INT_MAX)
	{
		// Update max open size
		if (openQueue.size() > maxOpenSize)
		{
			maxOpenSize = openQueue.size();
		}

		// Find v not visited
		PuzzleState* v = nullptr;
		int vId = 0;
		bool alreadyVisited = false;
		do
		{
			if (v != nullptr)
			{
				delete v;
			}

			if (openQueue.empty())
			{
				return false;
			}

			v = openQueue.front();
			openQueue.pop();
			vId = v->getId();
			alreadyVisited = visited.find(vId) != visited.end();
		} while (alreadyVisited);

		// if answer, return success
		if (v->isAnswer())
		{
			solutionLength = v->depth;
			return true;
		}

		// Insert v into visited
		visited.insert(vId);
		visitedCount += 1;

		// Expand v
		for (int i = 0; i < 4; i++)
		{
			if (v->canMove(i))
			{
				openQueue.push(v->getMovedState(i));
			}
		}

		delete v;
	}

	return false;
}