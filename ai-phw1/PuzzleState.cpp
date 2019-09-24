#include "PuzzleState.h"
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

PuzzleState::PuzzleState()
{

}

PuzzleState::PuzzleState(int* inputs)
{
	reset(inputs);
}


PuzzleState::PuzzleState(const PuzzleState& state)
{
	for (int i = 0; i < 9; i++)
	{
		board[i] = state.board[i];
	}

	blankIndex = state.blankIndex;
	depth = state.depth;
	estimatedCost = state.estimatedCost;
}


PuzzleState::~PuzzleState()
{
}

bool PuzzleState::operator <(const PuzzleState& p) const {
	if (estimatedCost < p.estimatedCost)
	{
		return true;
	}

	return false;
}

bool PuzzleState::operator >(const PuzzleState& p) const {
	if (estimatedCost > p.estimatedCost)
	{
		return true;
	}

	return false;
}

void PuzzleState::reset(int* inputs)
{
	for (int i = 0; i < 9; i++)
	{
		board[i] = inputs[i];

		if (board[i] == 0)
		{
			blankIndex = i;
		}
	}

	depth = 0;
	estimatedCost = 0;
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
	for (int i = 0; i < 9; i++)
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
	case DIRECTION_LEFT:
		result = ((blankIndex % 3) != 0);
		break;
	case DIRECTION_RIGHT:
		result = ((blankIndex % 3) != 2);
		break;
	case DIRECTION_UP:
		result = (blankIndex > 2);
		break;
	case DIRECTION_DOWN:
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
		case DIRECTION_LEFT:
			targetIndex = blankIndex - 1;
			break;
		case DIRECTION_RIGHT:
			targetIndex = blankIndex + 1;
			break;
		case DIRECTION_UP:
			targetIndex = blankIndex - 3;
			break;
		case DIRECTION_DOWN:
			targetIndex = blankIndex + 3;
			break;
		}

		// Swap tiles and set blank index
		swap(board[blankIndex], board[targetIndex]);
		blankIndex = targetIndex;
	}
	return canMoveToState;
}

PuzzleState PuzzleState::getMovedState(int moveDirection)
{
	PuzzleState newState = PuzzleState(*this);

	bool moveResult = newState.moveBy(moveDirection);

	// �̵��� �� ������ ����
	if (!moveResult)
	{
		newState = nullptr;
	}

	newState.depth = depth + 1;

	return newState;
}