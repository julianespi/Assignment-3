#include "TTT_Wesley.h"
using namespace std;

//PreCondition: startRange (integer) and endRange (integer)
//PostCondition: returns an integer value within range (startRannge and endRange)
int TTT_W::inputInteger(string prompt, int startRange, int endRange)
{
    int input;
    do
    {
        cout << prompt;
        if (!(cin >> input))
        {
            cout << "ERROR: Invalid input. Must be an integer type.\n";
            cin.clear();
            cin.ignore(999, '\n');
        }
        else if (!(input >= min(startRange, endRange) && input <= max(startRange, endRange)))
            cout << "ERROR: Invalid input. Must be from " << startRange << ".." << endRange << ".\n";
        else
            break;
    } while (true);
    cin.clear();
    cin.ignore(999, '\n');
    return input;
}
//precondition: user input for ft
//postcondition: firstTurn is set
void TTT_W::setFTurn(char ft)
{
    firstTurn = ft;
}
//precondition: firstTurn is set
//postcondition: get firstTurn
char TTT_W::getFTurn()
{
    return firstTurn;
}
void TTT_W::GameTTT()
{
    //precondition: firstTurn is set;
    //postcondition: determines starting player
    if (firstTurn == 'N')
    {
        cout << "Computer will take the first move." << endl;
        Sleep(500); 	// delay for 500 milliseconds
        cout << "Computer's symbols will be an O." << endl;
        Sleep(500); 	// delay for 500 milliseconds
        cout << "Player's symbols will be an X." << endl << endl;
        Sleep(500); 	// delay for 500 milliseconds
        turnCurrent = 2; //redundancy
        playerNow = false;
        Sleep(500); 	// delay for 500 milliseconds
    }
    //precondition: firstTurn is set
    //postcondition: determines starting player
    if (firstTurn == 'Y')
    {
        cout << "Player will take the first move." << endl;
        Sleep(500); 	// delay for 500 milliseconds
        cout << "Computer's symbols will be an O." << endl;
        Sleep(500); 	// delay for 500 milliseconds
        cout << "Player's symbols will be an X." << endl << endl;
        Sleep(500); 	// delay for 500 milliseconds
        turnCurrent = 1;
        playerNow = true;
        Sleep(500); 	// delay for 500 milliseconds
    }
    //precondition: firstTurn is set
    //postcondition: input validation
    if ((firstTurn != 'N') && (firstTurn != 'Y')) {
        cout << "Player has not given a valid answer";
    }
    //precondition: firstTurn = 'y' || 'n', winCondition == false
    //postcondition: game of Tic-Tac-Toe plays till winner
    while (winCondition == false)
    {
        //precondition: turnCurrent = 2
        //postcondition: computer takes a turn
        if (turnCurrent == 2) {
            cout << "Computer's Turn." << endl;
            turnSquare = rand() % 9 + 1;
            //precondition: turnSquare = 1
            //postcondition: coordinates on board are set
            if (turnSquare == 1)
            {
                x = 0;
                y = 0;
            }
            //precondition: turnSquare = 2
            //postcondition: coordinates on board are set
            if (turnSquare == 2)
            {
                x = 0;
                y = 1;
            }
            //precondition: turnSquare = 3
            //postcondition: coordinates on board are set
            if (turnSquare == 3)
            {
                x = 0;
                y = 2;
            }
            //precondition: turnSquare = 4
            //postcondition: coordinates on board are set
            if (turnSquare == 4)
            {
                x = 1;
                y = 0;
            }
            //precondition: turnSquare = 5
            //postcondition: coordinates on board are set
            if (turnSquare == 5)
            {
                x = 1;
                y = 1;
            }
            //precondition: turnSquare = 6
            //postcondition: coordinates on board are set
            if (turnSquare == 6)
            {
                x = 1;
                y = 2;
            }
            //precondition: turnSquare = 7
            //postcondition: coordinates on board are set
            if (turnSquare == 7)
            {
                x = 2;
                y = 0;
            }
            //precondition: turnSquare = 8
            //postcondition: coordinates on board are set
            if (turnSquare == 8)
            {
                x = 2;
                y = 1;
            }
            //precondition: turnSquare = 9
            //postcondition: coordinates on board are set
            if (turnSquare == 9)
            {
                x = 2;
                y = 2;
            }
            //precondition: selected square in board is filled
            //postcondition: reassigns selected square by computer
            while (ticBoard[x][y] >= 1)
            {
                x = 3;
                y = 3;
                turnSquare = rand() % 9 + 1;
                //precondition: turnSquare = 1
                //postcondition: coordinates on board are set
                if (turnSquare == 1)
                {
                    x = 0;
                    y = 0;
                }
                //precondition: turnSquare = 2
                //postcondition: coordinates on board are set
                if (turnSquare == 2)
                {
                    x = 0;
                    y = 1;
                }
                //precondition: turnSquare = 3
                //postcondition: coordinates on board are set
                if (turnSquare == 3)
                {
                    x = 0;
                    y = 2;
                }
                //precondition: turnSquare = 4
                //postcondition: coordinates on board are set
                if (turnSquare == 4)
                {
                    x = 1;
                    y = 0;
                }
                //precondition: turnSquare = 5
                //postcondition: coordinates on board are set
                if (turnSquare == 5)
                {
                    x = 1;
                    y = 1;
                }
                //precondition: turnSquare = 6
                //postcondition: coordinates on board are set
                if (turnSquare == 6)
                {
                    x = 1;
                    y = 2;
                }
                //precondition: turnSquare = 7
                //postcondition: coordinates on board are set
                if (turnSquare == 7)
                {
                    x = 2;
                    y = 0;
                }
                //precondition: turnSquare = 8
                //postcondition: coordinates on board are set
                if (turnSquare == 8)
                {
                    x = 2;
                    y = 1;
                }
                //precondition: turnSquare = 9
                //postcondition: coordinates on board are set
                if (turnSquare == 9)
                {
                    x = 2;
                    y = 2;
                }
            }
            Sleep(500); 	// delay for 500 milliseconds
            //precondition: square is not filled
            //postcondition: square filled with "O"
            if ((turnSquare == upperL) && (upperLeft == false))
            {
                upperLeft = true;
                ticBoard[0][0] = 2;
            }
            //precondition: square is not filled
            //postcondition: square filled with "O"
            if ((turnSquare == upperC) && (upperCenter == false))
            {
                upperCenter = true;
                ticBoard[0][1] = 2;
            }
            //precondition: square is not filled
            //postcondition: square filled with "O"
            if ((turnSquare == upperR) && (upperRight == false))
            {
                upperRight = true;
                ticBoard[0][2] = 2;
            }
            //precondition: square is not filled
            //postcondition: square filled with "O"
            if ((turnSquare == centerL) && (centerLeft == false))
            {
                centerLeft = true;
                ticBoard[1][0] = 2;
            }
            //precondition: square is not filled
            //postcondition: square filled with "O"
            if ((turnSquare == centerC) && (centerCenter == false))
            {
                centerCenter = true;
                ticBoard[1][1] = 2;
            }
            //precondition: square is not filled
            //postcondition: square filled with "O"
            if ((turnSquare == centerR) && (centerRight == false))
            {
                centerRight = true;
                ticBoard[1][2] = 2;
            }
            //precondition: square is not filled
            //postcondition: square filled with "O"
            if ((turnSquare == bottomL) && (bottomLeft == false))
            {
                bottomLeft = true;
                ticBoard[2][0] = 2;
            }
            //precondition: square is not filled
            //postcondition: square filled with "O"
            if ((turnSquare == bottomC) && (bottomCenter == false))
            {
                bottomCenter = true;
                ticBoard[2][1] = 2;
            }
            //precondition: square is not filled
            //postcondition: square filled with "O"
            if ((turnSquare == bottomR) && (bottomRight == false))
            {
                bottomRight = true;
                ticBoard[2][2] = 2;
            }
            turnCurrent = 1;
            Sleep(1000); 	// delay for 1000 milliseconds
        }
        //precondition: turnCurrent = 1, computer has gone
        //postcondition: player's turn
        if ((turnCurrent == 1) && (playerNow == true))
        {
            cout << "Player's Turn." << endl;
            cout << "Board will be generated upon first move selection." << endl;
            //precondition: player's turn to input square coord
            //postcondition: valid coordinates set
            //cout << "Player select a number <1-9> to place your symbol in a square: " << endl;
            turnSquare=inputInteger("Player select a number <1-9> to place your symbol in a square: ", 1,9);
            cout << endl;
            //precondition: turnSquare = 1
            //postcondition: coordinates on board are set
            if (turnSquare == 1)
            {
                x = 0;
                y = 0;
            }
            //precondition: turnSquare = 2
            //postcondition: coordinates on board are set
            if (turnSquare == 2)
            {
                x = 0;
                y = 1;
            }
            //precondition: turnSquare = 3
            //postcondition: coordinates on board are set
            if (turnSquare == 3)
            {
                x = 0;
                y = 2;
            }
            //precondition: turnSquare = 4
            //postcondition: coordinates on board are set
            if (turnSquare == 4)
            {
                x = 1;
                y = 0;
            }
            //precondition: turnSquare = 5
            //postcondition: coordinates on board are set
            if (turnSquare == 5)
            {
                x = 1;
                y = 1;
            }
            //precondition: turnSquare = 6
            //postcondition: coordinates on board are set
            if (turnSquare == 6)
            {
                x = 1;
                y = 2;
            }
            //precondition: turnSquare = 7
            //postcondition: coordinates on board are set
            if (turnSquare == 7)
            {
                x = 2;
                y = 0;
            }
            //precondition: turnSquare = 8
            //postcondition: coordinates on board are set
            if (turnSquare == 8)
            {
                x = 2;
                y = 1;
            }
            //precondition: turnSquare = 9
            //postcondition: coordinates on board are set
            if (turnSquare == 9)
            {
                x = 2;
                y = 2;
            }
            //precondition: selected square in board is filled
            //postcondition: reassigns selected square by player
            while ((((turnSquare <= 0) || (turnSquare >= 10)) || (ticBoard[x][y] >= 1)))
            {
                cout << "Invalid Selection, give a valid number that has not been taken: ";
                x = 3;
                y = 3;
                //precondition: player's turn to input square coord
                //postcondition: valid coordinates set
                turnSquare = inputInteger("Player select a number <1-9> to place your symbol in a square: ", 1, 9);
                //precondition: turnSquare = 1
                //postcondition: coordinates on board are set
                if (turnSquare == 1)
                {
                    x = 0;
                    y = 0;
                }
                //precondition: turnSquare = 2
                //postcondition: coordinates on board are set
                if (turnSquare == 2)
                {
                    x = 0;
                    y = 1;
                }
                //precondition: turnSquare = 3
                //postcondition: coordinates on board are set
                if (turnSquare == 3)
                {
                    x = 0;
                    y = 2;
                }
                //precondition: turnSquare = 4
                //postcondition: coordinates on board are set
                if (turnSquare == 4)
                {
                    x = 1;
                    y = 0;
                }
                //precondition: turnSquare = 5
                //postcondition: coordinates on board are set
                if (turnSquare == 5)
                {
                    x = 1;
                    y = 1;
                }
                //precondition: turnSquare = 6
                //postcondition: coordinates on board are set
                if (turnSquare == 6)
                {
                    x = 1;
                    y = 2;
                }
                //precondition: turnSquare = 7
                //postcondition: coordinates on board are set
                if (turnSquare == 7)
                {
                    x = 2;
                    y = 0;
                }
                //precondition: turnSquare = 8
                //postcondition: coordinates on board are set
                if (turnSquare == 8)
                {
                    x = 2;
                    y = 1;
                }
                //precondition: turnSquare = 9
                //postcondition: coordinates on board are set
                if (turnSquare == 9)
                {
                    x = 2;
                    y = 2;
                }
            }
            Sleep(500); 	// delay for 500 milliseconds
            //precondition: square is not filled
            //postcondition: square filled with "X"
            if ((turnSquare == upperL) && (upperLeft == false))
            {
                upperLeft = true;
                ticBoard[0][0] = 1;
            }
            //precondition: square is not filled
            //postcondition: square filled with "X"
            if ((turnSquare == upperC) && (upperCenter == false))
            {
                upperCenter = true;
                ticBoard[0][1] = 1;
            }
            //precondition: square is not filled
            //postcondition: square filled with "X"
            if ((turnSquare == upperR) && (upperRight == false))
            {
                upperRight = true;
                ticBoard[0][2] = 1;
            }
            //precondition: square is not filled
            //postcondition: square filled with "X"
            if ((turnSquare == centerL) && (centerLeft == false))
            {
                centerLeft = true;
                ticBoard[1][0] = 1;
            }
            //precondition: square is not filled
            //postcondition: square filled with "X"
            if ((turnSquare == centerC) && (centerCenter == false))
            {
                centerCenter = true;
                ticBoard[1][1] = 1;
            }
            //precondition: square is not filled
            //postcondition: square filled with "X"
            if ((turnSquare == centerR) && (centerRight == false))
            {
                centerRight = true;
                ticBoard[1][2] = 1;
            }
            //precondition: square is not filled
            //postcondition: square filled with "X"
            if ((turnSquare == bottomL) && (bottomLeft == false))
            {
                bottomLeft = true;
                ticBoard[2][0] = 1;
            }
            //precondition: square is not filled
            //postcondition: square filled with "X"
            if ((turnSquare == bottomC) && (bottomCenter == false))
            {
                bottomCenter = true;
                ticBoard[2][1] = 1;
            }
            //precondition: square is not filled
            //postcondition: square filled with "X"
            if ((turnSquare == bottomR) && (bottomRight == false))
            {
                bottomRight = true;
                ticBoard[2][2] = 1;
            }
            turnCurrent = 2;
            playerNow = false;
            Sleep(1000); 	// delay for 1000 milliseconds
        }
        //precondition: playerNow = false
        //postcondition: player's turn
        if ((turnCurrent == 1) && (playerNow == false))
        {
            playerNow = true;
        }

        //Board Fill
        if (upperLeft == true)
        {
            if (ticBoard[0][0] == 2)
            {
                symbolInSpace = 'O';
                cout << symbolInSpace << "|";
            }
            if (ticBoard[0][0] == 1)
            {
                symbolInSpace = 'X';
                cout << symbolInSpace << "|";
            }
        }
        else
        {
            symbolInSpace = ' ';
            cout << symbolInSpace << "|";
        }
        if (upperCenter == true)
        {
            if (ticBoard[0][1] == 2) {
                symbolInSpace = 'O';
                cout << symbolInSpace << "|";
            }
            if (ticBoard[0][1] == 1) {
                symbolInSpace = 'X';
                cout << symbolInSpace << "|";
            }
        }
        else
        {
            symbolInSpace = ' ';
            cout << symbolInSpace << "|";
        }
        if (upperRight == true)
        {
            if (ticBoard[0][2] == 2)
            {
                symbolInSpace = 'O';
                cout << symbolInSpace << endl;
            }
            if (ticBoard[0][2] == 1)
            {
                symbolInSpace = 'X';
                cout << symbolInSpace << endl;
            }
        }
        else
        {
            symbolInSpace = ' ';
            cout << symbolInSpace << endl;
        }
        cout << "------" << endl;
        if (centerLeft == true)
        {
            if (ticBoard[1][0] == 2)
            {
                symbolInSpace = 'O';
                cout << symbolInSpace << "|";
            }
            if (ticBoard[1][0] == 1)
            {
                symbolInSpace = 'X';
                cout << symbolInSpace << "|";
            }
        }
        else
        {
            symbolInSpace = ' ';
            cout << symbolInSpace << "|";
        }
        if (centerCenter == true)
        {
            if (ticBoard[1][1] == 2)
            {
                symbolInSpace = 'O';
                cout << symbolInSpace << "|";
            }
            if (ticBoard[1][1] == 1)
            {
                symbolInSpace = 'X';
                cout << symbolInSpace << "|";
            }
        }
        else
        {
            symbolInSpace = ' ';
            cout << symbolInSpace << "|";
        }
        if (centerRight == true)
        {
            if (ticBoard[1][2] == 2)
            {
                symbolInSpace = 'O';
                cout << symbolInSpace << endl;
            }
            if (ticBoard[1][2] == 1)
            {
                symbolInSpace = 'X';
                cout << symbolInSpace << endl;
            }
        }
        else
        {
            symbolInSpace = ' ';
            cout << symbolInSpace << endl;
        }
        cout << "------" << endl;
        if (bottomLeft == true)
        {
            if (ticBoard[2][0] == 2)
            {
                symbolInSpace = 'O';
                cout << symbolInSpace << "|";
            }
            if (ticBoard[2][0] == 1)
            {
                symbolInSpace = 'X';
                cout << symbolInSpace << "|";
            }
        }
        else
        {
            symbolInSpace = ' ';
            cout << symbolInSpace << "|";
        }
        if (bottomCenter == true)
        {
            if (ticBoard[2][1] == 2)
            {
                symbolInSpace = 'O';
                cout << symbolInSpace << "|";
            }
            if (ticBoard[2][1] == 1)
            {
                symbolInSpace = 'X';
                cout << symbolInSpace << "|";
            }
        }
        else
        {
            symbolInSpace = ' ';
            cout << symbolInSpace << "|";
        }
        if (bottomRight == true)
        {
            if (ticBoard[2][2] == 2)
            {
                symbolInSpace = 'O';
                cout << symbolInSpace << endl << endl;
            }
            if (ticBoard[2][2] == 1)
            {
                symbolInSpace = 'X';
                cout << symbolInSpace << endl << endl;
            }
        }
        else
        {
            symbolInSpace = ' ';
            cout << symbolInSpace << endl << endl;
        }
        //Winning Rows/Columns/Diagonals
        //precondition: a three in a row is detected made of "X"
        //postcondition: player wins
        if ((ticBoard[0][0] == 1) && (ticBoard[0][1] == 1) && (ticBoard[0][2] == 1))
        {
            winCondition = true;
            cout << "Player Wins!" << endl;
        }
        //precondition: a three in a row is detected made of "X"
        //postcondition: player wins
        if ((ticBoard[1][0] == 1) && (ticBoard[1][1] == 1) && (ticBoard[1][2] == 1))
        {
            winCondition = true;
            cout << "Player Wins!" << endl;
        }
        //precondition: a three in a row is detected made of "X"
        //postcondition: player wins
        if ((ticBoard[2][0] == 1) && (ticBoard[2][1] == 1) && (ticBoard[2][2] == 1))
        {
            winCondition = true;
            cout << "Player Wins!" << endl;
        }
        //precondition: a three in a row is detected made of "X"
        //postcondition: player wins
        if ((ticBoard[0][0] == 1) && (ticBoard[1][0] == 1) && (ticBoard[2][0] == 1))
        {
            winCondition = true;
            cout << "Player Wins!" << endl;
        }
        //precondition: a three in a row is detected made of "X"
        //postcondition: player wins
        if ((ticBoard[0][1] == 1) && (ticBoard[1][1] == 1) && (ticBoard[2][1] == 1))
        {
            winCondition = true;
            cout << "Player Wins!" << endl;
        }
        //precondition: a three in a row is detected made of "X"
        //postcondition: player wins
        if ((ticBoard[0][2] == 1) && (ticBoard[1][2] == 1) && (ticBoard[2][2] == 1))
        {
            winCondition = true;
            cout << "Player Wins!" << endl;
        }
        //precondition: a three in a row is detected made of "X"
        //postcondition: player wins
        if ((ticBoard[0][0] == 1) && (ticBoard[1][1] == 1) && (ticBoard[2][2] == 1))
        {
            winCondition = true;
            cout << "Player Wins!" << endl;
        }
        //precondition: a three in a row is detected made of "X"
        //postcondition: player wins
        if ((ticBoard[2][0] == 1) && (ticBoard[1][1] == 1) && (ticBoard[0][2] == 1))
        {
            winCondition = true;
            cout << "Player Wins!" << endl;
        }
        //precondition: a three in a row is detected made of "O"
        //postcondition: computer wins
        if ((ticBoard[0][0] == 2) && (ticBoard[0][1] == 2) && (ticBoard[0][2] == 2)) {
            winCondition = true;
            cout << "Computer Wins!" << endl;
        }
        //precondition: a three in a row is detected made of "O"
        //postcondition: computer wins
        if ((ticBoard[1][0] == 2) && (ticBoard[1][1] == 2) && (ticBoard[1][2] == 2)) {
            winCondition = true;
            cout << "Computer Wins!" << endl;
        }
        //precondition: a three in a row is detected made of "O"
        //postcondition: computer wins
        if ((ticBoard[2][0] == 2) && (ticBoard[2][1] == 2) && (ticBoard[2][2] == 2)) {
            winCondition = true;
            cout << "Computer Wins!" << endl;
        }
        //precondition: a three in a row is detected made of "O"
        //postcondition: computer wins
        if ((ticBoard[0][0] == 2) && (ticBoard[1][0] == 2) && (ticBoard[2][0] == 2)) {
            winCondition = true;
            cout << "Computer Wins!" << endl;
        }
        //precondition: a three in a row is detected made of "O"
        //postcondition: computer wins
        if ((ticBoard[0][1] == 2) && (ticBoard[1][1] == 2) && (ticBoard[2][1] == 2)) {
            winCondition = true;
            cout << "Computer Wins!" << endl;
        }
        //precondition: a three in a row is detected made of "O"
        //postcondition: computer wins
        if ((ticBoard[0][2] == 2) && (ticBoard[1][2] == 2) && (ticBoard[2][2] == 2)) {
            winCondition = true;
            cout << "Computer Wins!" << endl;
        }
        //precondition: a three in a row is detected made of "O"
        //postcondition: computer wins
        if ((ticBoard[0][0] == 2) && (ticBoard[1][1] == 2) && (ticBoard[2][2] == 2)) {
            winCondition = true;
            cout << "Computer Wins!" << endl;
        }
        //precondition: a three in a row is detected made of "O"
        //postcondition: computer wins
        if ((ticBoard[2][0] == 2) && (ticBoard[1][1] == 2) && (ticBoard[0][2] == 2)) {
            winCondition = true;
            cout << "Computer Wins!" << endl;
        }
        //precondition: no three in a row is detected made of "O" or "X" in fully filled board
        //postcondition: tie game
        if (winCondition == false)
        {
            if ((ticBoard[0][0] != 0) && (ticBoard[0][1] != 0) && (ticBoard[0][2] != 0) && (ticBoard[1][0] != 0) && (ticBoard[1][1] != 0) && (ticBoard[1][2] != 0) && (ticBoard[2][0] != 0) && (ticBoard[2][1] != 0) && (ticBoard[2][2] != 0)) {
                winCondition = true;
                cout << "Tie! Cat's Scratch, no one wins!";
            }
        }
    }
}
