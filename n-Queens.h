#pragma once
	int sizeOfBoard = inputInteger("Enter the size of the bored you want to play on: ", 1, 10);
	for (int c = 0; c < sizeOfBoard; c++)
	{
		for (int i = 0; i < sizeOfBoard; i++)
		{
			if (i == 0)
				cout << "|";
			cout << " |";
			if (i == sizeOfBoard - 1)
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
