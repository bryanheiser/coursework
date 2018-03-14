#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
	int key;
	Node *previous;
	Node *next;
};

void printReverse(Node *tail);
void printForward(Node *head);

int main()
{
	Node *head;
	Node *tail;
	Node *insert;
	
	//1st Node
	insert = new Node;
	insert->key = 0;
	insert->next = NULL;
	insert->previous = NULL;
	head = insert;
	tail = insert;
	
	//2nd Node
	insert = new Node;
	insert->key = 1;
	insert->next = NULL;
	insert->previous = NULL;
	insert->previous = tail;
	tail->next = insert;
	tail = insert;
	
	//3rd Node
	insert = new Node;
	insert->key = 2;
	insert->next = NULL;
	insert->previous = NULL;
	insert->previous = tail;
	tail->next = insert;
	tail = insert;
	
	printForward(head);
	printReverse(tail);
	
	return 0;
}
	
void printForward(Node *head)
{
	Node *index = head;
	if(head == NULL) 
		return;
	else
	{
		while(index != NULL)
		{
			cout << index->key << " ";
			index = index->next;
		}
		cout << endl;
	}
	return;
}

void printReverse(Node *tail)
{
	Node *index = tail;
	if(tail == NULL)
		return;
	else
	{
		while(index != NULL)
		{
			cout << index->key << " ";
			index = index->previous;
		}
		cout << endl;
	}
	return;
}
