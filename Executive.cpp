/**
* \Author: Chance Penner
* \Author: Markus Becerra
* \Author: Sarah Scott
* \Author: Thomas Gardner
* \Author: Haonan Hu
* \File:	 Executive.cpp
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
* \Brief:  Executive file where majority of game is run. Added AI game and AI turns.
*/
#include "Executive.h"
#include <limits>
#include "algorithm" //for toupper


int Executive::boatCheck() //will return numOfBoats when valid
{
	int numOfBoats = 0;						//declaring numberOfBoats
	std::string tempBoats = " ";	//declaring tempBoats string for storing numOfBoats as a string

	std::cout << "How many ships would you like to play with? (Choose 1-5): ";		//prompt user for number of ships

	std::getline(std::cin, tempBoats);		//Gather the users desired number of boats in a getline

	if(tempBoats.length() < 1 || tempBoats.length() > 1)		//check if the length of the string is NOT equal to one
	{
		std::cout << "Must be a one-digit number from 1-5!\n";	//print error that the digit was greater than length 1
		return boatCheck();		//return the boatCheck function to get a new input for the number of boats desired
	}

	else		//if the tempBoats length was equal to 1
	{
		numOfBoats = tempBoats.at(0) - '0';		//set numOfBoats integer equal to the first character of the tempBoats string

		if(numOfBoats < 1 || numOfBoats > 5)		//if numOfBoats is not between one and five (inclusive)
		{
			std::cout << "Must be an integer from 1-5!\n";		//print error message that the number is out of the range
			return boatCheck();		//return boatCheck function to get a new input for the number of boats desired
		}

		else
		{
			return numOfBoats;		//if the number of boats is valid (1-5), return the integer itself
		}
	}

}

