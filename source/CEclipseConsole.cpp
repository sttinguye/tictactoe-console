/*
 * CEclipseConsole.cpp
 *
 *  Created on: 08.11.2023
 *      Author: profe
 */

#include "CEclipseConsole.h"
#include <iostream>

CEclipseConsole::CEclipseConsole(CBoard* pBoard) : CDisplay(pBoard)
{
}

CEclipseConsole::~CEclipseConsole()
{

}

void CEclipseConsole::print()
{
	for(unsigned short rowIndex = 0; rowIndex < m_pBoard->getNumOfRows(); rowIndex++)
	{
		for(unsigned short columnIndex = 0; columnIndex < m_pBoard->getNumOfColumns(); columnIndex++)
		{
			switch (m_pBoard->getElementAt(rowIndex, columnIndex))
			{
			case CBoard::CBOARD_EMPTY:
				std::cout << ". ";
				break;

			case CBoard::CBOARD_X:
				std::cout << "x ";
				break;

			case CBoard::CBOARD_O:
				std::cout << "o ";
				break;

			default:
				//error handling
				break;
			}
		}

		std::cout << '\n';
	}
	std::cout << '\n';
}
