#include <iostream>
#include "HW3-Todo-StackLinkedList.hpp"
using namespace std;

TodoStackLinkedList::TodoStackLinkedList()
{
	stackHead = NULL;                   //points the head to NULL
}

bool TodoStackLinkedList::isEmpty()
{
	if(stackHead == NULL)               //checks if linked list is empty
		return true;
	else
		return false;
}

void TodoStackLinkedList::push(std::string todoItem)
{
	TodoItem *tmp = new TodoItem;			//adds new TodoItem to list
	tmp->next = stackHead;
	stackHead = tmp;
	tmp->todo = todoItem;
}

void TodoStackLinkedList::pop()
{
	if(stackHead == NULL)
	{
		cout<<"stack empty, cannot pop"<<endl;    //checks if pooping is possible
	}
	else
	{
		TodoItem *tmp = new TodoItem;
		tmp = stackHead;
		stackHead = tmp->next;                  //removes last element put into the list
		delete tmp;
	}
}

TodoItem* TodoStackLinkedList::peek()
{
	if(stackHead == NULL)
	{
		cout<<"stack empty, cannot peek"<<endl;				//checks if peeking is possible
		return NULL;
	}
	else
		return stackHead;				//returns the last element that was put in the list
}
