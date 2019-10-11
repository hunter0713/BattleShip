/**
* \Author: Chance Penner
* \Author: Markus Becerra
* \Author: Sarah Scott
* \Author: Thomas Gardner
* \Author: Haonan Hu
* \File:   Ship.h
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
* \File:	 Ship.h
* \Date:   10/20/2019
* \Brief:  Ship header file defining all characteristics of ships as an object.
*/
#ifndef SHIP_H
#define SHIP_H

#include <string>
#include <iostream>
#include <fstream>

/**
 * The Ship class represents all the models of ships, from size 1 to 5
 * all the ship-related methods are included in this class
 */
class Ship
{
private:
std::string* m_ship;
int m_length;
int m_damage;

public:
  /**
  * @pre none
  *	@param none
  *	@post ship class constructor
  */
  Ship();

  /**
  * @pre length cannot exceed 5
  *	@param length of a ship
  *	@post creat a ship for desired length
  */
  void createShip(int length);

  /**
  *	private member variable helper function
  * @pre coordinates must within Boundary
  *	@param coordinate and index for ship placement
  *	@post set the coordinate for ship
  */
  void setCoordinate(std::string coordinate, int index);

  /**
  *	private member variable helper function
  * @pre none
  *	@param index for ship
  *	@post get the coordinate for ship
  * @return the coordinates for ship
  */
  std::string getCoordinate(int index) const;

  /**
  * private member variable helper function
  * @pre length cannnot exceed 5
  *	@param length for ship
  *	@post set the ship length
  */
  void setLength(int length);

  /**
  * private member variable helper function
  * @pre none
  *	@param none
  *	@post get the ship length
  * @return the length of ship
  */
  int getLength() const;

  /**
  * @pre none
  *	@param none
  *	@post ship destructor
  */
  ~Ship();

  /**
  * @pre none
  *	@param none
  *	@post check the ship's condition
  @ @return true if ship is sunk
  */
  bool isSunk();

  /**
  * @pre none
  *	@param none
  *	@post hit the enemy ship and give damage to it
  */
  void addDamage();

  /**
  * private member variable helper function
  * @pre none
  *	@param none
  *	@post get the ship damage condition
  @ @return the damage to the ship
  */
  int getDamage() const;

  /**
  * private member variable helper function
  * @pre damage cannot exceed 5
  *	@param number of damage to the ship
  *	@post set the damage condition to the ship
  @ @return none
  */
  void setDamage(int newDamage);

};
#endif
