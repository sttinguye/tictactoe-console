/**
 * @file CEclipseConsole.h
 * @brief This file contains the definition of the CEclipseConsole class.
 */

#ifndef CECLIPSECONSOLE_H_
#define CECLIPSECONSOLE_H_

#include "CDisplay.h"

/**
 * @brief A class representing an Eclipse Console
 *
 * This class inherits from class CDisplay
 */
class CEclipseConsole: public CDisplay
{
public:
	/**
	 * @brief Parameterized constructor for CEclipseConsole.
	 *
	 * @param[in] pBoard pointer to the CBoard object.
	 */
	CEclipseConsole(CBoard* pBoard);

	/**
	 * @brief Destructor
	 */
	virtual ~CEclipseConsole();

	/**
	 * @brief A method to print out the board.
	 */
	void print();
};

#endif /* CECLIPSECONSOLE_H_ */
