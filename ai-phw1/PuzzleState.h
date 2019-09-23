#pragma once
#include <vector>

using namespace std; 

enum PuzzleMove
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class PuzzleState
{
public:
	int board[9] = { 0 };
	int blankIndex = 0;
	int depth = 0;

	PuzzleState();
	PuzzleState(int* inputs);
	PuzzleState(const PuzzleState& state);
	~PuzzleState();

	void reset(int* inputs);
	void print();
	int getId();
	bool canMove(int moveDirection);
	bool isAnswer();
	bool moveBy(int moveDirection);
	PuzzleState* getMovedState(int moveDirection);
};