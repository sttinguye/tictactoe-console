/*
 * CGame.cpp
 *
 *  Created on: 07.11.2023
 *      Author: profe
 */

#include "CGame.h"
#include "CHumanPlayer.h"
#include "CBot.h"
#include "CEclipseConsole.h"
#include "CTicTacToeBoard.h"
#include "CBoard.h"

#include <iostream>
#include <limits> // for std::numeric_limits

CGame::CGame()
{
	init();
}

CGame::~CGame()
{
	for(unsigned short i = 0; i < CGAME_NUMBER_OF_PLAYERS; i ++)
	{
		if (m_player[i])
		{
			delete m_player[i];
		}
		m_player[i] = nullptr;
	}

	if (m_display)
	{
		delete m_display;
		m_display = nullptr;
	}
}

void CGame::init()
{
	std::cout << "\n###########################################\n";
	std::cout << "###       Welcome to the Game Center    ###\n";
	std::cout << "###########################################\n\n";

	// initialize the state
	m_state = CGame::PLAYER_1_TURN;

	//initialize the board
	m_board = CTicTacToeBoard{CBOARD_MIN_NUMBER_OF_ROWS, CBOARD_MIN_NUMBER_OF_COLUMNS};

	std::cout << '\n';

	while (CGlobal::RC_SUCCESS != chooseScreen())
	{
		std::cout << "Please choose your Screen again!\n\n";
	}

	std::cout << '\n';

	while (CGlobal::RC_SUCCESS != choosePlayer())
	{
		std::cout << "Please input correct Player choosing command again!\n\n";
	}

	std::cout << '\n';

	std::cout << "#Instructions: type in 2 numbers indicating row and column index of a coordinate to play\n";
	std::cout << "For example, typing \"0 0\" will place a Stone at Coordinate (0, 0) on the Board.\n";

	std::cout << '\n';
}

CGlobal::RC_t CGame::chooseScreen()
{
	//TODO: add handling invalid input from user's keyboard

	std::cout << "#Choose which type of Screen you want to interact with: \n";
	std::cout << "1. Eclipse Console (type '1' and press Enter)\n";
	std::cout << "2. LG 4K OLED Ultra Slim ThinQ (not supported yet)\n";
	std::cout << "Your option: ";

	unsigned short displayOption{getCommand()};

	switch(displayOption)
	{
	case CGAME_CHOOSE_ECLIPSE_CONSOLE_COMMAND:
		m_display = new CEclipseConsole{&m_board};
		break;

	default:
		std::cout << "This type of Screen is not supported yet! Sorry :-(\n";
		return CGlobal::RC_ERROR;
	}

	return CGlobal::RC_SUCCESS;
}

CGlobal::RC_t CGame::choosePlayer()
{
	//TODO: add handling invalid input from user's keyboard

	unsigned short playerRaceIndex[CGAME_NUMBER_OF_PLAYERS] {};

	for (unsigned short i = 0; i < CGAME_NUMBER_OF_PLAYERS; i ++)
	{
		std::cout << "#Select Player " << i + 1 <<
				"'s race: (1 - human, 2 - computer) : ";

		playerRaceIndex[i] = getCommand();

		switch (playerRaceIndex[i])
		{
		case CGAME_CHOOSE_HUMAN_COMMAND:
			if (i == 0)
			{
				// How does this even work??
				m_player[i] = new CHumanPlayer{&m_board, CBoard::CBOARD_X};
			}
			else if (i == 1)
			{
				m_player[i] = new CHumanPlayer{&m_board, CBoard::CBOARD_O};
			}
			else
			{
				//TODO: add error handling
			}
			break;

		case CGAME_CHOOSE_BOT_COMMAND:
			if (i == 0)
			{
				m_player[i] = new CBot{&m_board, CBoard::CBOARD_X};
			}
			else if (i == 1)
			{
				m_player[i] = new CBot{&m_board, CBoard::CBOARD_O};
			}
			else
			{
				//TODO: add error handling
			}
			break;

		default:
			std::cout << "invalid command!\n";
			return CGlobal::RC_ERROR;
		}// end of switch case
	}// end of for loop

	return CGlobal::RC_SUCCESS;
}

