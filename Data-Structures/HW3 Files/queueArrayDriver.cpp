#include <iostream>
#include "HW3-Todo-QueueArray.hpp"
using namespace std;

int main()
{
	TodoQueueArray test = TodoQueueArray();
	test.enqueue("hi");
	test.enqueue("yo");
	test.dequeue();
	cout<<test.peek()->todo<<endl;
	test.dequeue();
	cout<<test.peek()->todo<<endl;
}