Executive::Executive()		//Executive constructor
{
  cout<<"==================================================================================================================================\n";
	cout<<" ▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄            ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄         ▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄ \n";
	cout<<"▐░░░░░░░░░░▌ ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌          ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌\n";
	cout<<"▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌ ▀▀▀▀█░█▀▀▀▀  ▀▀▀▀█░█▀▀▀▀ ▐░▌          ▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀▀▀ ▐░▌       ▐░▌ ▀▀▀▀█░█▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌\n";
	cout<<"▐░▌       ▐░▌▐░▌       ▐░▌     ▐░▌          ▐░▌     ▐░▌          ▐░▌          ▐░▌          ▐░▌       ▐░▌     ▐░▌     ▐░▌       ▐░▌\n";
	cout<<" ░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌     ▐░▌          ▐░▌     ▐░▌          ▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄█░▌     ▐░▌     ▐░█▄▄▄▄▄▄▄█░▌\n";
	cout<<"▐░░░░░░░░░░▌ ▐░░░░░░░░░░░▌     ▐░▌          ▐░▌     ▐░▌          ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌     ▐░▌     ▐░░░░░░░░░░░▌\n";
	cout<<"▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌     ▐░▌          ▐░▌     ▐░▌          ▐░█▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌     ▐░▌     ▐░█▀▀▀▀▀▀▀▀▀ \n";
	cout<<"▐░▌       ▐░▌▐░▌       ▐░▌     ▐░▌          ▐░▌     ▐░▌          ▐░▌                    ▐░▌▐░▌       ▐░▌     ▐░▌     ▐░▌          \n";
	cout<<"▐░█▄▄▄▄▄▄▄█░▌▐░▌       ▐░▌     ▐░▌          ▐░▌     ▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄█░▌▐░▌       ▐░▌ ▄▄▄▄█░█▄▄▄▄ ▐░▌          \n";
	cout<<"▐░░░░░░░░░░▌ ▐░▌       ▐░▌     ▐░▌          ▐░▌     ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░▌          \n";
	cout<<" ▀▀▀▀▀▀▀▀▀▀   ▀         ▀       ▀            ▀       ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀         ▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀           \n";
	cout<<"==================================================================================================================================\n";

	explosionAnimation();
	start = false;
	menuChoice =0;
	int numOfBoats = 0;		//int numOfBoats to store the number of boats
	try
	{
		numOfBoats = boatCheck();		//try block to set Executive constructor's numOfBoats to the value returned by boatCheck
	}
	catch(std::runtime_error &rte)	//catch error if the function fails
	{
		std::cout << "Invalid number of ships";		//print error message if the function fails
	}

			std::cout<<"Please Choose Game Mode:\n" << "1.) Single Player vs AI\n2.) 2-Player\n>> ";
			std::cin >> menuChoice;
			cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << endl;
			cout << "Please enter a 1 or 2" << endl;
			if(menuChoice == 2)
			{
				start = true;
			}
			else if(menuChoice == 1)
			{
				start =  true;
				std::cout <<"Now choose difficulty(1-3): ";
				std::cin >> ai_Difficulty;
				while(ai_Difficulty != 1 && ai_Difficulty != 2 && ai_Difficulty != 3)
				{
					std::cin.clear();
					std::cin.ignore(1);
					std::cout <<"Now choose difficulty(1-3): ";
					std::cin >> ai_Difficulty;
				}
			}
			else
			{
				while(menuChoice != 1 && menuChoice != 2)
				{
				std::cin.clear();
				std::cin.ignore(1);
				std::cout<<"Please Choose Game Mode:\n" << "1.) Single Player vs AI\n2.) 2-Player\n>> ";
				std::cin >> menuChoice;
				}
			}


	if(menuChoice == 2)
	{
	player_1 = new Player(numOfBoats); 		//create player 1 object passing in the number of boats
	player_2 = new Player(numOfBoats);		//create player 2 object passing in the number of boats
	m_gameOver = false;			//m_gameOver member variable set to false at the beginning of the game
	m_player_1Turn = 1;			//m_player_1Turn member boolean set to 1, game starts with player 1's turn

	std::cout <<"\nPlayer 1 place your ships\n";		//prompt player1 to place their ships
	player_1 -> getBoard() -> setupBoard();
	std::cout << "Press Enter to go to the next Player's turn: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); //basically lets the user type in anything, ignoring their input
	std::cout <<"\nPlayer 2 place your ships\n";		//promt player2 to place their ships
	//std::cout << "Press Enter to go to the next Player's turn: ";
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	player_2 -> getBoard() -> setupBoard();					//call getBoard and setupBoard from board.cpp to create the two boards for player2
	game();		//call Executive game function to start the game once both players have set up their boards
}
else if(menuChoice == 1)
{
	m_gameOver = false;
	m_player_1Turn = 1;
	player_1 = new Player(numOfBoats); 		//create player
	player_2 = new Player(numOfBoats);
	std::cout <<"\nPlayer 1 place your ships\n";
	player_1 -> getBoard() -> setupBoard(); //setup only player
	////////////Start AI game/////////////////////////
	if(ai_Difficulty == 1)
	{
		cout << "Setting up easy AI..." << endl;
		player_2 -> getBoard() -> setupBoard_AI();
		AIgame();
	}
	else if(ai_Difficulty == 2)
	{
		cout << "Setting up normal AI..." << endl;
		player_2 -> getBoard() -> setupBoard_AI();
		AIgame();
   //normal difficulty
	}
	else if(ai_Difficulty == 3)
	{
		cout << "Setting up hard AI..." << endl;
		player_2 -> getBoard() -> setupBoard_AI();
		AIgame();
		//hard difficulty
	}
	else
	{
		//error catching somehow
	}
}
player_1->getBoard()->setShipsLeft(numOfBoats, false);
player_2->getBoard()->setShipsLeft(numOfBoats, false);

}

Executive::~Executive()		//Executive destructor
{
	delete player_1;		//delete player1 object
	delete player_2;		//delete player2 object
}

