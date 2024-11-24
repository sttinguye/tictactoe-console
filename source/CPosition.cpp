/*
 * CPosition.cpp
 *
 *  Created on: 07.11.2023
 *      Author: profe
 */

#include "CPosition.h"

#include "CBoard.h" // for the macro CBOARD_MIN_NUMBER_OF_ROWS and CBOARD_MIN_NUMBER_OF_COLUMNS

#include <stdexcept>

unsigned short CPosition::m_numRows = CBOARD_MIN_NUMBER_OF_ROWS;

unsigned short CPosition::m_numCols = CBOARD_MIN_NUMBER_OF_COLUMNS;

CPosition::CPosition(unsigned short rowIndex, unsigned short columnIndex)
{
	if (rowIndex >= m_numRows || columnIndex >= m_numCols)
	{
		throw std::out_of_range("Coordinate values must be from 0 to 2.\n");
	}

	m_row = rowIndex;
	m_col = columnIndex;
}

void CPosition::setSize(unsigned short numRows, unsigned short numCols)
{
	m_numRows = numRows;
	m_numCols = numCols;
}

unsigned short CPosition::getRow()
{
	return m_row;
}

unsigned short CPosition::getCol()
{
	return m_col;
}

bool CPosition::operator ==(const CPosition &rop)
{
	if (m_row == rop.m_row && m_col == rop.m_col)
	{
		return true;
	}

	// else
	return false;
}

CPosition& CPosition::operator =(const CPosition &rop)
{
	// Protect from self assignment
	if (this == &rop) return *this;

	m_row = rop.m_row;
	m_col = rop.m_col;

	return (*this);
}
