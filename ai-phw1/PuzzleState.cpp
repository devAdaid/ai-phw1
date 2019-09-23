#include "PuzzleState.h"
#include<iostream>
#include <algorithm>

using namespace std;

PuzzleState::PuzzleState()
{

}

PuzzleState::PuzzleState(int* inputs)
{
	for (int i = 0; i < 9; i++)
	{
		board[i] = inputs[i];

		if (board[i] == 0)
		{
			blankIndex = i;
		}
	}
}


PuzzleState::PuzzleState(const PuzzleState& state)
{
	blankIndex = state.blankIndex;
	depth = state.depth;

	for (int i = 0; i < 9; i++)
	{
		board[i] = state.board[i];
	}
}


PuzzleState::~PuzzleState()
{
}

void PuzzleState::print()
{
	cout << "State: " << endl
		<< board[0] << " " << board[1] << " " << board[2] << endl
		<< board[3] << " " << board[4] << " " << board[5] << endl
		<< board[6] << " " << board[7] << " " << board[8] << endl;
}

int PuzzleState::getId()
{
	int result = 0;
	for (int i = 8; i >= 0; i--)
	{
		result *= 10;
		result += board[i];
	}
	return result;
}

bool PuzzleState::canMove(int moveDirection)
{
	bool result = false;
	switch (moveDirection)
	{
	case LEFT:
		result = ((blankIndex % 3) != 0);
		break;
	case RIGHT:
		result = ((blankIndex % 3) != 2);
		break;
	case UP:
		result = (blankIndex > 2);
		break;
	case DOWN:
		result = (blankIndex < 6);
		break;
	}

	return result;
}

bool PuzzleState::isAnswer()
{
	for (int i = 0; i < 8; i++)
	{
		if (board[i] != (i + 1))
		{
			return false;
		}
	}

	return true;
}

bool PuzzleState::moveBy(int moveDirection)
{
	bool canMoveToState = canMove(moveDirection);
	if (canMoveToState)
	{
		int targetIndex = -1;

		// Calculate target index to be swapped with blank
		switch (moveDirection)
		{
		case LEFT:
			targetIndex = blankIndex - 1;
			break;
		case RIGHT:
			targetIndex = blankIndex + 1;
			break;
		case UP:
			targetIndex = blankIndex - 3;
			break;
		case DOWN:
			targetIndex = blankIndex + 3;
			break;
		}

		// Swap tiles and set blank index
		swap(board[blankIndex], board[targetIndex]);
		blankIndex = targetIndex;
	}
	return canMoveToState;
}

PuzzleState* PuzzleState::getMovedState(int moveDirection)
{
	PuzzleState* newState = new PuzzleState(*this);

	bool moveResult = newState->moveBy(moveDirection);

	// 이동할 수 없으면 해제
	if (!moveResult)
	{
		delete newState;
		newState = nullptr;
	}

	newState->depth = depth + 1;

	return newState;
}