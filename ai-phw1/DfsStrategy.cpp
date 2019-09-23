#include "DfsStrategy.h"
#include <stack>
#include <set>

DfsStrategy::DfsStrategy()
{
}


DfsStrategy::~DfsStrategy()
{
}

bool DfsStrategy::solvePuzzle(PuzzleState* puzzle)
{
	bool result = false;
	stack<PuzzleState*> openStack;
	set<int> visited;

	openStack.push(new PuzzleState(*puzzle));

	while (visitedCount < INT_MAX)
	{
		// Update max open size
		if (openStack.size() > maxOpenSize)
		{
			maxOpenSize = openStack.size();
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

			if (openStack.empty())
			{
				return false;
			}

			v = openStack.top();
			openStack.pop();
			vId = v->getId();
			alreadyVisited = visited.find(vId) != visited.end();
		} while (alreadyVisited);

		// if answer, return success
		if (v->isAnswer())
		{
			v->print();
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
				openStack.push(v->getMovedState(i));
			}
		}

		delete v;
	}

	return false;
}