#include <iostream>
#include <math.h>
#include <limits.h>
using namespace std;

void findFactors(unsigned long long int n);

int main()
{
	unsigned long long int n;
	cout << "Enter a number to factor: ";
	cin >> n;
	findFactors(n);
}

void findFactors(unsigned long long int n)
{
	unsigned long long int max = sqrt(n);
	unsigned long long int i,j;
	unsigned long long int count = 0;
	unsigned long long int b = max/2;
	unsigned long long int a[b];
	for(i = 3; i <= max; i++)  //fill an array with all odd values
	{							//from 3 to sqrt(n)
		if(i%2 != 0)
		{
			a[count] = i;
			count++;
		}
	}
	for(j = 0; j <= b; j++) 	//test all numbers in the array to find
	{							//lower prime that divides n
		if(n%a[j] == 0)
		{
			cout<<"("<<a[j]<<","<<n/a[j]<<")"<<endl;
			return;
		}
	}
}
