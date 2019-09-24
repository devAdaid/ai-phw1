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
private:
	int board[9] = { 0 };
	int blankIndex = 0;

	bool moveBy(int moveDirection);
	int getManhattanDistanceAt(int idx);

public:
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
	int calculateEstimatedCost();
	PuzzleState getMovedState(int moveDirection);
};