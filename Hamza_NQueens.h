#pragma once
#include <iostream>
#include <stack>
#include <iomanip>
#include <iterator>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <chrono>
#include "input.h"
using namespace std;





//Precondition: takes input user from board size
//Postcondition: displays board size based upon user input
void displayBoard(string** nQueens, int sizeOfBoard)
{
    for (int i = 0; i < sizeOfBoard; i++) {
        for (int j = 0; j < sizeOfBoard; j++) {
            if (j == 0)
                cout << "|";
            cout << nQueens[i][j]
                << "|";
            if (j == sizeOfBoard - 1)
                cout << endl;
        }
        for (int i = 0; i < sizeOfBoard; i++)
        {
            if (i == 0)
                cout << "-";
            cout << "--";
            if (i == sizeOfBoard - 1)
                cout << endl;
        }
    }
}

//Precondition: asks user to placea queen in row and column
//Postcondition: places queen in desired row and column
void addQueen(string**& nQueens, int sizeOfBoard)
{
    int row = inputInteger("Enter the row you want to put a queen: ", 1, sizeOfBoard) - 1;
    int coloum = inputInteger("Enter the column you want to put a queen: ", 1, sizeOfBoard) - 1;

    //Validates if queen has already been placed there
    for (int i = 0; i < sizeOfBoard; i++)
        if (nQueens[row][coloum] == "*")
        {
            cout << "Invalid. A queen is already placed here. Try Again." << endl;
            return;
        }


    nQueens[row][coloum] = "Q";

    

    for (int i = 0; i < sizeOfBoard; i++)
    {

        if (coloum != i)
            nQueens[row][i] = "*";
    }

    for (int i = 0; i < sizeOfBoard; i++)
    {
        if (row != i)
            nQueens[i][coloum] = "*";
    }



   //handles diagonal line going bottom right.
   //all diagnal lines  
    int temp1 = -1;
    for (int i = row; i < sizeOfBoard; i++)
    {
        temp1++;
        if (i >= sizeOfBoard)
            break;
        for (int j = coloum; j < sizeOfBoard; j++) {

            if (j >= sizeOfBoard)
                break;
            if (i == row + temp1 && j == coloum + temp1)
            {
                if (row != i && coloum != j)
                    nQueens[i][j] = "*";
            }

        }
    }

    temp1 = -1;
    for (int i = row; i > -1; i--)
    {
        temp1++;
        if (i <= -1)
            break;
        for (int j = coloum; j > -1; j--) {

            if (j <= -1)
                break;
            if (i == row - temp1 && j == coloum - temp1)
            {
                if (row != i && coloum != j)
                    nQueens[i][j] = "*";
            }

        }
    }

    temp1 = -1;
    for (int i = row; i < sizeOfBoard; i++)
    {
        temp1++;
        if (i >= sizeOfBoard)
            break;
        for (int j = coloum; j > -1; j--) {

            if (j <= -1)
                break;
            if (i == row + temp1 && j == coloum - temp1)
            {
                if (row != i && coloum != j)
                    nQueens[i][j] = "*";
            }

        }
    }

    temp1 = -1;
    for (int i = row; i > -1; i--)
    {
        temp1++;
        if (i <= -1)
            break;
        for (int j = coloum; j < sizeOfBoard; j++) {

            if (j >= sizeOfBoard)
                break;
            if (i == row - temp1 && j == coloum + temp1)
            {
                if (row != i && coloum != j)
                    nQueens[i][j] = "*";
            }

        }
    }

 
    displayBoard(nQueens, sizeOfBoard);
    
}





//Precondition: asks user which row and column the program should delete a queen
//Postcondition: deletes queen from selected row and column
void removeQueen(string**& nQueens, int sizeOfBoard)
{
    int row = inputInteger("Enter the row you want to delete a queen: ", 1, sizeOfBoard) - 1;
    int coloum = inputInteger("Enter the coloum you want to delete a queen: ", 1, sizeOfBoard) - 1;
    nQueens[row][coloum] = " ";


    for (int i = 0; i < sizeOfBoard; i++)
    {

        if (coloum != i)
            nQueens[row][i] = " ";
    }

    for (int i = 0; i < sizeOfBoard; i++)
    {
        if (row != i)
            nQueens[i][coloum] = " ";
    }
  



    int temp1 = -1;
    for (int i = row; i < sizeOfBoard; i++)
    {
        temp1++;
        if (i >= sizeOfBoard)
            break;
        for (int j = coloum; j < sizeOfBoard; j++) {

            if (j >= sizeOfBoard)
                break;
            if (i == row + temp1 && j == coloum + temp1)
            {
                if (row != i && coloum != j)
                    nQueens[i][j] = " ";
            }


        }

    }




    displayBoard(nQueens, sizeOfBoard);
}






//Precondition: When user defines a board, the New/Remove queen menu opens
//Postcondition: user inout to add a queen, or delete a queen
int nQueenMenu()
{
    cout << endl << "N Queen Program";
    cout << endl << "-------------------------------------------";
    cout << endl << "0. Exit";
    cout << endl << "1. Place a new Queen";
    cout << endl << "2. Remove Queen";
    cout << endl << "-------------------------------------------" << endl;
    int options = inputInteger("Options: ", 0, 2);
    cout << endl << endl << endl;
    return options;
}
//Precondition: user input n-queen game
//Postcondition: opens up NQueens Game
void nQueensGame()
{
    int sizeOfBoard = inputInteger("Enter the size of the board you want to play on: ", 1, 10);

    string** nQueens = new string * [sizeOfBoard];

    //creates the array and fills the array with blank spaces
    for (int i = 0; i < sizeOfBoard; i++) {

        // Declare a memory block
        // of size sizeOfBoard
        nQueens[i] = new string[sizeOfBoard];
    }

    // Traverse the 2D array
    for (int i = 0; i < sizeOfBoard; i++) {
        for (int j = 0; j < sizeOfBoard; j++) {

            // Assign values to the
            // memory blocks created
            nQueens[i][j] = " ";
        }
    }

    do
    {
        switch (nQueenMenu())
        {
        case 0: exit(1); break;
        case 1: addQueen(nQueens, sizeOfBoard); break;
        case 2: removeQueen(nQueens, sizeOfBoard); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    } while (true);

    //Delete the array created
    for (int i = 0; i < sizeOfBoard; i++)    //To delete the inner arrays
        delete[] nQueens[i];
    delete[] nQueens;
}
