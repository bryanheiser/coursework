#include <iostream>
#include <math.h>
using namespace std;

void firstDDigitLucas(int D);

int main()
{
	int D;
	cout << "Enter an integer: ";
	cin >> D;
	firstDDigitLucas(D);
}

void firstDDigitLucas(int D)
{
	unsigned long int LucasNums[100];
	unsigned long int index = pow(10,D-1);
	for(int i = 0; i < 100; i++)
	{
		if(i == 0)
			LucasNums[i] = 2;
		else if(i == 1)
			LucasNums[i] = 1;
		else
			LucasNums[i] = LucasNums[i-1] + LucasNums[i-2];
	}
	
	for(int j = 0; j < 100; j++)
	{
		if(LucasNums[j] >= index)
		{
			cout << "(" << j << ", " << LucasNums[j] << ")" << endl;
			return;
		}
	}
}
