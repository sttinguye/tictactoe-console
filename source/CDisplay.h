/**
 * @file CDisplay.h
 * @brief This file contains the definition of the CDisplay class.
 */

#ifndef CDISPLAY_H_
#define CDISPLAY_H_

#include "CBoard.h"

/**
 * @brief A class representing an abstract Display
 *
 * This class is an abstract class which is inherited by the CEclipseConsole class
 */
class CDisplay
{
protected:
	/**
	 * @brief A member representing the Association relationship with the CBoard object.
	 */
	CBoard* m_pBoard;

public:
	/**
	 * @brief Parameterized constructor for CDisplay.
	 *
	 * @param[in] pBoard pointer to the CBoard object.
	 */
	CDisplay(CBoard* pBoard);

	/**
	 * @brief Destructor
	 */
	virtual ~CDisplay();

	/**
	 * @brief A method to print out the board.
	 */
	virtual void print() = 0;
};

#endif /* CDISPLAY_H_ */
