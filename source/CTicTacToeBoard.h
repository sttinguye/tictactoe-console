/**
 * @file CTicTacToeBoard.h
 * @brief This file contains the definition of the CTicTacToeBoard class.
 */

#ifndef CTICTACTOEBOARD_H_
#define CTICTACTOEBOARD_H_

#include "CBoard.h"

//================== Configuration Macros =======================

/**
 * @brief This Macro defines how many consecutive Stones on the Board that determine Victory
 */
#define CTICTACTOEBOARD_NUM_OF_STONES_THAT_WIN	3

//===============================================================

/**
 * @brief A class representing a TicTacToe Board
 *
 * This class inherits from class CBoard
 */
class CTicTacToeBoard: public CBoard
{
public:
	/**
	 * @brief Default Constructor
	 */
	CTicTacToeBoard();

	/**
	 * @brief Parameterized constructor for CBoard.
	 *
	 * @param[in] numRows number of rows.
	 * @param[in] numCols number of columns.
	 */
	CTicTacToeBoard(unsigned short numRows, unsigned short numCols);

	/**
	 * @brief Destructor
	 */
	virtual ~CTicTacToeBoard();

	/**
	 * @brief A method to count number of the stone in 3 rows and return the largest number out of 3 rows.
	 *
	 * @param[in] stone the stone to be counted.
	 * @return largest number of the stones out of the 3 rows.
	 */
	unsigned short countRow(const CBoard::player_t& stone);

	/**
	 * @brief A method to count number of the stone in 3 columns and return the largest number out of 3 columns.
	 *
	 * @param[in] stone the stone to be counted.
	 * @return largest number of the stones out of the 3 columns.
	 */
	unsigned short countColumn(const CBoard::player_t& stone);

	/**
	 * @brief A method to count number of the stone in 2 diagonal lines and return the largest number out of 2 diagonal lines.
	 *
	 * @param[in] stone the stone to be counted.
	 * @return largest number of the stones out of the 2 diagonal lines.
	 */
	unsigned short countDiagonal(const CBoard::player_t& stone);

};

#endif /* CTICTACTOEBOARD_H_ */
