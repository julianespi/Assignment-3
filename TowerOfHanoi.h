#pragma once

bool checkIfComplete(stack<int> pegC,int numberOfdisk)
{
	bool isComplete = false;

	stack<int> winningStack;
	stack<int> temp = pegC;

	for (int i = numberOfdisk; i > 0; i--)
	{
		winningStack.push(i);
	}
	int stackSize = winningStack.size();
	if (temp.size() == winningStack.size())
	{
		for (int i = 0; i < stackSize; i++)
		{
			if (temp.top() == winningStack.top())
			{
				
				temp.pop();
				winningStack.pop();
				isComplete = true;
			}
			else
			{
				isComplete = false;
				break;
			}
		}
	}
	return isComplete;
}

void DisplayTowers(stack<int> pegA, stack<int> pegB, stack<int> pegC)
{
	stack<int> temp;


	temp = pegA;
	cout << "tower 1: ";
	for (int i = 0; i < pegA.size(); i++)
	{
		cout << temp.top() << " ";
		temp.pop();
	}
	cout << endl;

	temp = pegB;
	cout << "tower 2: ";
	for (int i = 0; i < pegB.size(); i++)
	{
		cout << temp.top() << " ";
		temp.pop();
	}
	cout << endl;

	temp = pegC;
	cout << "tower 3: ";
	for (int i = 0; i < pegC.size(); i++)
	{
		cout << temp.top() << " ";
		temp.pop();
	}
	cout << endl;
}

void resetTowerOfHanoi(stack<int> &pegA, stack<int> &pegC, int &numberOfdisk)
{
	int size = pegC.size();
	for (int i = 0; i < size; i++)
		pegC.pop();

	numberOfdisk = inputInteger("Enter the number of disk you want to play with: ", true);

	for (int i = numberOfdisk; i > 0; i--)
	{
		pegA.push(i);
	}

}

void towerOfHanoi()
{
	stack<int> pegA;
	stack<int> pegB;
	stack<int> pegC;
	int numberOfMoves = 0;
	
	char doAgain;

	int numberOfdisk = inputInteger("Enter the number of disk you want to play with: ", true);

	for(int i = numberOfdisk; i > 0; i--)
	{
		pegA.push(i);
	}
	auto start = chrono::steady_clock::now();

	do
	{
		
		DisplayTowers(pegA, pegB, pegC);

		int option1 = inputInteger("Enter the peg you want to move a disk from(1 = A, 2 = B, 3 = C, 4 to Quit): ", 1, 4);
		if (option1 == 4)
		{
			return;
		}
		int option2 = inputInteger("Enter the peg you want to move a disk to(1 = A, 2 = B, 3 = C, 4 to Quit): ", 1, 4);
		if (option2 == 4)
		{
			return;
		}

		else if (option1 == 1 && option2 == 1)
		{
			if (pegA.size() == 0)
			{
				cout << "Pillar is empyt..." << endl;
			}
			else if (pegA.size() == 0 || pegA.top() > pegA.top())
			{
				pegA.push(pegA.top());
				pegA.pop();
			}


		}
		else if (option1 == 1 && option2 == 2)
		{
			if (pegA.size() == 0)
			{
				cout << "Pillar is empyt..." << endl;
			}
			else if (pegB.size() == 0 || pegB.top() > pegA.top())
			{
				pegB.push(pegA.top());
				pegA.pop();
			}

		}
		else if (option1 == 1 && option2 == 3)
		{
			if (pegA.size() == 0)
			{
				cout << "Pillar is empyt..." << endl;
			}
			else if (pegC.size() == 0 || pegC.top() > pegA.top())
			{
				pegC.push(pegA.top());
				pegA.pop();
			}

		}
		else if (option1 == 2 && option2 == 1)
		{
			if (pegB.size() == 0)
			{
				cout << "Pillar is empyt..." << endl;
			}
			else if (pegA.size() == 0 || pegA.top() > pegB.top())
			{
				pegA.push(pegB.top());
				pegB.pop();
			}

		}
		else if (option1 == 2 && option2 == 2)
		{
			if (pegB.size() == 0)
			{
				cout << "Pillar is empyt..." << endl;
			}
			else if (pegB.size() == 0 || pegB.top() > pegB.top())
			{
				pegB.push(pegB.top());
				pegB.pop();
			}

		}
		else if (option1 == 2 && option2 == 3)
		{
			if (pegB.size() == 0)
			{
				cout << "Pillar is empyt..." << endl;
			}
			else if (pegC.size() == 0 || pegC.top() > pegB.top())
			{
				pegC.push(pegB.top());
				pegB.pop();
			}

		}
		else if (option1 == 3 && option2 == 1)
		{
			if (pegC.size() == 0)
			{
				cout << "Pillar is empyt..." << endl;
			}
			else if (pegA.size() == 0 || pegA.top() > pegC.top())
			{
				pegA.push(pegC.top());
				pegC.pop();
			}

		}
		else if (option1 == 3 && option2 == 2)
		{
			if (pegC.size() == 0)
			{
				cout << "Pillar is empyt..." << endl;
			}
			else if (pegB.size() == 0 || pegB.top() > pegC.top())
			{
				pegB.push(pegC.top());
				pegC.pop();
			}

		}
		else if (option1 == 3 && option2 == 3)
		{
			if (pegC.size() == 0)
			{
				cout << "Pillars are empyt..." << endl;
			}
			else if (pegC.size() == 0 || pegC.top() > pegC.top())
			{
				pegC.push(pegC.top());
				pegC.pop();
			}

		}

		numberOfMoves++;

		if (checkIfComplete(pegC,numberOfdisk))
		{
			cout << endl << endl;
			cout << " YOU WON!!!" << endl;
			cout << "Number of Moves taken: " << numberOfMoves << endl;
			auto end = chrono::steady_clock::now();
			double elpasedTime = double(chrono::duration_cast<chrono::seconds> (end - start).count());
			cout << "Time taken: " << elpasedTime << endl;
			cout << endl << endl;

			doAgain = inputStatus("do you want to try again (y = yes and n = no):", 'Y', 'N');
			if (doAgain == 'Y')
			{
				resetTowerOfHanoi(pegA, pegC, numberOfdisk);
				start = chrono::steady_clock::now();
			}
			else break;
		}
		cout << endl;
	} while (true);
}
