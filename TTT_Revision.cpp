// TTT_Revision.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <iomanip>

using namespace std;

int main()
{
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
    bool winCondition = false;
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

    int turnSquare = 0;
    char symbolInSpace = ' ';

    //First Turn/Turn counter
    char firstTurn = 'n';
    int turnCurrent = 0;

    srand(time(NULL)); //random seed

    cout << "Thank you for playing Tic-Tac-Toe." << endl << endl;
    cout << "Here are the rules: " << endl;
    cout << "1. This is a single player game in which the player will take alternating turns with the computer." << endl;
    cout << "2. To win, the player or computer must match three of their own symbols in a straight line (Rows, Columns, Diagonals)." << endl;
    cout << "3. For the player to conduct their turn, they will type a number between 1-9 to reflect their decision according to the diagram below: " << endl;
    cout << "1|2|3" << endl;
    cout << "-----" << endl;
    cout << "4|5|6" << endl;
    cout << "-----" << endl;
    cout << "7|8|9" << endl << endl;
    cout << "4. Good luck and have fun." << endl << endl;
    cout << "Would you like to go first? <y,n>: " << endl;
    cin >> firstTurn;
    if (firstTurn == 'n') {
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
    if (firstTurn == 'y') {
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
    if ((firstTurn != 'n') && (firstTurn != 'y')) {
        cout << "Player has not given a valid answer, please rerun the program to play." << endl;
    }
    while (winCondition == false) {
        if (turnCurrent == 2) {
            cout << "Computer's Turn." << endl;
            turnSquare = rand() % 9 + 1;
            if (turnSquare == 1) {
                x = 0;
                y = 0;
            }
            if (turnSquare == 2) {
                x = 0;
                y = 1;
            }
            if (turnSquare == 3) {
                x = 0;
                y = 2;
            }
            if (turnSquare == 4) {
                x = 1;
                y = 0;
            }
            if (turnSquare == 5) {
                x = 1;
                y = 1;
            }
            if (turnSquare == 6) {
                x = 1;
                y = 2;
            }
            if (turnSquare == 7) {
                x = 2;
                y = 0;
            }
            if (turnSquare == 8) {
                x = 2;
                y = 1;
            }
            if (turnSquare == 9) {
                x = 2;
                y = 2;
            }
            while (ticBoard[x][y] >= 1) {
                x = 3;
                y = 3;
                turnSquare = rand() % 9 + 1;
                if (turnSquare == 1) {
                    x = 0;
                    y = 0;
                }
                if (turnSquare == 2) {
                    x = 0;
                    y = 1;
                }
                if (turnSquare == 3) {
                    x = 0;
                    y = 2;
                }
                if (turnSquare == 4) {
                    x = 1;
                    y = 0;
                }
                if (turnSquare == 5) {
                    x = 1;
                    y = 1;
                }
                if (turnSquare == 6) {
                    x = 1;
                    y = 2;
                }
                if (turnSquare == 7) {
                    x = 2;
                    y = 0;
                }
                if (turnSquare == 8) {
                    x = 2;
                    y = 1;
                }
                if (turnSquare == 9) {
                    x = 2;
                    y = 2;
                }
            }
            Sleep(500); 	// delay for 500 milliseconds
            if ((turnSquare == upperL) && (upperLeft == false)) {
                upperLeft = true;
                ticBoard[0][0] = 2;
            }
            if ((turnSquare == upperC) && (upperCenter == false)) {
                upperCenter = true;
                ticBoard[0][1] = 2;
            }
            if ((turnSquare == upperR) && (upperRight == false)) {
                upperRight = true;
                ticBoard[0][2] = 2;
            }
            if ((turnSquare == centerL) && (centerLeft == false)) {
                centerLeft = true;
                ticBoard[1][0] = 2;
            }
            if ((turnSquare == centerC) && (centerCenter == false)) {
                centerCenter = true;
                ticBoard[1][1] = 2;
            }
            if ((turnSquare == centerR) && (centerRight == false)) {
                centerRight = true;
                ticBoard[1][2] = 2;
            }
            if ((turnSquare == bottomL) && (bottomLeft == false)) {
                bottomLeft = true;
                ticBoard[2][0] = 2;
            }
            if ((turnSquare == bottomC) && (bottomCenter == false)) {
                bottomCenter = true;
                ticBoard[2][1] = 2;
            }
            if ((turnSquare == bottomR) && (bottomRight == false)) {
                bottomRight = true;
                ticBoard[2][2] = 2;
            }
            turnCurrent = 1;
            Sleep(1000); 	// delay for 1000 milliseconds
        }
        if ((turnCurrent == 1) && (playerNow == true)) {
            cout << "Player's Turn." << endl;
            cout << "Board will be generated upon first move selection." << endl;
            cout << "Player select a number <1-9> to place your symbol in a square: " << endl;
            cin >> turnSquare;
            cout << endl;
            if (turnSquare == 1) {
                x = 0;
                y = 0;
            }
            if (turnSquare == 2) {
                x = 0;
                y = 1;
            }
            if (turnSquare == 3) {
                x = 0;
                y = 2;
            }
            if (turnSquare == 4) {
                x = 1;
                y = 0;
            }
            if (turnSquare == 5) {
                x = 1;
                y = 1;
            }
            if (turnSquare == 6) {
                x = 1;
                y = 2;
            }
            if (turnSquare == 7) {
                x = 2;
                y = 0;
            }
            if (turnSquare == 8) {
                x = 2;
                y = 1;
            }
            if (turnSquare == 9) {
                x = 2;
                y = 2;
            }
            while ((((turnSquare <= 0) || (turnSquare >= 10)) || (ticBoard[x][y] >= 1))) {
                cout << "Invalid Selection, give a valid number that has not been taken: ";
                x = 3;
                y = 3;
                cin >> turnSquare;
                if (turnSquare == 1) {
                    x = 0;
                    y = 0;
                }
                if (turnSquare == 2) {
                    x = 0;
                    y = 1;
                }
                if (turnSquare == 3) {
                    x = 0;
                    y = 2;
                }
                if (turnSquare == 4) {
                    x = 1;
                    y = 0;
                }
                if (turnSquare == 5) {
                    x = 1;
                    y = 1;
                }
                if (turnSquare == 6) {
                    x = 1;
                    y = 2;
                }
                if (turnSquare == 7) {
                    x = 2;
                    y = 0;
                }
                if (turnSquare == 8) {
                    x = 2;
                    y = 1;
                }
                if (turnSquare == 9) {
                    x = 2;
                    y = 2;
                }
            }
            Sleep(500); 	// delay for 500 milliseconds
            if ((turnSquare == upperL) && (upperLeft == false)) {
                upperLeft = true;
                ticBoard[0][0] = 1;
            }
            if ((turnSquare == upperC) && (upperCenter == false)) {
                upperCenter = true;
                ticBoard[0][1] = 1;
            }
            if ((turnSquare == upperR) && (upperRight == false)) {
                upperRight = true;
                ticBoard[0][2] = 1;
            }
            if ((turnSquare == centerL) && (centerLeft == false)) {
                centerLeft = true;
                ticBoard[1][0] = 1;
            }
            if ((turnSquare == centerC) && (centerCenter == false)) {
                centerCenter = true;
                ticBoard[1][1] = 1;
            }
            if ((turnSquare == centerR) && (centerRight == false)) {
                centerRight = true;
                ticBoard[1][2] = 1;
            }
            if ((turnSquare == bottomL) && (bottomLeft == false)) {
                bottomLeft = true;
                ticBoard[2][0] = 1;
            }
            if ((turnSquare == bottomC) && (bottomCenter == false)) {
                bottomCenter = true;
                ticBoard[2][1] = 1;
            }
            if ((turnSquare == bottomR) && (bottomRight == false)) {
                bottomRight = true;
                ticBoard[2][2] = 1;
            }
            turnCurrent = 2;
            playerNow = false;
            Sleep(1000); 	// delay for 1000 milliseconds
        }
        if ((turnCurrent == 1) && (playerNow == false)) {
            playerNow = true;
        }

        //Board Fill
        if (upperLeft == true) {
            if (ticBoard[0][0] == 2) {
                symbolInSpace = 'O';
                cout << symbolInSpace << "|";
            }
            if (ticBoard[0][0] == 1) {
                symbolInSpace = 'X';
                cout << symbolInSpace << "|";
            }
        }
        else {
            symbolInSpace = ' ';
            cout << symbolInSpace << "|";
        }
        if (upperCenter == true) {
            if (ticBoard[0][1] == 2) {
                symbolInSpace = 'O';
                cout << symbolInSpace << "|";
            }
            if (ticBoard[0][1] == 1) {
                symbolInSpace = 'X';
                cout << symbolInSpace << "|";
            }
        }
        else {
            symbolInSpace = ' ';
            cout << symbolInSpace << "|";
        }
        if (upperRight == true) {
            if (ticBoard[0][2] == 2) {
                symbolInSpace = 'O';
                cout << symbolInSpace << endl;
            }
            if (ticBoard[0][2] == 1) {
                symbolInSpace = 'X';
                cout << symbolInSpace << endl;
            }
        }
        else {
            symbolInSpace = ' ';
            cout << symbolInSpace << endl;
        }
        cout << "------" << endl;
        if (centerLeft == true) {
            if (ticBoard[1][0] == 2) {
                symbolInSpace = 'O';
                cout << symbolInSpace << "|";
            }
            if (ticBoard[1][0] == 1) {
                symbolInSpace = 'X';
                cout << symbolInSpace << "|";
            }
        }
        else {
            symbolInSpace = ' ';
            cout << symbolInSpace << "|";
        }
        if (centerCenter == true) {
            if (ticBoard[1][1] == 2) {
                symbolInSpace = 'O';
                cout << symbolInSpace << "|";
            }
            if (ticBoard[1][1] == 1) {
                symbolInSpace = 'X';
                cout << symbolInSpace << "|";
            }
        }
        else {
            symbolInSpace = ' ';
            cout << symbolInSpace << "|";
        }
        if (centerRight == true) {
            if (ticBoard[1][2] == 2) {
                symbolInSpace = 'O';
                cout << symbolInSpace << endl;
            }
            if (ticBoard[1][2] == 1) {
                symbolInSpace = 'X';
                cout << symbolInSpace << endl;
            }
        }
        else {
            symbolInSpace = ' ';
            cout << symbolInSpace << endl;
        }
        cout << "------" << endl;
        if (bottomLeft == true) {
            if (ticBoard[2][0] == 2) {
                symbolInSpace = 'O';
                cout << symbolInSpace << "|";
            }
            if (ticBoard[2][0] == 1) {
                symbolInSpace = 'X';
                cout << symbolInSpace << "|";
            }
        }
        else {
            symbolInSpace = ' ';
            cout << symbolInSpace << "|";
        }
        if (bottomCenter == true) {
            if (ticBoard[2][1] == 2) {
                symbolInSpace = 'O';
                cout << symbolInSpace << "|";
            }
            if (ticBoard[2][1] == 1) {
                symbolInSpace = 'X';
                cout << symbolInSpace << "|";
            }
        }
        else {
            symbolInSpace = ' ';
            cout << symbolInSpace << "|";
        }
        if (bottomRight == true) {
            if (ticBoard[2][2] == 2) {
                symbolInSpace = 'O';
                cout << symbolInSpace << endl << endl;
            }
            if (ticBoard[2][2] == 1) {
                symbolInSpace = 'X';
                cout << symbolInSpace << endl << endl;
            }
        }
        else {
            symbolInSpace = ' ';
            cout << symbolInSpace << endl << endl;
        }

        //Winning Rows/Columns/Diagonals
        if ((ticBoard[0][0] == 1) && (ticBoard[0][1] == 1) && (ticBoard[0][2] == 1)) {
            winCondition = true;
            cout << "Player Wins!" << endl;
        }
        if ((ticBoard[1][0] == 1) && (ticBoard[1][1] == 1) && (ticBoard[1][2] == 1)) {
            winCondition = true;
            cout << "Player Wins!" << endl;
        }
        if ((ticBoard[2][0] == 1) && (ticBoard[2][1] == 1) && (ticBoard[2][2] == 1)) {
            winCondition = true;
            cout << "Player Wins!" << endl;
        }
        if ((ticBoard[0][0] == 1) && (ticBoard[1][0] == 1) && (ticBoard[2][0] == 1)) {
            winCondition = true;
            cout << "Player Wins!" << endl;
        }
        if ((ticBoard[0][1] == 1) && (ticBoard[1][1] == 1) && (ticBoard[2][1] == 1)) {
            winCondition = true;
            cout << "Player Wins!" << endl;
        }
        if ((ticBoard[0][2] == 1) && (ticBoard[1][2] == 1) && (ticBoard[2][2] == 1)) {
            winCondition = true;
            cout << "Player Wins!" << endl;
        }
        if ((ticBoard[0][0] == 1) && (ticBoard[1][1] == 1) && (ticBoard[2][2] == 1)) {
            winCondition = true;
            cout << "Player Wins!" << endl;
        }
        if ((ticBoard[2][0] == 1) && (ticBoard[1][1] == 1) && (ticBoard[0][2] == 1)) {
            winCondition = true;
            cout << "Player Wins!" << endl;
        }
        if ((ticBoard[0][0] == 2) && (ticBoard[0][1] == 2) && (ticBoard[0][2] == 2)) {
            winCondition = true;
            cout << "Computer Wins!" << endl;
        }
        if ((ticBoard[1][0] == 2) && (ticBoard[1][1] == 2) && (ticBoard[1][2] == 2)) {
            winCondition = true;
            cout << "Computer Wins!" << endl;
        }
        if ((ticBoard[2][0] == 2) && (ticBoard[2][1] == 2) && (ticBoard[2][2] == 2)) {
            winCondition = true;
            cout << "Computer Wins!" << endl;
        }
        if ((ticBoard[0][0] == 2) && (ticBoard[1][0] == 2) && (ticBoard[2][0] == 2)) {
            winCondition = true;
            cout << "Computer Wins!" << endl;
        }
        if ((ticBoard[0][1] == 2) && (ticBoard[1][1] == 2) && (ticBoard[2][1] == 2)) {
            winCondition = true;
            cout << "Computer Wins!" << endl;
        }
        if ((ticBoard[0][2] == 2) && (ticBoard[1][2] == 2) && (ticBoard[2][2] == 2)) {
            winCondition = true;
            cout << "Computer Wins!" << endl;
        }
        if ((ticBoard[0][0] == 2) && (ticBoard[1][1] == 2) && (ticBoard[2][2] == 2)) {
            winCondition = true;
            cout << "Computer Wins!" << endl;
        }
        if ((ticBoard[2][0] == 2) && (ticBoard[1][1] == 2) && (ticBoard[0][2] == 2)) {
            winCondition = true;
            cout << "Computer Wins!" << endl;
        }
        if (winCondition == false) {
            if ((ticBoard[0][0] != 0) && (ticBoard[0][1] != 0) && (ticBoard[0][2] != 0) && (ticBoard[1][0] != 0) && (ticBoard[1][1] != 0) && (ticBoard[1][2] != 0) && (ticBoard[2][0] != 0) && (ticBoard[2][1] != 0) && (ticBoard[2][2] != 0)) {
                winCondition = true;
                cout << "Tie! Cat's Scratch, no one wins!";
            }
        }
    }
    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
