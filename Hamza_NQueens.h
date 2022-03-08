//N Queens by Hamza Patel
#include <iostream>
#include <math.h>
#include "input.h"
using namespace std;




int main()
{
    
    cout << "N Queen Program\n";

    int sizeOfBoard = inputInteger("Enter the size of the board you want to play on: ", 1, 10);


    // this will be put into newQueen()
        int row = inputInteger("\nEnter the row you want to put a queen: ", 1, sizeOfBoard);
        int column = inputInteger("Enter the column you want to put a queen: ", 1, sizeOfBoard);
    

        
        /*
  newQueen();
  deleteQueen();

    
    int nQueenMenu();
  
    
        do
        {
            switch (nQueenMenu())
            {
            case 0: exit(1); break;
           // case 1: newQueen(); break;
           // case 2: deleteQueen(); break;
            default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
            }
            cout << "\n";
            system("pause");

        } while (true);
    

    //Precondition:none
    //PostCondition:displays the main menu
    int nQueenMenu();
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
    */





    {
        string** nQueens = new string * [sizeOfBoard];

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


            nQueens[row - 1][column - 1] = "Q";

    
        // Traverse the 2D array
        for (int i = 0; i < sizeOfBoard; i++) {
            for (int j = 0; j < sizeOfBoard; j++) {
                if (j == 0)
                    cout << "|";
                // Print values of the
                // memory block
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

        //Delete the array created
        for (int i = 0; i < sizeOfBoard; i++)    //To delete the inner arrays
            delete[] nQueens[i];
        delete[] nQueens;

    }
    

}
