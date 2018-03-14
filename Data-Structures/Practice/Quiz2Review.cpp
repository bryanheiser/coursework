#include <iostream>
using namespace std;

struct node
{
	int value;
	node *next;
};

node *DeleteNode(node *head, int value);
int main()
{
	node *head = new node;
	node *temp = new node;
	head = NULL;
	
}

node *DeleteNode(node *head, int value)
{
	node *tmp = head;
	node *tmp2 = head;
	while(tmp != NULL)
	{
		if(head->value == value)
		{
			head = head->next;
			delete tmp;
			tmp = head;
			tmp2 = head;
		}
		else if(tmp->value == value)
		{
			tmp2->next = tmp->next;
			delete tmp;
			tmp = tmp2->next;
		}
		else
		{
			tmp2 = tmp;
			tmp = tmp->next;
		}
	}
}
