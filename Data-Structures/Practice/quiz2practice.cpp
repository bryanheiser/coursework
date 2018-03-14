#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
	int value;
	node *next;
};

void printPath(node *ptr);
int main()
{
	node *newNode = new node;
	node *head = NULL;
	head = newNode;
	newNode->value = 1;
	newNode->next = NULL;
	node *newNode2 = new node;
	newNode2->value = 2;
	newNode2->next = NULL;
	newNode->next = newNode2;
	printPath(head);
	head = newNode->next;
	newNode->next = NULL;
	delete newNode;
	printPath(head);
}

void printPath(node *ptr)
{
    cout << "== CURRENT PATH ==" << endl;

    // If the head is NULL
    if (ptr == NULL)
    {
        cout << "nothing in path" << endl;
        cout << "==================" << endl;
        return;
	}
	
	while(ptr != NULL)
	{
		cout << ptr->value << " -> ";           //goes thru list and prints each city
		ptr = ptr->next;
	}
	cout << "NULL" << endl;
    cout << "==================" << endl;
}
