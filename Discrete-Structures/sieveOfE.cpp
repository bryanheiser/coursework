#include <iostream>
#include <math.h>
using namespace std;
void sieveOfE(int N);
int main()
{
	int N;
	cout << "Enter an integer: ";
	cin >> N;
	sieveOfE(N);
}

void sieveOfE(int N)
{
	bool a[N+1];
	int count = 0;
	long int sum = 0;
	for(int i = 0; i <= N; i++)
	{
		if(i == 0)
			a[i] = false;
		else if(i == 1)
			a[i] = false;
		else
			a[i] = true;
	}
	for(int j = 2; j <= sqrt(N); j++)
	{
		for(int k = 2; k <= N; k++)
		{
			if(k != j)
			{
				int test = k%j;
				if(test == 0)
					a[k] = false;
			}
		}
	}
	for(int m = 2; m <= N; m++)
	{
		if(a[m] == true)
		{
			count++;
			sum += m;
		}
	}
	cout << "(" << count << "," << sum << ")" << endl;
}
