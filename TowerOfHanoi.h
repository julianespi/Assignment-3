#pragma once
#include<stack>
using namespace std;

void moveFunction(stack<int> pegA, stack<int> pegB, stack<int> pegC)
{

	do
	{
		int option1 = inputInteger("Enter the peg you want to move a disk from(1 = A, 2 = B, 3 = C, 4 = Q): ", 1, 4);
		int option2 = inputInteger("Enter the peg you want to move a disk to(1 = A, 2 = B, 3 = C, 4 = Q): ", 1, 4);

		if (option1 == 4 || option2 == 4)
		{
			return;
		}
		else if (option1 == 1 && option2 == 1)
		{
			if (pegA.size() == 0 && pegA.size() == 0)
			{
				cout << "Pillars are empyt..." << endl;
			}
			else if (pegA.size() == 0 || pegA.top() > pegA.top())
			{
				pegA.push(pegA.top());
				pegA.pop();
			}


		}
		else if (option1 == 1 && option2 == 2)
		{
			if (pegA.size() == 0 && pegB.size() == 0)
			{
				cout << "Pillars are empyt..." << endl;
			}
			else if (pegB.size() == 0 || pegB.top() > pegA.top())
			{
				pegB.push(pegA.top());
				pegA.pop();
			}

		}
		else if (option1 == 1 && option2 == 3)
		{
			if (pegA.size() == 0 && pegC.size() == 0)
			{
				cout << "Pillars are empyt..." << endl;
			}
			else if (pegC.size() == 0 || pegC.top() > pegA.top())
			{
				pegC.push(pegA.top());
				pegA.pop();
			}

		}
		else if (option1 == 2 && option2 == 1)
		{
			if (pegB.size() == 0 && pegA.size() == 0)
			{
				cout << "Pillars are empyt..." << endl;
			}
			else if (pegA.size() == 0 || pegA.top() > pegB.top())
			{
				pegA.push(pegB.top());
				pegB.pop();
			}

		}
		else if (option1 == 2 && option2 == 2)
		{
			if (pegB.size() == 0 && pegB.size() == 0)
			{
				cout << "Pillars are empyt..." << endl;
			}
			else if (pegA.size() == 0 || pegB.top() > pegB.top())
			{
				pegB.push(pegB.top());
				pegB.pop();
			}

		}
		else if (option1 == 2 && option2 == 3)
		{
			if (pegB.size() == 0 && pegC.size() == 0)
			{
				cout << "Pillars are empyt..." << endl;
			}
			else if (pegA.size() == 0 || pegC.top() > pegB.top())
			{
				pegC.push(pegB.top());
				pegB.pop();
			}

		}
		else if (option1 == 3 && option2 == 1)
		{
			if (pegC.size() == 0 && pegA.size() == 0)
			{
				cout << "Pillars are empyt..." << endl;
			}
			else if (pegA.size() == 0 || pegA.top() > pegC.top())
			{
				pegA.push(pegC.top());
				pegC.pop();
			}

		}
		else if (option1 == 3 && option2 == 2)
		{
			if (pegC.size() == 0 && pegB.size() == 0)
			{
				cout << "Pillars are empyt..." << endl;
			}
			else if (pegA.size() == 0 || pegB.top() > pegC.top())
			{
				pegB.push(pegC.top());
				pegC.pop();
			}

		}
		else if (option1 == 3 && option2 == 3)
		{
			if (pegC.size() == 0 && pegC.size() == 0)
			{
				cout << "Pillars are empyt..." << endl;
			}
			else if (pegA.size() == 0 || pegC.top() > pegC.top())
			{
				pegC.push(pegC.top());
				pegC.pop();
			}

		}

		cout << endl;
	} while (true);
}


void towerOfHanoi()
{
	stack<int> pegA;
	stack<int> pegB;
	stack<int> pegC;

	int numberOfdisk = inputInteger("Enter the number of disk you want to play with: ", true);

	for(int i = numberOfdisk; i > 0; i--)
	{
		pegA.push(i);
	}

	moveFunction(pegA, pegB, pegC);
}
