#include "AStarStrategy.h"
#include <map>
#include <queue>
#include <set>
#include <iostream>

using namespace std;

AStarStrategy::AStarStrategy()
{
	name = "A*";
}


AStarStrategy::~AStarStrategy()
{
}

bool AStarStrategy::solvePuzzle(PuzzleState& puzzle)
{
	reset();

	priority_queue<PuzzleState, vector<PuzzleState>, greater<PuzzleState>> open;
	map<int, int> closed;

	open.push(PuzzleState(puzzle));

	while (visitedCount < INT_MAX)
	{
		// Update max OPEN size
		if (open.size() > maxOpenSize)
		{
			maxOpenSize = open.size();
		}

		PuzzleState v;
		int vId = 0;

		// Find v
		while (true)
		{			
			// Check for whether Open is empty
			if (open.empty())
			{
				cout << "Fail to find Answer: OPEN is empty" << endl << endl;
				return false;
			}

			// Find v of lowest cost in OPEN
			v = open.top();
			open.pop();
			vId = v.getId();

			auto vInOpen = closed.find(vId);
			if (vInOpen == closed.end())
			{
				// v is not visited
				visitedCount += 1;
				break;
			}
			else
			{
				// v is visited
				int newCost = v.estimatedCost;
				int oldCost = (*vInOpen).second;
				if (newCost < oldCost)
				{
					// Remove v in CLOSED
					closed.erase(vId);
					break;
				}
			}
		} // Found v

		// If answer, return success
		if (v.isAnswer())
		{
			solutionLength = v.depth;
			return true;
		}

		// Insert v into CLOSED
		closed.insert(make_pair(vId, v.estimatedCost));

		// Expand v
		for (int i = 0; i < DIRECTION_MAX; i++)
		{
			if (v.canMove(i))
			{
				open.push(v.getMovedState(i));
			}
		}

	} // Cost reaches max

	cout << "Fail to find Answer: visit count is max" << endl << endl;
	return false;
}
