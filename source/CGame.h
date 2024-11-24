/**
 * @file CGame.h
 * @brief This file contains the definition of the CGame class.
 */


#ifndef CGAME_H_
#define CGAME_H_

#include "CTicTacToeBoard.h"
#include "CPlayer.h"
#include "CDisplay.h"
#include "CGlobal.h"

//================== Configuration Macros =======================

/**
 * @brief This Macro defines number of players in a Game
 */
#define CGAME_NUMBER_OF_PLAYERS		2

/**
 * @brief This Macro defines command to choose Human Player
 */
#define CGAME_CHOOSE_HUMAN_COMMAND	1

/**
 * @brief This Macro defines command to choose Computer Player
 */
#define CGAME_CHOOSE_BOT_COMMAND	2

/**
 * @brief This Macro defines command to choose the Game of TicTacToe
 */
#define CGAME_CHOOSE_TICTACTOE_COMMAND	1

/**
 * @brief This Macro defines command to choose Eclipse Console
 */
#define CGAME_CHOOSE_ECLIPSE_CONSOLE_COMMAND	1

//===============================================================

/**
 * @brief A class representing a Game.
 *
 * This class represents the Game
 */
class CGame
{
public:
	/**
	 * @brief An enum representing the states of the Game.
	 */
	typedef enum
	{
		PLAYER_1_TURN,		/**< Player 1's turn */
		PLAYER_2_TURN,		/**< Player 2's turn */
		GAMEOVER,			/**< Game Over */
	}state_t;

private:
	/**
	 * @brief A member representing the Board of the Game.
	 */
	CTicTacToeBoard		m_board;

	/**
	 * @brief A member representing the Players of the Game.
	 */
	CPlayer*	m_player[CGAME_NUMBER_OF_PLAYERS];

	/**
	 * @brief A member representing the Display of the Game.
	 */
	CDisplay*	m_display;

	/**
	 * @brief A member representing the State of the Game.
	 */
	CGame::state_t	m_state;

	/**
	 * @brief Choose the Screen to interact with
	 *
	 * @return RC_SUCCESS if choose supported Screens (e.g., Eclipse Console)
	 */
	CGlobal::RC_t chooseScreen();

	/**
	 * @brief Choose the Races of the Players
	 *
	 * @return RC_SUCCESS if choose supported Races (e.g., Human or Bot)
	 */
	CGlobal::RC_t choosePlayer();

	/**
	 * @brief This function take inputs from the User (keyboard) to initialize the Game
	 */
	void init();

	/**
	 * @brief This function ignore redundant input from the User
	 *
	 * For example, if User enters "1fg", only the '1' will be extracted, the rest are ignored
	 */
	void ignoreRedundantKeyboardInput();

	/**
	 * @brief This function handles invalid inputs from the User's Keyboard
	 *
	 * This code is inspired from the post: https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/
	 */
	unsigned short getCommand();

public:
	/**
	 * @brief Default Constructor
	 */
	CGame();

	/**
	 * @brief Destructor
	 */
	virtual ~CGame();

	/**
	 * @brief This function runs the Game.
	 */
	CGlobal::RC_t run();
};

#endif /* CGAME_H_ */
