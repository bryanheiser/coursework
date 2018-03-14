#include <iostream>
#include "HW3-Todo-QueueLinkedList.hpp"
using namespace std;

TodoQueueLinkedList::TodoQueueLinkedList()
{
	queueFront = NULL;                            //set head and tail ptrs to NULL
	queueEnd = NULL;
}

bool TodoQueueLinkedList::isEmpty()
{
	if(queueEnd == NULL)             //checks if tail ptr is pointing to NULL which means queue's empty
		return true;
	else
		return false;
}

void TodoQueueLinkedList::enqueue(std::string todoItem)
{
	if(queueEnd == NULL)
	{
		TodoItem *tmp = new TodoItem;                    //checks if element is being added as the first object
		queueFront = tmp;
		queueEnd = tmp;                                  //adds new item
		tmp->todo = todoItem;
		tmp->next = NULL;
	}
	else
	{
		TodoItem *tmp = new TodoItem;
		tmp->next = queueFront;                    //adds new item any other time
		queueFront = tmp;
		tmp->todo = todoItem;
	}
	
}

void TodoQueueLinkedList::dequeue()
{
	if(queueEnd == NULL)
	{
		cout<<"queue empty, cannot dequeue"<<endl;       //checks if dequeuing is possible
	}
	else
	{
		TodoItem *tmp = new TodoItem;
		TodoItem *tmp2 = new TodoItem;
		tmp = queueFront;
		tmp2 = queueEnd->next;
		if(queueFront == queueEnd)
		{
			delete tmp2;
			queueFront = NULL;						//dequeues if there is only one item left
			queueEnd = NULL;
		}
		else 
		{
			while (tmp->next != queueEnd)        //traverses thru list to find prev element before the last one
			{
				tmp = tmp->next;
			}
			queueEnd = tmp;
			tmp->next = NULL;                   //dequeues last element
			delete tmp2;
		}
	}
}

TodoItem* TodoQueueLinkedList::peek()
{
	if(queueEnd == NULL)
	{
		cout<<"queue empty, cannot peek"<<endl;       //checks if peeking is possible
		return NULL;
	}
	else
	{
		return queueEnd;           //returns first element added to queue
	}
}