void Executive::game()
{
	std::string guess = " ";

	while(!m_gameOver)
	{
		try
		{
			guess = " ";			//reinitializes guess to prevent infinite out of boundary loop

			while(guess.length() != 2)
			{
				if(m_player_1Turn % 2 == 1)	//if it is player 1's turn
				{
					player_1->getBoard()->printShotBoard();
					player_1->getBoard()->printMyBoard();
					std::cout << "Player 1: Where would you like to shoot: "; //print player's board and opponent's board and ask for user a location to shoot

					std::getline(std::cin, guess);

					std::transform(guess.begin(), guess.end(),guess.begin(), ::toupper);	//converts guess to uppercase

				//	std::cout << "guess: " << guess << "\n"; //print out user's guess

					if(guess.length() != 2)
					{
						std::cout << "Invalid coordinate! Try again.\n"; //error if user inputs a string which length is not 2
					}
				}
				else	//if it is player 2's turn
				{
					player_2->getBoard()->printShotBoard();
					player_2->getBoard()->printMyBoard();
					std::cout <<"Player 2: Where would you like to shoot: "; //print player's board and opponent's board and ask for user a location to shoot

					std::getline(std::cin, guess);

					std::transform(guess.begin(), guess.end(),guess.begin(), ::toupper);	//converts guess to uppercase


					if(guess.length() != 2)
					{
						std::cout << "Invalid coordinate! Try again.\n";//error if user inputs a string which length is not 2
					}

				}
			}

			shoot(guess); //shoot the location as user demand
			//printIntermission();
			if(m_player_1Turn % 2 == 1 && !m_gameOver) //if it is player 1's turn
			{

				std::cout << "PLAYER 1 TURN\n";
				player_1->getBoard()->printShotBoard();
				player_1->getBoard()->printMyBoard();

				std::cout <<"Player 1 please hit enter and let other player shoot at your ships in secret: "; //print the board for checking hit or not and hit eneter for next player's turn
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); //get rid of user's ramdon input to crash the game
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
				printIntermission();
				cout<<"\n\n\n\n\n\n\n\n";
			}
			else if(m_player_1Turn % 2 == 0 && !m_gameOver)	//if it is player 2's turn
			{
				std::cout << "PLAYER 2 TURN\n";
				player_2->getBoard()->printShotBoard();
				player_2->getBoard()->printMyBoard();

				std::cout <<"Player 2 please hit enter and let other player shoot at your ships in secret: ";//print the board for checking hit or not and hit eneter for next player's turn
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); //get rid of user's ramdon input to crash the game
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
				printIntermission();
				cout<<"\n\n\n\n\n\n\n\n";
			}

			m_player_1Turn++; //change player turn
		}
		catch(std::runtime_error &rte)
		{
			std::cout << rte.what();
		}
	}

	if(m_player_1Turn % 2 == 1) //m_player_1Turn gets changed right before this, which is why the value is comparing different than above
	{
		player_2->getBoard()->printShotBoard();
		player_2->getBoard()->printMyBoard();

		printWinnerP2();
		std::cout << "Player 2 sunk "<<player_1->getBoard()->getNumberofShips()<<" ship(s)\n";
		std::cout << "Player 1 sunk "<<(player_2->getBoard()->getNumberofShips())-(player_2->getBoard()->getShipsLeft())<<" ship(s)\n";
	}
	else
	{
		player_1->getBoard()->printShotBoard();
		player_1->getBoard()->printMyBoard();

		printWinnerP1();
		std::cout << "Player 2 sunk "<<(player_1->getBoard()->getNumberofShips())-(player_1->getBoard()->getShipsLeft())<<" ship(s)\n";
		std::cout << "Player 1 sunk "<<player_2->getBoard()->getNumberofShips()<<" ship(s)\n";
	}

}

////////////////###########################################################################
////////////////####################NEW_CODE###############################################
////////////////###########################################################################
void Executive::printIntermission()	//prints the intermission screen so player's can swap turns
{
	//for(int i=0;i<40;i++)
	//{
		std::cout << "\n\n\n\n\n\n";	//prints a lot of newlines to add blank space so that player's can swap turns without seeing each other's boards
	//}
	std::cout << "When ready, please press Enter: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');	//takes in input of the user, basically ignoring any input so that the user can type anything
}

