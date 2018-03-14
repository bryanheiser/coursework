#include <iostream>
#include "HW3-Todo-StackArray.hpp"
using namespace std;

int main()
{
	
	TodoStackArray test = TodoStackArray();
	
	test.push("hello");
	
	cout << test.peek()->todo << endl;
	test.push("hfhf");
	cout<<test.peek()->todo<<endl;
	test.pop();
	cout<<test.peek()->todo<<endl;
}
