#pragma once
#include <vector>

using namespace std; 

enum MoveDirection
{
	DIRECTION_LEFT,
	DIRECTION_RIGHT,
	DIRECTION_UP,
	DIRECTION_DOWN,
	DIRECTION_MAX
};

class PuzzleState
{
public:
	int board[9] = { 0 };
	int blankIndex = 0;
	int depth = 0;
	int estimatedCost = 0;

	PuzzleState();
	PuzzleState(int* inputs);
	PuzzleState(const PuzzleState& state);
	~PuzzleState();

	bool operator <(const PuzzleState& p) const;
	bool operator >(const PuzzleState& p) const;
	void reset(int* inputs);
	void print();
	int getId();
	bool canMove(int moveDirection);
	bool isAnswer();
	bool moveBy(int moveDirection);
	int calculateEstimatedCost();
	int getManhattanDistanceAt(int idx);
	PuzzleState* getMovedState(int moveDirection);
};