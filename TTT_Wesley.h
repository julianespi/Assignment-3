#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <iomanip>
using namespace std;
class TTT_W
{
private:
	//First Turn
	char firstTurn;

	//2-D Array + Board filler: 0 = blank, 1 = Player, 2 = Computer
	int ticBoard[3][4] = { {0,0,0,0}, {0,0,0,0}, {0,0,0,0} };

	//Array Selection
	int x = 0;
	int y = 0;

	//Nine Squares: Filled/Not Filled
	bool upperLeft = false;
	bool upperCenter = false;
	bool upperRight = false;
	bool centerLeft = false;
	bool centerCenter = false;
	bool centerRight = false;
	bool bottomLeft = false;
	bool bottomCenter = false;
	bool bottomRight = false;

	//game condition
	bool winCondition = false;

	//player or cpu
	bool playerNow = false;

	//Nine Squares: Selection
	int upperL = 1;
	int upperC = 2;
	int upperR = 3;
	int centerL = 4;
	int centerC = 5;
	int centerR = 6;
	int bottomL = 7;
	int bottomC = 8;
	int bottomR = 9;

	//Filler
	int turnSquare ;
	char symbolInSpace = ' ';

	//Turn counter
	int turnCurrent = 0;

	//random seed
	/*srand(time(NULL));*/

public:
	//Setter
	//precondition: user input for first player
	//postcondition: firstTurn = 'n' || firstTurn = 'y'
	void setFTurn(char ft);
	//Getter
	//precondition: firstTurn is set
	//postcondition: get firstTurn
	char getFTurn();
	//precondition: firstTurn is set
	//postcondition: runs a game of tic tac toe
	void GameTTT();
};