void Executive::AIgame() //Zack: I just copy and pasted the orignal game code and am adding changes for AI turns
{
	std::string guess = " ";

	while(!m_gameOver)
	{
		try
		{
			guess = " ";			//reinitializes guess to prevent infinite out of boundary loop

			while(guess.length() != 2)
			{
				if(m_player_1Turn % 2 == 1)	//if it is player 1's turn
				{
					player_1->getBoard()->printShotBoard();
					player_1->getBoard()->printMyBoard();
					std::cout << "Player 1: Where would you like to shoot: "; //print player's board and opponent's board and ask for user a location to shoot

					std::getline(std::cin, guess);

					std::transform(guess.begin(), guess.end(),guess.begin(), ::toupper);	//converts guess to uppercase

				//	std::cout << "guess: " << guess << "\n"; //print out user's guess

					if(guess.length() != 2)
					{
						std::cout << "Invalid coordinate! Try again.\n"; //error if user inputs a string which length is not 2
					}

				}
				else	//if it is AI turn
				{
					cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
					std::cout <<"Allowing for AI shot "; //print player's board and opponent's board

					if(ai_Difficulty == 1) //Randomly generates positions for easy AI
						{
							guess = player_2->getBoard()->randPosGen();
							cout << "AI SHOT: " << guess << endl;
						}
					if(ai_Difficulty == 2) //Normal AI shot mechanics go here
						{

						std::string prevGuess = player_2->getRecentGuess();
						if(prevGuess == "")//if first guess
						{
							lastHit = "";
							guess = player_2->getBoard()->randPosGen();//guess random spot
						}else if(player_1->getBoard()->isHitPos(prevGuess.at(1)-49,(int)prevGuess.at(0)-65)||lastHit!="")//if previous guess was a hits or last ship hit is not sunk
						{
							if(player_1->getBoard()->isHitPos(prevGuess.at(1)-49,(int)prevGuess.at(0)-65))
							{
								lastHit = prevGuess;
							}
							int lastShipHit = player_1->getBoard()->getShipIndex(lastHit);
							if(player_1->getBoard()->getShip()[lastShipHit].isSunk())// to see if the ship being tracked is sunk
							{
								lastHit = "";
								shipDir = ' ';
								int numShips = player_1->getBoard()->getNumberofShips();
								for(int i = 0; i < numShips; i++)//checks every ship to see if damaged but not sunk
								{
									if(player_1->getBoard()->getShip()[i].getDamage()>=1 && !(player_1->getBoard()->getShip()[i].isSunk()))//if has damage and not sunk
									{
										lastHit = player_1->getBoard()->getShip()[i].getCoordinate(i);//set lastHit to damaged ship
									}
								}
							}
							guess = mediumAiShot(player_1->getBoard(), prevGuess, lastShipHit);
							std::string prevGuess = player_2->getRecentGuess();
						}else
						{
							guess = player_2->getBoard()->randPosGen();
						}
						player_2->setRecentGuess(guess);






						}
					if(ai_Difficulty == 3) // Hard AI shot mechanics go here
						{
							cout<< "\nAI SHOT: " << hardAiShot(player_1->getBoard());
								guess = hardAiShot(player_1->getBoard());
						}
					}
				}

					std::transform(guess.begin(), guess.end(),guess.begin(), ::toupper);	//converts guess to uppercase

					if(guess.length() != 2)
					{
						std::cout << "Invalid coordinate! Try again.\n";//error if user inputs a string which length is not 2
					}




			shoot(guess); //shoot the location as user demand

			if(m_player_1Turn % 2 == 1 && !m_gameOver) //if it is player 1's turn
			{

				//std::cout << "PLAYER 1 TURN\n";
				player_1->getBoard()->printShotBoard();
				player_1->getBoard()->printMyBoard();
			}
			m_player_1Turn++; //change player turn
		}
		catch(std::runtime_error &rte)
		{
			std::cout << rte.what();
		}
	}

	if(m_player_1Turn % 2 == 1) //m_player_1Turn gets changed right before this, which is why the value is comparing different than above
	{
		player_2->getBoard()->printShotBoard();
		player_2->getBoard()->printMyBoard();
		std::cout << "The AI won!\n";
		std::cout << "AI sunk "<<player_1->getBoard()->getNumberofShips()<<" ship(s)\n";
		std::cout << "Player 1 sunk "<<(player_2->getBoard()->getNumberofShips())-(player_2->getBoard()->getShipsLeft())<<" ship(s)\n";
	}
	else
	{
		player_1->getBoard()->printShotBoard();
		player_1->getBoard()->printMyBoard();

		std::cout << "PLAYER 1 WINS!\n";
		std::cout << "Player 2 sunk "<<(player_1->getBoard()->getNumberofShips())-(player_1->getBoard()->getShipsLeft())<<" ship(s)\n";
		std::cout << "Player 1 sunk "<<player_2->getBoard()->getNumberofShips()<<" ship(s)\n";
	}

}
std::string Executive::mediumAiShot(Board* playerBoard, std::string prevShot, int shipIndex)
{
	std::string guess = "";
	if(lastHit == "")//guess randomly if havent hit anything
	{
		return(player_2->getBoard()->randPosGen());
	}
	int row = (int)lastHit.at(1);
	int col = (int)lastHit.at(0);
	if(shipDir == 'h') //if direction is horizontal
	{

		col = col + 1;
		guess = (char)col;
		guess += (char)row;
		if(player_1->getBoard()->withinBoundary(guess))//guess within boundary
		{
			if(player_1->getBoard()->getElement(row-49,col-65)=="\033[1;36m~\033[0m")//if spot on board is blue tilde
			{
				return(guess);
			}else if(player_1->getBoard()->getElement(row-49,col-65)!="\033[1;36m~\033[0m"||!(player_1->getBoard()->withinBoundary(guess)))//if spot on board is not blue tilde or not within boundary
			{
				int numShips = player_1->getBoard()->getNumberofShips() - 1;
				col = col + (rand() % (numShips-(-numShips)+1) + (-numShips));
				guess = (char)col;
				guess += (char)row;
				return(guess);
			}else
			{
				col = col + 2;
				guess = (char)col;
				guess += (char)row;
				return(guess);
			}
		}
	}else if(shipDir == 'v')//if direction is vertical
	{
		row = row + 1;
		guess = (char)col;
		guess += (char)row;
		if(player_1->getBoard()->withinBoundary(guess))//guess within boundary
		{
			if(player_1->getBoard()->getElement(row-49,col-65)=="\033[1;36m~\033[0m")//if spot on board is blue tilde
			{
				return(guess);
			}else if(player_1->getBoard()->getElement(row-49,col-65)!="\033[1;36m~\033[0m"||!(player_1->getBoard()->withinBoundary(guess)))//if spot on board is not blue tilde or not within boundary
			{
				int numShips = player_1->getBoard()->getNumberofShips() - 1;
				row = row + (rand() % (numShips-(-numShips)+1) + (-numShips));
				guess = (char)col;
				guess += (char)row;
				return(guess);
			}else
			{
				row = row + 2;
				guess = (char)col;
				guess += (char)row;
				return(guess);
			}
		}
	}	else//if ship has only been hit once
	{
		int randNum = (rand() % (4-1+1) + 1);
		if(randNum == 1)//guess right
		{
			col = col + 1;
			guess = (char)col;
			guess += (char)row;
			if(player_1->getBoard()->isShipPos(row-49,col-65)&&player_1->getBoard()->getShipIndex(guess)==shipIndex)//if the enemy ship is going horizontally
			{
					shipDir = 'h';
			}
			return(guess);
		}else if(randNum == 2)//guess left
		{
			col = col - 1;
			guess = (char)col;
			guess += (char)row;
			if(player_1->getBoard()->isShipPos(row-49,col-65)&&player_1->getBoard()->getShipIndex(guess)==shipIndex)//if the enemy ship is going horizontally
			{
					shipDir = 'h';
			}
			return(guess);
		}else if(randNum == 3)//guess up
		{
			row = row - 1;
			guess = (char)col;
			guess += (char)row;
			if(player_1->getBoard()->isShipPos(row-49,col-65)&&player_1->getBoard()->getShipIndex(guess)==shipIndex)//if the enemy ship is going vertically
			{
					shipDir = 'v';
			}
			return(guess);
		}else if(randNum == 4)//guess down
		{
			row = row + 1;
			guess = (char)col;
			guess += (char)row;
			if(player_1->getBoard()->isShipPos(row-49,col-65)&&player_1->getBoard()->getShipIndex(guess)==shipIndex)//if the enemy ship is going vertically
			{
					shipDir = 'v';
			}
			return(guess);
		}
	}
	return(player_2->getBoard()->randPosGen());
}