void CGame::ignoreRedundantKeyboardInput()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

unsigned short CGame::getCommand()
{
	// Loop a valid input is entered
	while (1)
	{
		unsigned short input{};
		std::cin >> input;

		// Check for failed extraction: e.g., a Lunatic enters 'a'
		if (!std::cin) // if the previous extraction failed
		{
			if (std::cin.eof()) // if the input stream was closed
			{
				std::exit(0);
			}

			std::cin.clear(); // reset std::cin, make it takes input again.
			ignoreRedundantKeyboardInput();     // and remove the bad input

			std::cout << "Invalid command. Please try again!\nYour option: ";
		}
		else
		{
			ignoreRedundantKeyboardInput(); // remove any extraneous input
			return input;
		}
	}

	// put here so that the compiler does not complain
	return 0;
}

CGlobal::RC_t CGame::run()
{
	unsigned short totalNumOfRounds {static_cast<unsigned short>(m_board.getNumOfRows() * m_board.getNumOfColumns())};

	unsigned short currentRound{0};

	while (currentRound < totalNumOfRounds)
	{
		// just in case
		if (currentRound >= totalNumOfRounds)
			return CGlobal::RC_ERROR;

		switch(m_state)
		{
		case CGame::PLAYER_1_TURN:
			std::cout << "#Round " << currentRound + 1 << '\n';

			/**
			 * - Event: place Stone failed
			 * - Guard: none
			 */
			if (CGlobal::RC_SUCCESS !=
								m_player[currentRound % CGAME_NUMBER_OF_PLAYERS]->placeStone())
			{
				std::cout << "invalid coordinate! Please input again!\n\n";
				m_state = CGame::PLAYER_1_TURN;
				break;
			}

			/**
			 * - Event: place Stone successfully
			 * - Guard: if Player 1 has 3 consecutive Stones on the same row, or column, or diagonal
			 */
			if(m_player[currentRound % CGAME_NUMBER_OF_PLAYERS]->isWin())
			{
				m_state = CGame::GAMEOVER;
				m_display->print();
				std::cout << "Player 1 wins!!\n";
				break;
			}

			/**
			 * - Event: place Stone successfully
			 * - Guard: if Player 1 has NO 3 consecutive Stones on the same row, or column, or diagonal
			 */
			m_state = CGame::PLAYER_2_TURN;
			m_display->print();

			currentRound++;
			break;

		case CGame::PLAYER_2_TURN:
			std::cout << "#Round " << currentRound + 1 << '\n';

			/**
			 * - Event: place Stone failed
			 * - Guard: none
			 */
			if (CGlobal::RC_SUCCESS !=
					m_player[currentRound % CGAME_NUMBER_OF_PLAYERS]->placeStone())
			{
				std::cout << "invalid coordinate! Please input again!\n\n";
				m_state = CGame::PLAYER_2_TURN;
				break;
			}

			/**
			 * - Event: place Stone successfully
			 * - Guard: if Player 2 has 3 consecutive Stones on the same row, or column, or diagonal
			 */
			if(m_player[currentRound % CGAME_NUMBER_OF_PLAYERS]->isWin())
			{
				m_state = CGame::GAMEOVER;
				m_display->print();
				std::cout << "Player 2 wins!!\n";
				break;
			}

			/**
			 * - Event: place Stone successfully
			 * - Guard: if Player 2 has NO 3 consecutive Stones on the same row, or column, or diagonal
			 */
			m_state = CGame::PLAYER_1_TURN;
			m_display->print();

			currentRound++;
			break;

		case CGame::GAMEOVER:
			return CGlobal::RC_SUCCESS;

		default:
			return CGlobal::RC_ERROR_INVALID_STATE;

		}// end of switch case

	}// end of while

	std::cout << "Tie!\n";

	return CGlobal::RC_SUCCESS;
}
