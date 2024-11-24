/**
 * @file CHumanPlayer.h
 * @brief This file contains the definition of the CGame class.
 */

#ifndef CHUMANPLAYER_H_
#define CHUMANPLAYER_H_

#include "CPlayer.h"

/**
 * @brief A class representing a Human Player.
 *
 * This class inherits from class CPlayer
 */
class CHumanPlayer: public CPlayer
{
public:
	/**
	 * @brief Parameterized constructor for CHumanPlayer.
	 *
	 * @param[in] pBoard pointer to the CTicTacToeBoard object.
	 * @param[in] stone stone of the player.
	 */
	CHumanPlayer(CTicTacToeBoard* pBoard, const CBoard::player_t& stone);

	/**
	 * @brief Destructor
	 */
	virtual ~CHumanPlayer();

	/**
	 * @brief A method to place Stone on the Board
	 *
	 * @return RC_SUCCESS if place Stone on a valid position.
	 */
	CGlobal::RC_t placeStone();
};

#endif /* CHUMANPLAYER_H_ */
