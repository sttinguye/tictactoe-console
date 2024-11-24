/*
 * CBot.cpp
 *
 *  Created on: 08.11.2023
 *      Author: profe
 */

#include "CBot.h"
#include <iostream>
#include <limits> //for std::numeric_limits

CBot::CBot(CTicTacToeBoard*	pBoard, const CBoard::player_t& stone) : CPlayer(pBoard, stone)
{
}

CBot::~CBot()
{
	// TODO Auto-generated destructor stub
}

int CBot::minimax(int depth, bool isMaximizing)
{
	// Condition to stop the Recursion and loop back.
	CBoard::player_t winner {checkWinner()};
	if(winner == m_stone)
	{
		// the score/point the Bot gain if it choose this path
		return 1;
	}
	else if(winner == opponentStone())
	{
		// the score/point the Bot gain if it choose this path
		return -1;
	}
	//tie
	else if(winner == CBoard::player_t::CBOARD_EMPTY)
	{
		// the score/point the Bot gain if it choose this path
		return 0;
	}

	// else result = CBoard::player_t::CBOARD_UNKNOWN;
	// this means, we nee to continue to do the Recursion...

	int bestScore {0};
	int score{0};

	if (isMaximizing)
	{
		bestScore = std::numeric_limits<int>::min();

		for(unsigned short rowIndex = 0; rowIndex < m_pBoard->getNumOfRows(); rowIndex++)
		{
			for(unsigned short columnIndex = 0; columnIndex < m_pBoard->getNumOfColumns(); columnIndex++)
			{
				if(CBoard::player_t::CBOARD_EMPTY == m_pBoard->getElementAt(rowIndex, columnIndex))
				{
					m_pBoard->setElementAt(CPosition{rowIndex, columnIndex}, m_stone);

					score = minimax(depth + 1, false);

					m_pBoard->setElementAt(CPosition{rowIndex, columnIndex}, CBoard::player_t::CBOARD_EMPTY);

//					bestScore = std::max(score, bestScore);
					if (score >= bestScore) bestScore = score;
				}

			}
		}

		// after looping thru all the board then return the best score.
		return bestScore;
	}
	else // is minimizing
	{
		bestScore = std::numeric_limits<int>::max();

		for(unsigned short rowIndex = 0; rowIndex < m_pBoard->getNumOfRows(); rowIndex++)
		{
			for(unsigned short columnIndex = 0; columnIndex < m_pBoard->getNumOfColumns(); columnIndex++)
			{
				if(CBoard::player_t::CBOARD_EMPTY == m_pBoard->getElementAt(rowIndex, columnIndex))
				{
					m_pBoard->setElementAt(CPosition{rowIndex, columnIndex}, opponentStone());

					score = minimax(depth + 1, true);

					m_pBoard->setElementAt(CPosition{rowIndex, columnIndex}, CBoard::player_t::CBOARD_EMPTY);

//					bestScore = std::min(score, bestScore);
					if (score < bestScore) bestScore = score;
				}
			}
		}

		return bestScore;
	}


	return 0;
}

CGlobal::RC_t CBot::placeStone()
{
	int bestScore{std::numeric_limits<int>::min()};
	int score{0};
	CPosition bestPosition{0, 0};

	for(unsigned short rowIndex = 0; rowIndex < m_pBoard->getNumOfRows(); rowIndex++)
	{
		for(unsigned short columnIndex = 0; columnIndex < m_pBoard->getNumOfColumns(); columnIndex++)
		{
			// if this position is empty
			if(CBoard::player_t::CBOARD_EMPTY == m_pBoard->getElementAt(rowIndex, columnIndex))
			{
				// place a stone here and applies the minimax algo to see the outcomes.
				m_pBoard->setElementAt(CPosition{rowIndex, columnIndex}, m_stone);

				// 'false' here because we can see that the Bot has made a move above, so it's the other player's turn
				// so it is the minimizing path.
				score = minimax(0, false);

				// take the Stone out because we are not sure if we decide to choose this position yet.
				m_pBoard->setElementAt(CPosition{rowIndex, columnIndex}, CBoard::player_t::CBOARD_EMPTY);

				if(score > bestScore)
				{
					bestScore = score;
					bestPosition = CPosition{rowIndex, columnIndex};
				}
			}
		}
	}

	// Choose the most optimal move.

	if (m_stone == CBoard::CBOARD_X)
	{
		std::cout << "Player 1 (Computer) is placing a Stone at (" << bestPosition.getRow() << ", " << bestPosition.getCol()
					<< ")...\n";
	}
	else if (m_stone == CBoard::CBOARD_O)
	{
		std::cout << "Player 2 (Computer) is placing a Stone at (" << bestPosition.getRow() << ", " << bestPosition.getCol()
							<< ")...\n";
	}
	else
	{
		return CGlobal::RC_ERROR_UNKNOWN;
	}

	if (CGlobal::RC_SUCCESS != m_pBoard->setElementAt(CPosition{bestPosition.getRow(), bestPosition.getCol()}, m_stone))
	{
		return CGlobal::RC_ERROR;
	}

	return CGlobal::RC_SUCCESS;
}
