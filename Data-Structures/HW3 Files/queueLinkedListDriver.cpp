#include <iostream>
#include "HW3-Todo-QueueLinkedList.hpp"
using namespace std;

int main()
{
	TodoQueueLinkedList test = TodoQueueLinkedList();
	test.enqueue("booty");
	cout<<test.peek()->todo<<endl;
	test.dequeue();
	test.enqueue("word up");
	cout<<test.peek()->todo<<endl;
	test.dequeue();
	cout<<test.peek()->todo<<endl;
}
