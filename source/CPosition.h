/**
 * @file CPosition.h
 * @brief This file contains the definition of the CPosition class.
 */

#ifndef CPOSITION_H_
#define CPOSITION_H_

/**
 * @brief A class representing a position that has row and column coordinate
 */
class CPosition
{
private:
	/**
	 * @brief A member representing the max number of rows of the CPosition class
	 *
	 * This is a static member, meaning it belongs to the class rather than the object itself.
	 */
	static unsigned short m_numRows;

	/**
	 * @brief A member representing the max number of columns of the CPosition class
	 *
	 * This is a static member, meaning it belongs to the class rather than the object itself.
	 */
	static unsigned short m_numCols;

	/**
	 * @brief A member representing the row coordinate of the position object
	 */
	unsigned short	m_row;

	/**
	 * @brief A member representing the column coordinate of the position object
	 */
	unsigned short	m_col;

	/**
	 * @brief A member method to set the number of rows and number of columns of the class itself.
	 *
	 * @param[in] numRows number of rows.
	 * @param[in] numCols number of columns.
	 */
	static void setSize(unsigned short numRows, unsigned short numCols);

public:
	/**
	 * @brief Parameterized constructor for CPosition.
	 *
	 * @param[in] rowIndex row coordinate.
	 * @param[in] columnIndex column coordinate.
	 */
	explicit CPosition(unsigned short rowIndex, unsigned short columnIndex);

	/**
	 * @brief A method that returns the row coordinate of the position.
	 *
	 * @return The row coordinate of the position.
	 */
	unsigned short getRow();

	/**
	 * @brief A method that returns the column coordinate of the position.
	 *
	 * @return The column coordinate of the position.
	 */
	unsigned short getCol();

	/**
	 * @brief Overloaded equality operator.
	 *
	 * This operator compares two CPosition objects for equality.
	 *
	 * @param[in] rop The right-operand side CPosition object.
	 * @return True if the objects are equal, false otherwise.
	 */
	bool operator==(const CPosition& rop);

	/**
	 * @brief Overloaded assignment operator.
	 *
	 * This operator assigns the value of one CPosition object to another.
	 *
	 * @param[in] rop The right-operand side CPosition object.
	 * @return A reference to the left-operand side CPosition object.
	 */
	CPosition& operator=(const CPosition& rop);

	/**
	 * @brief A friend class that can access CPosition's private members.
	 */
	friend class CBoard;
};

#endif /* CPOSITION_H_ */
