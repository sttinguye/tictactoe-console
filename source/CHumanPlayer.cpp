/*
 * CHumanPlayer.cpp
 *
 *  Created on: 08.11.2023
 *      Author: profe
 */

#include "CHumanPlayer.h"
#include "CPosition.h"
#include <iostream>
#include <stdexcept>

CHumanPlayer::CHumanPlayer(CTicTacToeBoard*	pBoard, const CBoard::player_t& stone) : CPlayer(pBoard, stone)
{
}

CHumanPlayer::~CHumanPlayer()
{
	// TODO Auto-generated destructor stub
}

CGlobal::RC_t CHumanPlayer::placeStone()
{
	try
	{
		if (m_stone == CBoard::CBOARD_X)
		{
			std::cout << "Player 1 places a Stone at coordinate: ";
		}
		else if (m_stone == CBoard::CBOARD_O)
		{
			std::cout << "Player 2 places a Stone at coordinate: ";
		}
		else
		{
			return CGlobal::RC_ERROR;
		}

		unsigned short row{};
		unsigned short column{};

		//TODO: add handling invalid input from user's keyboard here
		std::cin >> row >> column;

		if(row >= m_pBoard->getNumOfRows() || column >= m_pBoard->getNumOfColumns())
		{
			return CGlobal::RC_ERROR_RANGE;
		}

		CPosition pos{row, column};

		if (true != m_pBoard->positionIsEmpty(pos))
		{
			return CGlobal::RC_ERROR_INVALID;
		}

		std::cout << "placing a Stone at Coordinate (" << row << ", " << column << ")...\n";

		if (CGlobal::RC_SUCCESS != m_pBoard->setElementAt(pos, m_stone))
		{
			return CGlobal::RC_ERROR;
		}

		return CGlobal::RC_SUCCESS;
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Exception caught in CHumanPlayer::placeStone(): " << ex.what() << std::endl;
		return CGlobal::RC_ERROR;
	}

	// put here so the compiler does not complain
	return CGlobal::RC_ERROR_UNKNOWN;
}

