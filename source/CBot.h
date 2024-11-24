/**
 * @file CBot.h
 * @brief This file contains the definition of the CBot class.
 */

#ifndef CBOT_H_
#define CBOT_H_

#include "CPlayer.h"

/**
 * @brief A class representing a Computer Player.
 *
 * This class inherits from class CPlayer
 */
class CBot: public CPlayer
{
private:
	/**
	 * @brief Minimax algorithm used for the Bot to play the most optimal move.
	 *
	 * Source:
	 * Youtube:       https://www.youtube.com/watch?v=trKjYdBASyQ
	 * geeksforgeeks: https://www.geeksforgeeks.org/minimax-algorithm-in-game-theory-set-1-introduction/
	 * wikipedia:     https://en.wikipedia.org/wiki/Minimax
	 *
	 */
	int minimax(int depth, bool isMaximizing);

public:
	/**
	 * @brief Parameterized constructor for CBot.
	 *
	 * @param[in] pBoard pointer to the CTicTacToeBoard object.
	 * @param[in] stone stone of the player.
	 */
	CBot(CTicTacToeBoard* pBoard, const CBoard::player_t& stone);

	/**
	 * @brief Destructor
	 */
	virtual ~CBot();

	/**
	 * @brief A method to place Stone on the Board
	 *
	 * @return RC_SUCCESS if place Stone on a valid position.
	 */
	CGlobal::RC_t placeStone();
};

#endif /* CBOT_H_ */
