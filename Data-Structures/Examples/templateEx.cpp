// template example

#include <iostream>
using namespace std;
template <typename Type>
Type sqr(Type x)
{
	return x * x;
}

int main()
{
	int n = 3;
	int square = sqr(n);
	cout << square << endl;
	double sq2 = sqr(3.1415926);
	cout << sq2 << endl;
}


