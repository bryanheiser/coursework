#include <iostream>
using namespace std;

int myMethod(int x);

int main()
{
	cout << myMethod(4) << endl;
}

int myMethod(int x)
{
	int y;
	if(x == 0)
	{
		return 1;
	}
	else
	{
		y = 2 * myMethod(x - 1);
		return y+1;
	}
}
