/**
 * @file CBoard.h
 * @brief This file contains the definition of the CBoard class.
 */

#ifndef CBOARD_H_
#define CBOARD_H_

#include "CPosition.h"
#include "CGlobal.h"

//================== Configuration Macros =======================

/**
 * @brief This Macro defines the minimum number of rows the CBoard object can have
 */
#define CBOARD_MIN_NUMBER_OF_ROWS		3

/**
 * @brief This Macro defines the minimum number of columns the CBoard object can have
 */
#define CBOARD_MIN_NUMBER_OF_COLUMNS	3

//===============================================================

/**
 * @brief A class representing an abstract Board
 *
 * This class is an abstract class which is inherited by the CTicTacToeBoard class
 */
class CBoard
{
public:
	/**
	 * @brief An enum representing the stones of the player
	 */
	typedef enum
	{
		CBOARD_EMPTY,	/**< empty or null */
		CBOARD_X,		/**< Player 1's stone */
		CBOARD_O,		/**< Player 2's stone */
		CBOARD_UNKNOWN,/**< unknown stone, used for the Minimax algorithm (in method CBot::minimax(int depth, bool isMaximizing)) */
	}player_t;

protected:
	/**
	 * @brief A member representing the number of rows of the Board.
	 */
	unsigned short		m_numRows;

	/**
	 * @brief A member representing the number of columns of the Board.
	 */
	unsigned short		m_numCols;

	/**
	 * @brief An array of the Cells of the Board which contain the Player's stones.
	 */
	CBoard::player_t*	m_cellStatuses;

	/**
	 * @brief A method to convert coordinate into array index.
	 */
	unsigned short calculateIndex(unsigned short rowIndex, unsigned short columnIndex);

public:
	/**
	 * @brief Default Constructor
	 */
	CBoard();

	/**
	 * @brief Parameterized constructor for CBoard.
	 *
	 * @param[in] numRows number of rows.
	 * @param[in] numCols number of columns.
	 */
	CBoard(unsigned short numRows, unsigned short numCols);

	/**
	 * @brief Destructor
	 */
	virtual ~CBoard();

	/**
	 * @brief A method that returns the number of rows of the Board
	 *
	 * @return The Board's number of rows.
	 */
	unsigned short getNumOfRows();

	/**
	 * @brief A method that returns the number of columns of the Board
	 *
	 * @return The Board's number of columns.
	 */
	unsigned short getNumOfColumns();

	/**
	 * @brief A method that returns the number of columns of the Board
	 *
	 * @return The Board's number of columns.
	 */
	CBoard::player_t getElementAt(unsigned short rowIndex, unsigned short columnIndex);

	/**
	 * @brief A method to clear the Board.
	 */
	void clear();

	/**
	 * @brief A method to place a Stone on the Board via the CPosition object
	 *
	 * @param[in] pos a coordinate object containing information of the row and column.
	 * @param[in] playerStone the stone to be placed on the Board.
	 *
	 * @return RC_SUCCESS if element is valid
	 */
	CGlobal::RC_t setElementAt(const CPosition& pos, const CBoard::player_t& playerStone);

	/**
	 * @brief A method to check if a position on the Board is occupied or not
	 *
	 * @param[in] pos a coordinate object containing information of the row and column.
	 * @return true or false.
	 */
	bool positionIsEmpty(const CPosition& pos);

	/**
	 * @brief overloaded assignment operator
	 *
	 * @param[in] rop The right-operand side CBoard object.
	 * @return A reference to the left-operand side CBoard object.
	 */
	CBoard& operator=(const CBoard& rop);
};

#endif /* CBOARD_H_ */