std::string Executive::hardAiShot(Board* playerBoard)
{
	std::string shot = "";
	bool foundShip = false;
	int row = 0;
	int col = 0;
	while(foundShip == false)
	{
			if(playerBoard->isShipPos(row,col))
			{
					foundShip = true;
					row += 49;
					col += 65;
					shot = (char)col;
					shot += (char)row;
					return(shot);
			}
			col++;
			if(col == 8)
			{
				row++;
				col = 0;
			}
	}
	return(shot);
}

void Executive::explosionAnimation()
{
	system("clear");




cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "          *         \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
usleep(250000);
system("clear");
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "         * *        \n";
cout << "          0         \n";
cout << "         * *        \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
usleep(250000);
system("clear");
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "        ** **       \n";
cout << "        *0 0*       \n";
cout << "          *         \n";
cout << "        *0 0*       \n";
cout << "        ** **       \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
usleep(250000);
system("clear");
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "        ** **       \n";
cout << "        *0 0*       \n";
cout << "          *         \n";
cout << "        *0 0*       \n";
cout << "        ** **       \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
usleep(250000);
system("clear");
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "       *  *  *      \n";
cout << "        00 00       \n";
cout << "        0* *0       \n";
cout << "       *     *      \n";
cout << "        0* *0       \n";
cout << "        00 00       \n";
cout << "       *  *  *      \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
usleep(250000);
system("clear");
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "       0  0  0      \n";
cout << "        ** **       \n";
cout << "        *   *       \n";
cout << "       0     0      \n";
cout << "        *   *       \n";
cout << "        ** **       \n";
cout << "       0  0  0      \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
usleep(250000);
system("clear");
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "       *  *  *      \n";
cout << "                    \n";
cout << "                    \n";
cout << "       *     *      \n";
cout << "                    \n";
cout << "                    \n";
cout << "       *  *  *      \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
usleep(250000);
system("clear");
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
cout << "                    \n";
usleep(250000);
system("clear");
cout << "                                  \n";
cout << "                                  \n";
cout << "                                  \n";
cout << "                                  \n";
cout << "                                  \n";
cout << "                                  \n";
cout << "                                  \n";
cout << " ____  ____  _____  _________  _  \n";
cout << "|_   ||   _||_   _||  _   _  || | \n";
cout << "                                  \n";
cout << "                                  \n";
cout << "                                  \n";
cout << "|____||____||_____|  |_____|  (_) \n";
cout << "                                  \n";
cout << "                                  \n";
cout << "                                  \n";
cout << "                                  \n";
cout << "                                  \n";
cout << "                                  \n";
cout << "                                  \n";
cout << "                                  \n";
usleep(250000);
system("clear");
cout << "                                  \n";
cout << "                                  \n";
cout << "                                  \n";
cout << "                                  \n";
cout << "                                  \n";
cout << "                                  \n";
cout << "                                  \n";
cout << " ____  ____  _____  _________  _  \n";
cout << "|_   ||   _||_   _||  _   _  || | \n";
cout << "  | |__| |    | |  |_/ | | \\_|| | \n";
cout << "                                  \n";
cout << " _| |  | |_  _| |_    _| |_   |_| \n";
cout << "|____||____||_____|  |_____|  (_) \n";
cout << "                                  \n";
cout << "                                  \n";
cout << "                                  \n";
cout << "                                  \n";
cout << "                                  \n";
cout << "                                  \n";
cout << "                                  \n";
cout << "                                  \n";
usleep(250000);
system("clear");
cout << "                                  \n";
cout << "                                  \n";
cout << "                                  \n";
cout << "                                  \n";
cout << "                                  \n";
cout << "                                  \n";
cout << "                                  \n";
cout << " ____  ____  _____  _________  _  \n";
cout << "|_   ||   _||_   _||  _   _  || | \n";
cout << "  | |__| |    | |  |_/ | | \\_|| | \n";
cout << "  |  __  |    | |      | |    | | \n";
cout << " _| |  | |_  _| |_    _| |_   |_| \n";
cout << "|____||____||_____|  |_____|  (_) \n";
cout << "                                  \n";
cout << "                                  \n";
cout << "                                  \n";
cout << "                                  \n";
cout << "                                  \n";
cout << "                                  \n";
cout << "                                  \n";
cout << "                                  \n";
usleep(1000000);
system("clear");
}

