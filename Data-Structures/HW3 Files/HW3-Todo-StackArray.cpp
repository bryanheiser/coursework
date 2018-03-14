#include <iostream>
#include "HW3-Todo-StackArray.hpp"
using namespace std;

TodoStackArray::TodoStackArray()
{
	stackTop = -1;
	for(int i = 0; i < MAX_STACK_SIZE; i++)         //fills array with TodoItems for stack
		stack[i] = new TodoItem;
}

bool TodoStackArray::isEmpty()
{
	if(stackTop == -1)               //checks if an element has been added to the array
		return true;
	else
		return false;
}

bool TodoStackArray::isFull()
{
	if(stackTop == MAX_STACK_SIZE)   //checks if array is at max capacity
		return true;
	else
		return false;
}

void TodoStackArray::push(string todoItem)
{
	if(stackTop == MAX_STACK_SIZE)
	{
		cout<<"stack full, cannot push"<<endl;    //checks if pushing is possible
	}
	else
	{
		stack[++stackTop]->todo = todoItem;             //adds new element to array
	}
}

void TodoStackArray::pop()
{
	if(stackTop == -1)
	{
		cout<<"stack empty, cannot pop"<<endl;    //checks if popping is possible
	}
	else
	{
		stack[stackTop]->todo = "";             //erases element in that pos of the array
		stackTop--;
	}
}

TodoItem* TodoStackArray::peek()
{
	if(stackTop == -1)
	{
		cout<<"stack empty, cannot peek"<<endl;      //checks if peeking is possible
		return NULL;
	}
	else
	{
		return stack[stackTop];              //returns last element added to array
	}
}
