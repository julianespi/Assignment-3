#pragma once
const int QUEENSVLAUE = 100;

//Precondition: takes input user from board size
//Postcondition: displays board size based upon user input
void displayBoard(int** nQueens, int sizeOfBoard)
{
    // displays the bored
    for (int i = 0; i < sizeOfBoard; i++) {
        for (int j = 0; j < sizeOfBoard; j++) {
            if (j == 0)
                cout << "|";
            if (nQueens[i][j] == QUEENSVLAUE)
                cout << "Q";
            else if (nQueens[i][j] > 0)
                cout << "*";
            else
                cout << " ";
            cout << "|";
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
//Precondition: takes input user from board size
//Postcondition: displays the values of the board
void displayBoardValues(int** nQueens, int sizeOfBoard)
{
    // displays the bored
    for (int i = 0; i < sizeOfBoard; i++) {
        for (int j = 0; j < sizeOfBoard; j++) {
            if (j == 0)
                cout << "|";

            cout << nQueens[i][j] << " ";
            cout << "|";
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
void addQueen(int**& nQueens, int sizeOfBoard, int& numberOfQueensOnBoard)
{
    int row = inputInteger("enter the row you want to put a queen: ", 1, sizeOfBoard) - 1;
    int coloum = inputInteger("enter the coloum you want to put a queen: ", 1, sizeOfBoard) - 1;

    

    displayBoardValues(nQueens, sizeOfBoard);
    cout << endl << endl;

    if (nQueens[row][coloum] == QUEENSVLAUE)
    {
        cout << "Invalid. A queen is already placed here. Try Again." << endl;
        return;
    }
    else if (nQueens[row][coloum] > 0)
    {
        cout << "Invalid. in the path of a current Queen. Try Again." << endl;
        return;
    }
    else
    {
        nQueens[row][coloum] = QUEENSVLAUE;
        numberOfQueensOnBoard++;
    }


    for (int i = 0; i < sizeOfBoard; i++)
    {

        if (coloum != i)
            nQueens[row][i] += 1;
    }

    for (int i = 0; i < sizeOfBoard; i++)
    {
        if (row != i)
            nQueens[i][coloum] += 1;
    }

    //handle diagonal line going bottom right.
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
                    nQueens[i][j] += 1;
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
                    nQueens[i][j] += 1;
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
                    nQueens[i][j] += 1;
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
                    nQueens[i][j] += 1;
            }

        }
    }

    displayBoard(nQueens, sizeOfBoard);

}

//Precondition: asks user which row and column the program should delete a queen
//Postcondition: deletes queen from selected row and column
void removeQueen(int**& nQueens, int sizeOfBoard, int& numberOfQueensOnBoard)
{
    if (numberOfQueensOnBoard == 0)
    {
        cout << "Put atleast one queen on the board before you try to remove one..." << endl;
        return;
    }


    int row = inputInteger("enter the row you want to put a queen: ", 1, sizeOfBoard) - 1;
    int coloum = inputInteger("enter the coloum you want to put a queen: ", 1, sizeOfBoard) - 1;

    if (nQueens[row][coloum] == QUEENSVLAUE)
    {
        nQueens[row][coloum] = 0;
    }
    else if (nQueens[row][coloum] > 0)
    {
        cout << "Invalid. This is a Queens path not a Queen. Try Again." << endl;
        return;
    }
    else
    {
        cout << "Invalid. This is a blank space. Try Again." << endl;
        return;
    }

    nQueens[row][coloum] = 0;
    numberOfQueensOnBoard--;

    for (int i = 0; i < sizeOfBoard; i++)
    {

        if (coloum != i)
            nQueens[row][i] -= 1;
    }

    for (int i = 0; i < sizeOfBoard; i++)
    {
        if (row != i)
            nQueens[i][coloum] -= 1;
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
                    nQueens[i][j] -= 1;
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
                    nQueens[i][j] -= 1;
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
                    nQueens[i][j] -= 1;
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
                    nQueens[i][j] -= 1;
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
    int sizeOfBoard = inputInteger("Enter the size of the bored you want to play on: ", 1, 10);
    int numberOfQueensOnBoard = 0;
    int** nQueens = new int* [sizeOfBoard];


    


    //creates the array and fills the array with blank spaces
    for (int i = 0; i < sizeOfBoard; i++) {

        // Declare a memory block
        // of size sizeOfBoard
        nQueens[i] = new int[sizeOfBoard];
    }

    // Traverse the 2D array
    for (int i = 0; i < sizeOfBoard; i++) {
        for (int j = 0; j < sizeOfBoard; j++) {

            // Assign values to the
            // memory blocks created
            nQueens[i][j] = 0;
        }
    }

    do
    {
        switch (nQueenMenu())
        {
        case 0: return; break;
        case 1: addQueen(nQueens, sizeOfBoard, numberOfQueensOnBoard); break;
        case 2: removeQueen(nQueens, sizeOfBoard, numberOfQueensOnBoard); break;
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