void Executive::printWinnerP1()
{
	cout << " ____      ____  _____  ____  _____  ____  _____  ________  _______      _______  _____          _     ____  ____  ________  _______        ___   ____  _____  ________  " << endl;
	usleep(100000);
	cout << "|_  _|    |_  _||_   _||_   \\|_   _||_   \\|_   _||_   __  ||_   __ \\    |_   __ \\|_   _|        / \\   |_  _||_  _||_   __  ||_   __ \\     .'   `.|_   \\|_   _||_   __  | " << endl;
	usleep(100000);
	cout << "  \\ \\  /\\  / /    | |    |   \\ | |    |   \\ | |    | |_ \\_|  | |__) |     | |__) | | |         / _ \\    \\ \\  / /    | |_ \\_|  | |__) |   /  .-.  \\ |   \\ | |    | |_ \\_| " << endl;
	usleep(100000);
	cout << "   \\ \\/  \\/ /     | |    | |\\ \\| |    | |\\ \\| |    |  _| _   |  __ /      |  ___/  | |   _    / ___ \\    \\ \\/ /     |  _| _   |  __ /    | |   | | | |\\ \\| |    |  _| _  " << endl;
	usleep(100000);
	cout << "    \\  /\\  /     _| |_  _| |_\\   |_  _| |_\\   |_  _| |__/ | _| |  \\ \\_   _| |_    _| |__/ | _/ /   \\ \\_  _|  |_    _| |__/ | _| |  \\ \\_  \\  `-'  /_| |_\\   |_  _| |__/ | " << endl;
	usleep(100000);
	cout << "     \\/  \\/     |_____||_____|\\____||_____|\\____||________||____| |___| |_____|  |________||____| |____||______|  |________||____| |___|  `.___.'|_____|\\____||________| " << endl;
}

