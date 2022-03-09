// Names of Group:
// Julian Espinoza
// Wesley Goo
// Hamza Patel
// Arturo Islas Mejia
// Date: 2/16/2022

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
#include"Tic-Tac-Toe.h"
#include "TowerOfHanoi.h"
#include "n-Queens.h"
using namespace std;


int mainMenuOption();
int main()
{
    do
    {
        switch (mainMenuOption())
        {
        case 0: exit(1); break;
        case 1: ticTacToe(); break;
        case 2: towerOfHanoi(); break;
        case 3: nQueens(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    } while (true);
}

//Precondition:none
//PostCondition:displays the main menu
int mainMenuOption()
{
    cout << endl << "Chapter 1: Assignment by Julian Espinoza, Wesley Goo, Hamza Patel, Arturo Islas Mejia";
    cout << endl << "==========================================";
    cout << endl << "1. ticTacToe";
    cout << endl << "2. towerOfHanoi";
    cout << endl << "3. nQueens";
    cout << endl << "==========================================";
    cout << endl << "Exit 0";
    cout << endl << "==========================================" << endl;
    int options = inputInteger("Options: ", 0, 3);
    cout << endl << endl << endl;
    return options;
}
