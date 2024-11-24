/*
 * CPlayer.cpp
 *
 *  Created on: 07.11.2023
 *      Author: profe
 */

#include "CPlayer.h"
#include <iostream>

CPlayer::CPlayer(CTicTacToeBoard *pBoard, const CBoard::player_t &stone)
{
	m_pBoard = pBoard;
	m_stone = stone;
}

CPlayer::~CPlayer()
{
	// TODO Auto-generated destructor stub
}

bool CPlayer::isWin()
{
	if (m_pBoard->countRow(m_stone) == CTICTACTOEBOARD_NUM_OF_STONES_THAT_WIN)
	{
		return true;
	}
	else if (m_pBoard->countColumn(m_stone) == CTICTACTOEBOARD_NUM_OF_STONES_THAT_WIN)
	{
		return true;
	}
	else if (m_pBoard->countDiagonal(m_stone) == CTICTACTOEBOARD_NUM_OF_STONES_THAT_WIN)
	{
		return true;
	}
	else
	{
		//don't care
	}

	return false;
}

CBoard::player_t CPlayer::opponentStone()
{
	if (m_stone == CBoard::player_t::CBOARD_X)
	{
		return CBoard::player_t::CBOARD_O;
	}

	return CBoard::player_t::CBOARD_X;
}

bool CPlayer::isMyOpponentWin()
{
	CBoard::player_t stone{ opponentStone() };

	if (m_pBoard->countRow(stone) == CTICTACTOEBOARD_NUM_OF_STONES_THAT_WIN)
	{
		return true;
	}
	else if (m_pBoard->countColumn(stone) == CTICTACTOEBOARD_NUM_OF_STONES_THAT_WIN)
	{
		return true;
	}
	else if (m_pBoard->countDiagonal(stone) == CTICTACTOEBOARD_NUM_OF_STONES_THAT_WIN)
	{
		return true;
	}
	else
	{
		//don't care
	}

	return false;
}

CBoard::player_t CPlayer::checkWinner()
{
//	unsigned short emptyStoneCount{0};
//
//	for(unsigned short rowIndex = 0; rowIndex < m_pBoard->getNumOfRows(); rowIndex++)
//	{
//		for(unsigned short columnIndex = 0; columnIndex <  m_pBoard->getNumOfColumns(); columnIndex++)
//		{
//			if (m_pBoard->getElementAt(rowIndex, columnIndex) == CBoard::player_t::CBOARD_EMPTY)
//			{
//				emptyStoneCount++;
//			}
//		}
//	}

	// check if a Tie!
//	if (emptyStoneCount == 0)
//	{
//		return CBoard::player_t::CBOARD_EMPTY;
//	}

	if (isBoardFull())
	{
		return CBoard::player_t::CBOARD_EMPTY;
	}
	else if(isWin())
	{
		return m_stone;
	}
	else if(isMyOpponentWin())
	{
		return opponentStone();
	}
	else
	{
		return CBoard::player_t::CBOARD_UNKNOWN;
	}

	return CBoard::player_t::CBOARD_UNKNOWN;
}

bool CPlayer::isBoardFull()
{
	for(unsigned short rowIndex = 0; rowIndex < m_pBoard->getNumOfRows(); rowIndex++)
	{
		for(unsigned short columnIndex = 0; columnIndex <  m_pBoard->getNumOfColumns(); columnIndex++)
		{
			if (m_pBoard->getElementAt(rowIndex, columnIndex) == CBoard::player_t::CBOARD_EMPTY)
			{
				return false;
			}
		}
	}

	return true;
}
