/*
 * CBoard.cpp
 *
 *  Created on: 07.11.2023
 *      Author: profe
 */

#include "CBoard.h"
#include <iostream>

CBoard::CBoard()
{
	std::cout << "CBoard default Constructor invoked\n";

	m_numRows = CBOARD_MIN_NUMBER_OF_ROWS;
	m_numCols = CBOARD_MIN_NUMBER_OF_COLUMNS;

	unsigned short boardSize{static_cast<unsigned short>(m_numRows * m_numCols)};
	m_cellStatuses = new CBoard::player_t[boardSize];

	// initialize values
	for (unsigned short i = 0; i < boardSize; i++)
	{
		m_cellStatuses[i] = CBoard::CBOARD_EMPTY;
	}

	CPosition::setSize(m_numRows, m_numCols);
}

CBoard::CBoard(unsigned short numRows, unsigned short numCols)
{
	//TODO: add error handling

	m_numRows = numRows;
	m_numCols = numCols;

	unsigned short boardSize{static_cast<unsigned short>(m_numRows * m_numCols)};
	m_cellStatuses = new CBoard::player_t[boardSize];

	// initialize values
	for (unsigned short i = 0; i < boardSize; i++)
	{
		m_cellStatuses[i] = CBoard::CBOARD_EMPTY;
	}

	CPosition::setSize(m_numRows, m_numCols);
}

CBoard::~CBoard()
{
	delete[] m_cellStatuses;
	m_cellStatuses = nullptr;
}

unsigned short CBoard::getNumOfRows()
{
	return m_numRows;
}

unsigned short CBoard::calculateIndex(unsigned short rowIndex,
		unsigned short columnIndex)
{
	return ((rowIndex * m_numCols) + columnIndex);
}

unsigned short CBoard::getNumOfColumns()
{
	return m_numCols;
}

CBoard::player_t CBoard::getElementAt(unsigned short rowIndex,
		unsigned short columnIndex)
{
	return m_cellStatuses[calculateIndex(rowIndex, columnIndex)];
}

void CBoard::clear()
{
	for(unsigned short rowIndex = 0; rowIndex < m_numRows; rowIndex++)
	{
		for(unsigned short columnIndex = 0; columnIndex < m_numCols; columnIndex++)
		{
			m_cellStatuses[calculateIndex(rowIndex, columnIndex)] = CBoard::CBOARD_EMPTY;
		}
	}
}

CGlobal::RC_t CBoard::setElementAt(const CPosition& pos, const CBoard::player_t& playerStone)
{
	// cannot do check if position is empty here because
	// it will affect the place Stone of the Computer player.

	if (pos.m_row >= pos.m_numRows || pos.m_col >= pos.m_numCols)
	{
		return CGlobal::RC_ERROR_BAD_PARAM;
	}

	m_cellStatuses[calculateIndex(pos.m_row, pos.m_col)] = playerStone;

	return CGlobal::RC_SUCCESS;
}

bool CBoard::positionIsEmpty(const CPosition &pos)
{
	return (m_cellStatuses[calculateIndex(pos.m_row, pos.m_col)] == CBoard::CBOARD_EMPTY);
}

CBoard& CBoard::operator =(const CBoard &rop)
{
	if((m_numRows != rop.m_numRows) || (m_numCols != rop.m_numCols))
	{
		//release memory
		delete[] m_cellStatuses;
		m_cellStatuses = nullptr;

		//allocate memory
		m_numRows = rop.m_numRows;
		m_numCols = rop.m_numCols;
		unsigned short boardSize{static_cast<unsigned short>(m_numRows * m_numCols)};
		m_cellStatuses = new CBoard::player_t[boardSize];

		// initialize values
		for (unsigned short i = 0; i < boardSize; i++)
		{
			m_cellStatuses[i] = CBoard::CBOARD_EMPTY;
		}

		//set the CPosition class size also.
		CPosition::setSize(m_numRows, m_numCols);
	}

	//start assigning
	for(unsigned short i = 0; i < m_numRows; i++)
	{
		for(unsigned short j = 0; j < m_numCols; j++)
		{
			m_cellStatuses[calculateIndex(i, j)] = rop.m_cellStatuses[calculateIndex(i, j)];
		}
	}

	return *this;
}
