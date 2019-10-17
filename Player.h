/**
* \Author: Chance Penner
* \Author: Markus Becerra
* \Author: Sarah Scott
* \Author: Thomas Gardner
* \Author: Haonan Hu
* \File:   Player.h
* \Date:   09/19/2019
* \Brief:  File is header file
* \copyright: Group "Big SegFault Energy" All rights reserved
*/
/**
* \Author: Hunter Cobb
* \Author: Zackariah Khazraeinazmpour
* \Author: Brandon Wheat
* \Author: Justin Khounsombath
* \Author: William Burdick
* \File:	 Player.cpp
* \Date:   10/20/2019
* \Brief:  Player header file that plans out what exactly a player can do and what a player consists of.
*/
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Board.h"

/**
 * The Player class represents players in the game
 * all the Player-related methods are included in this class
 */
class Player
{
private:

  Board* m_board = nullptr;/**board pointer for the player*/
  std::string recentguess; /**most recent guess*/
  int numOfShips; /**number of ships for each player*/

public:
  /**
  * @pre none
  *	@param none
  *	@player constructor
  */
  Player(int shipsNum);

  /**
  * @pre none
  *	@param none
  *	@post player destructor
  */
  ~Player();

  /**
  * private member variable helper function
  * @pre guess must be valid
  *	@param user's guess location
  *	@post set the most recent uer guess location
  */
  void setRecentGuess(std::string guess);

  /**
  * private member variable helper function
  * @pre none
  *	@param none
  *	@post get the most recent user's guess location
  * @return user's guess location
  */
  std::string getRecentGuess() const;

  /**
  * @pre user's guess loaction must be valid
  *	@param user's guess location and boolean value hit
  *	@post shoot the board with the location that user guesses
  */
  void shooting(std::string guess, bool hit);

  /**
  * @pre user's guess loaction must be valid
  *	@param user's guess location
  *	@post check the player got shot or not
  * @return ture if player got shot
  */
  bool gettingShot(std::string guess);

  /**
  * @pre none
  *	@param none
  *	@post the the player's board
  * @return player's board
  */
  Board* getBoard();
};
#endif
