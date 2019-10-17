/**
* \Author: Chance Penner
* \Author: Markus Becerra
* \Author: Sarah Scott
* \Author: Thomas Gardner
* \Author: Haonan Hu
* \File:	 Board.h
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
* \File:	 Board.h
* \Date:   10/20/2019
* \Brief:  Class that acts as the data structure for ships and player shots.
*/
#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <iostream>
#include <stdexcept>
#include "Ship.h"
#include "algorithm"

/**
 * The Board class represents a general game board
 * the scale of the board is 8*8
 * all the game-related methods are included in this class
 */
class Board
{
private:
	std::string myBoard[8][8]; /**Board Containing the ships of a player*/
	std::string m_rowNames = "ABCDEFGH"; /**row axis labels*/
	std::string m_columnNames = "12345678";/**column axis labels*/
	int m_rowIndex;/**keeps track of row index*/
	int m_columnIndex;/**keeps track of column index*/
	/**
	* @pre none
	*	@param takes a location string from user
	*	@post converts userGuess to two array indices, updating rowIndex and columnIndex
	*/
	void guessConversion(std::string userGuess);
	int shipsLeft = numberOfShips;/**number of ships left in the game*/
	std::string blueTilde;/**character representing water*/
	std::string redHit;/**character representing a hit*/
	std::string whiteMiss;/**character representing a miss*/
	std::string ship;
	int numberOfShips;/**keeps track of number of ships in game*/
	Ship* m_ship = nullptr;/**m_ship pointer*/

public:
	/////////////////////////NEW_CODE//////////////////////////////
	/**
	* @pre none
	*	@param none
	*	@post asks the player where they want to place the ships.
	* uses with withinBoundary and edits myBoard and shotBoard
	*/
	void setupBoard_AI();
	/**
	* @pre none
	*	@param none
	*	@return: - The String containing the randomly generated coordinate.
	*/
	std::string randPosGen();
	/**
	* @pre none
	*	@param row: - row of position to check
		@param col: - col of position to check
	*	@return: - whether or not the position is a ship
	*/
	bool isShipPos(int row, int col);
	/**
	* @pre none
	*	@param row: - row of position to check
		@param col: - col of position to check
	*	@return: - whether or not the position is a hit
	*/
	bool isHitPos(int row, int col);



/**
*	private member variable helper function
* @pre none
*	@param takes a int for number of ships
*	@post change private member variable shipsLeft to tempNum
*/
void setShipsLeft(int tempNum, bool sunk);

/**
*	private member variable helper function
* @pre none
*	@param none
*	@post get private member variable shipsLeft
* @return number of Ships left
*/
int getShipsLeft() const;

	////////////////////////////OLD_CODE//////////////////////////
	std::string shotBoard[8][8];
	/**
	* @pre none
	*	@post board constructor
	*/
	Board();

	/**
	* @pre none
	*	@post Board destructor
	*/
	~Board();

	/**
	* @pre none
	*	@param numbers of ships will be passed in the method for board setting up
	*	@post set up board and fill board with blue tilde
	*/
	Board(int shipnum);

	/**
	* @pre none
	*	@param none
	*	@post print the shot board for player
	*/
	void printShotBoard();

	/**
	* @pre none
	*	@param none
	*	@post print the player board
	*/
	void printMyBoard();
	/**
	*	private member variable helper function
	* @pre none
	*	@param takes a int for number of ships
	*	@post change private member variable numberOfShips to shipnum
	*/
	void setNumberofShips(int shipnum);

	/**
	*	private member variable helper function
	* @pre none
	*	@param none
	*	@post get private member variable numberOfShips
	* @return number of Ships
	*/
	int getNumberofShips() const;



	/**
	* @pre none
	*	@param none
	*	@post asks the player where they want to place the ships.
	* uses with withinBoundary and edits myBoard and shotBoard
	*/
	void setupBoard();

	/**
	* @pre user guess location must be valid
	*	@param user's guee location and a boolean value checking hit or not
	*	@post if blueTilde, change to whiteMiss, if whiteMiss, prints you already shot here,
	* if redHit, prints you already shot here, if ship, change to redHit
	*/
	void updateShotBoard(std::string userGuess, bool wasHit);

	/**
	* @pre user guess location must be valid
	*	@param user's guess location
	*	@post updated player's board, if blueTilde, change to whiteMiss,
	*  if whiteMiss, prints you already shot here, if redHit, prints you already shot here,
	*  if ship, change to redHit
	* @return true if it hit a ship
	*/
	bool updateMyBoard(std::string userGuess);

	/**
	* @pre user's guess location must be valid
	*	@param user's guess location
	*	@post gets called from Player shoot function. Calls guessConversion. Needs to check for valid input.
	* @return true if user's guess is in boundary
	*/
	bool withinBoundary(std::string userGuess);

	/**
	* @pre user's guess location must be valid, ship length cant exceed 5
	*	@param user's guess location and size of ship
	*	@post check horizontal placed ship will collide with other ship or not
	* @return true if ships will collide
	*/
	bool noHorizontalCollision(std::string userGuess, int shipLength);

	/**
	* @pre user's guess location must be valid, ship length cant exceed 5
	*	@param user's guess location and size of ship
	*	@post check vertical placed ship will collide with other ship or not
	* @return true if ships will collide
	*/
	bool noVerticalCollision(std::string userGuess, int shipLength);

	/**
	*	private member variable helper function
	* @pre none
	*	@param none
	*	@post get ship object
	* @return ship object
	*/
	Ship* getShip() const;
	int getShipIndex(std::string aiGuess);//returns ship at location guessed by AI
	std::string getElement(int row, int col);
};
#endif
