//N Queens by Hamza Patel
#pragma warning
#include <iostream>
#include <math.h>
using namespace std;

int i, j, n;
int a[20][20];
int row, col;

//function to print the board
//issues with this one
int PrintBoard()
{
	for (i = 1;i <= n;i++)
	{
		for (j = 1;j <= n;j++)
		{
			a[i][j] = '-';
		}
	}
	return 0;

}
//function that prints the array
int PrintArray()
{
	for (i = 1;i <= n;i++)
	{
		for (j = 1;j <= n;j++)
		{
			cout<< " ", a[i][j];
		}
		cout << "  ";
	}
	cout << "  ";
	return 0;
}
//function to place queen
int PlaceQueen(int row, int col)
{
	a[row][col] = 'Q';
	return 0;
}

//function that checks if Q can be placed or not
//Does not work yet
int RowChecker(int row, int col)
{
	int i, j, flag{};
	for (i = 1;i <= row;i++)
	{
		for (j = 1;j <= n;j++)
		{
			int k = abs(row - i);
			int l = abs(col - n);
			if (a[i][col] != 'Q' && a[k][l] != 'Q')
			{
				flag = 1;
			}
			else
			{
				flag = 0;
				break;
			}
		}
	}
	return flag;
}


int main(void)
{
	cout << "Enter no. of queen(s): ";
	cin >> n;

	PrintBoard();

	for (i = 1;i <= n;i++)
	{
		cout << "Where would you like to place a queen?" << endl;
		cout << "Enter Row: ";
		cin >> row;

		cout << "Enter Column: ";
		cin >> col;

		if (RowChecker(row, col) == 1)
		{
			PlaceQueen(row, col);
		}

	}
	PrintArray();


	
}
