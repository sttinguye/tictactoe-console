/*
 * CTicTacToeBoard.cpp
 *
 *  Created on: 08.11.2023
 *      Author: profe
 */

#include "CTicTacToeBoard.h"

CTicTacToeBoard::CTicTacToeBoard() : CBoard()
{
}

CTicTacToeBoard::CTicTacToeBoard(unsigned short numRows, unsigned short numCols) : CBoard(numRows, numCols)
{
}


CTicTacToeBoard::~CTicTacToeBoard()
{
	// TODO Auto-generated destructor stub

	// which destructor is called?bn
}

unsigned short CTicTacToeBoard::countRow(const CBoard::player_t& stone)
{
	unsigned short numOfConsecutiveStones{0};

	unsigned short counterOfEachRow{0};

	for(unsigned short rowIndex = 0; rowIndex < m_numRows; rowIndex++)
	{
		for(unsigned short columnIndex = 0; columnIndex < m_numCols; columnIndex++)
		{
			if(m_cellStatuses[calculateIndex(rowIndex, columnIndex)] == stone)
			{
				counterOfEachRow++;
			}
		}

		if (numOfConsecutiveStones < counterOfEachRow)
		{
			numOfConsecutiveStones = counterOfEachRow;
		}

		//reset counter
		counterOfEachRow = 0;
	}

	return numOfConsecutiveStones;
}

unsigned short CTicTacToeBoard::countColumn(const CBoard::player_t& stone)
{
	unsigned short numOfConsecutiveStones{0};

	unsigned short counterOfEachColumn{0};

	for(unsigned short columnIndex = 0; columnIndex < m_numCols; columnIndex++)
	{
		for(unsigned short rowIndex = 0; rowIndex < m_numRows; rowIndex++)
		{
			if(m_cellStatuses[calculateIndex(rowIndex, columnIndex)] == stone)
			{
				counterOfEachColumn++;
			}
		}

		if (numOfConsecutiveStones < counterOfEachColumn)
		{
			numOfConsecutiveStones = counterOfEachColumn;
		}

		//reset counter
		counterOfEachColumn = 0;
	}

	return numOfConsecutiveStones;
}

unsigned short CTicTacToeBoard::countDiagonal(const CBoard::player_t& stone)
{
	unsigned short numOfConsecutiveStones{0};

	unsigned short counter{0};

	for(unsigned short rowIndex = 0; rowIndex < m_numRows; rowIndex++)
	{
		for(unsigned short columnIndex = 0; columnIndex < m_numCols; columnIndex++)
		{
			if(rowIndex == columnIndex && m_cellStatuses[calculateIndex(rowIndex, columnIndex)] == stone)
			{
				counter++;
			}
		}
	}

	if (numOfConsecutiveStones < counter)
	{
		numOfConsecutiveStones = counter;
	}

	//reset counter
	counter = 0;

	for(unsigned short rowIndex = 0; rowIndex < m_numRows; rowIndex++)
	{
		for(unsigned short columnIndex = 0; columnIndex < m_numCols; columnIndex++)
		{
			if((rowIndex+columnIndex) == (m_numRows-1) && m_cellStatuses[calculateIndex(rowIndex, columnIndex)] == stone)
			{
				counter++;
			}
		}
	}

	if (numOfConsecutiveStones < counter)
	{
		numOfConsecutiveStones = counter;
	}

	//reset counter
	counter = 0;

	return numOfConsecutiveStones;
}
