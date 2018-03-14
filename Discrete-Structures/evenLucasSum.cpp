#include <iostream>
using namespace std;

int evenLucasSum(int N);

int main()
{
	int N;
	cout << "Enter an integer: ";
	cin >> N;
	cout << evenLucasSum(N) << endl;
}


int evenLucasSum(int N)
{
	int LucasNums[N+1];
	int sum = 0;
	
	for(int i = 0; i < N+1; i++)
	{
		if(i == 0)
			LucasNums[i] = 2;
		else if(i == 1)
			LucasNums[i] = 1;
		else
			LucasNums[i] = LucasNums[i-1] + LucasNums[i-2];
	}
	
	for(int j = 0; j < N+1; j++)
	{
		if((LucasNums[j] % 2) == 0)
			sum += LucasNums[j];
	}
	
	return sum;
}
