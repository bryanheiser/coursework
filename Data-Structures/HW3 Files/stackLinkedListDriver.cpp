#include <iostream>
#include "HW3-Todo-StackLinkedList.hpp"
using namespace std;

int main()
{
	TodoStackLinkedList test = TodoStackLinkedList();
	test.push("yo");
	test.push("what");
	//test.push("yes");
	test.pop();
	cout<<test.peek()->todo<<endl;
}
