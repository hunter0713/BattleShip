/**
* \Author: Chance Penner
* \Author: Markus Becerra
* \Author: Sarah Scott
* \Author: Thomas Gardner
* \Author: Haonan Hu
* \File:	 Player.cpp
* \Date:   09/19/2019
* \Brief:  File is cpp file
* \copyright: Group "Big SegFault Energy" All rights reserved
*/
/**
* \Author: Hunter Cobb
* \Author: Zackariah Khazraeinazmpour
* \Author: Brandon Wheat
* \Author: Justin Khounsombath
* \Author: William Burdick
* \File:	 Executive.cpp
* \Date:   10/20/2019
* \Brief:  Player class that defines all the functions a player object can take
*/
#include "Player.h"

Player::Player(int shipNums)
{
	m_board = new Board(shipNums);
	numOfShips = shipNums;
}

Player::~Player()
{
  delete m_board;
}

void Player::setRecentGuess(std::string userGuess)
{
	recentguess = userGuess;
}

std::string Player::getRecentGuess() const
{
	return recentguess;
}

void Player::shooting(std::string userGuess, bool hit)
{
	m_board->updateShotBoard(userGuess, hit); //update the shot board after player shooting
}

bool Player::gettingShot(std::string userGuess)
{
	if(m_board->withinBoundary(userGuess)) // check userGuess within boundary or not
	{
		return (m_board->updateMyBoard(userGuess)); //updated player's board after get shot
	}
	else
	{
		throw(std::runtime_error("Out of Boundary! Try again.\n"));
	}

}

Board* Player::getBoard()
{
	return m_board;
}