void Executive::printWinnerP2()
{
	cout << " ____      ____  _____  ____  _____  ____  _____  ________  _______      _______  _____          _     ____  ____  ________  _______      _________  ____      ____   ___    " << endl;
	usleep(100000);
	cout << "|_  _|    |_  _||_   _||_   \\|_   _||_   \\|_   _||_   __  ||_   __ \\    |_   __ \\|_   _|        / \\   |_  _||_  _||_   __  ||_   __ \\    |  _   _  ||_  _|    |_  _|.'   `.  " << endl;
	usleep(100000);
	cout << "  \\ \\  /\\  / /    | |    |   \\ | |    |   \\ | |    | |_ \\_|  | |__) |     | |__) | | |         / _ \\    \\ \\  / /    | |_ \\_|  | |__) |   |_/ | | \\_|  \\ \\  /\\  / / /  .-.  \\ " << endl;
	usleep(100000);
	cout << "   \\ \\/  \\/ /     | |    | |\\ \\| |    | |\\ \\| |    |  _| _   |  __ /      |  ___/  | |   _    / ___ \\    \\ \\/ /     |  _| _   |  __ /        | |       \\ \\/  \\/ /  | |   | | " << endl;
	usleep(100000);
	cout << "    \\  /\\  /     _| |_  _| |_\\   |_  _| |_\\   |_  _| |__/ | _| |  \\ \\_   _| |_    _| |__/ | _/ /   \\ \\_  _|  |_    _| |__/ | _| |  \\ \\_     _| |_       \\  /\\  /   \\  `-'  / " << endl;
	usleep(100000);
	cout << "     \\/  \\/     |_____||_____|\\____||_____|\\____||________||____| |___| |_____|  |________||____| |____||______|  |________||____| |___|   |_____|       \\/  \\/     `.___.'  " << endl;
}


////////////////###########################################################################
////////////////####################OLD_CODE###############################################
////////////////###########################################################################
void Executive::shoot(std::string location)
{
	int numberOfShips = player_1->getBoard()->getNumberofShips(); //sets the number of ships

	bool hit = false;

	if(m_player_1Turn % 2 == 1)
	{
		hit = player_2->gettingShot(location); //check player_2 has a ship at the location or not
		player_1->shooting(location,hit); //update hit marker for player_1

		for(int i=0;i<numberOfShips;i++)	//checks for game over
		{
			if(player_2->getBoard()->getShip()[i].isSunk())
			{
				cout << "Player 2, you have " << player_2->getBoard()->getShipsLeft() << " Ships left!";
				m_gameOver = true;	//sets to true if they are sunk
			}
			else
			{
				m_gameOver = false;	//sets back to false if any are not sunk and then breaks out of for loop
				break;
			}
		}


	}
	else
	{
		hit = player_1->gettingShot(location); //check player_1 has a ship at the location or not
		player_2->shooting(location,hit); //update hit marker for player_2

		for(int i=0;i<numberOfShips;i++)	//checks for game over
		{
			if(player_1->getBoard()->getShip()[i].isSunk())
			{
				cout << "Player 1, you have " << player_1->getBoard()->getShipsLeft() << " Ships left!\n";
				m_gameOver = true;	//sets to true if they are sunk
			}
			else
			{
				m_gameOver = false; //sets back to false if any are not sunk and then breaks out of for loop
				break;
			}
		}
	}
}
