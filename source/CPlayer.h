/**
 * @file CPlayer.h
 * @brief This file contains the definition of the CPlayer class.
 */

#ifndef CPLAYER_H_
#define CPLAYER_H_

#include "CTicTacToeBoard.h"
#include "CPosition.h"
#include "CGlobal.h"

/**
 * @brief A class representing an abstract Player
 *
 * This class is an abstract class which is inherited by the CHumanPlayer and CBot class
 */
class CPlayer
{
protected:
	/**
	 * @brief A member representing the Association relationship with the CTicTacBoard object.
	 */
	CTicTacToeBoard*	m_pBoard;

	/**
	 * @brief A member representing the player's stone.
	 */
	CBoard::player_t 	m_stone;

	/**
	 * @brief A member method returning the opponent's stone.
	 *
	 * @return the stone of the opponent player
	 */
	CBoard::player_t opponentStone();

	/**
	 * @brief A member method to tell if the opponent has won the game.
	 *
	 * This method is called by method checkWinner() to check who wins, which is in turn called by method
	 * CBot::minimax(int depth, bool isMaximizing) for the Minimax algorithm.
	 *
	 * @return the stone of the opponent player
	 */
	bool isMyOpponentWin();

	/**
	 * @brief A member method to tell who is the winner.
	 *
	 * This method is called by method
	 * CBot::minimax(int depth, bool isMaximizing) for the Minimax algorithm.
	 *
	 * @return the stone of the winner.
	 */
	CBoard::player_t checkWinner();

	/**
	 * @brief A member method to tell if there is no empty slot left.
	 *
	 * This method is called by method
	 * CBot::minimax(int depth, bool isMaximizing) for the Minimax algorithm.
	 *
	 * @return true or false
	 */
	bool isBoardFull();

public:
	/**
	 * @brief Parameterized constructor for Player.
	 *
	 * @param[in] pBoard pointer to the object CTicTacToeBoard.
	 * @param[in] stone stone of the player.
	 */
	CPlayer(CTicTacToeBoard* pBoard, const CBoard::player_t& stone);

	/**
	 * @brief Destructor
	 */
	virtual ~CPlayer();

	/**
	 * @brief A method that tells if the player has won.
	 *
	 * @return true or false
	 */
	bool isWin();

	/**
	 * @brief A method to place Stone on the Board
	 *
	 * @return RC_SUCCESS if place Stone on a valid position.
	 */
	virtual CGlobal::RC_t placeStone() = 0;
};

#endif /* CPLAYER_H_ */
