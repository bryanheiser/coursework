#include <iostream>
#include "HW3-Todo-QueueArray.hpp"
using namespace std;

TodoQueueArray::TodoQueueArray()
{
	queueFront = 0;
	queueEnd = 0;
	for(int i = 0; i < MAX_QUEUE_SIZE; i++)    //creates array of TodoItems for queue
	{
		queue[i] = new TodoItem;
	}
}

bool TodoQueueArray::isEmpty()
{
	if(queueEnd == 0 && queueFront == 0)    //checks if nothing is in the array
		return true;
	else
		return false;
}

bool TodoQueueArray::isFull()
{
	if(queueEnd == MAX_QUEUE_SIZE)      //checks if the array is full
		return true;
	else
		return false;
}

void TodoQueueArray::enqueue(string todoItem)
{
	if(queueEnd == MAX_QUEUE_SIZE)
	{
		cout<<"queue full, cannot enqueue"<<endl;        //makes sure enqueuing is possible
	}
	else 
	{
		queueEnd++;
		queue[queueEnd]->todo = todoItem;              //adds new todoItem to queue
	}	
}

void TodoQueueArray::dequeue()
{
	if(queueEnd == 0 && queueFront == 0)
	{
		cout<<"queue empty, cannot dequeue"<<endl;     //checks if dequeuing is possible
	}
	else
	{
		queue[queueFront]->todo = "";               //erases the element at the front of the queue
		queueFront++;
	}
}

TodoItem* TodoQueueArray::peek()
{
	if(queueEnd == 0 && queueFront == 0)
	{
		cout<<"queue empty, cannot peek"<<endl;     //checks if peeking is possible
		return NULL;
	}
	else
	{
		return queue[queueEnd];           //returns the first element that was added to the array
	}
}
