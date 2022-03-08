#pragma once
void displayBoard(string**nQueens, int sizeOfBoard)
{
    // displays the bored
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

void addQueen(string **&nQueens, int sizeOfBoard)
{
    int row = inputInteger("enter the row you want to put a queen: ", 1, sizeOfBoard) - 1;
    int coloum = inputInteger("enter the coloum you want to put a queen: ", 1, sizeOfBoard) - 1;

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
            if(i == row +temp1 && j == coloum + temp1)
            {
                if (row != i && coloum != j)
                    nQueens[i][j] = "*";
            }

        }
    }

    displayBoard(nQueens, sizeOfBoard);
    //not working 
    //cout << endl;
    //for (int i = row; i >= 0; i--) {
    //    if (i <= 0)
    //        break;
    //    for (int j = coloum; j >= 0; j--) {
    //        if (j <= 0)
    //            break;
    //        // Assign values to the
    //        if (row != i && coloum != j )
    //            nQueens[i][j] = "*";
    //    }
    //}


    //displayBoard(nQueens, sizeOfBoard);
}

void removeQueen(string **&nQueens, int sizeOfBoard)
{
    int row = inputInteger("enter the row you want to put a queen: ", 1, sizeOfBoard) - 1;
    int coloum = inputInteger("enter the coloum you want to put a queen: ", 1, sizeOfBoard) - 1;
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

    displayBoard(nQueens, sizeOfBoard);
}

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

void nQueensGame()
{
    int sizeOfBoard = inputInteger("Enter the size of the bored you want to play on: ", 1, 10);

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
