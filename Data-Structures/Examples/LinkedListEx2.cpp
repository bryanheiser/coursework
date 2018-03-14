#include <iostream>
#include <cstdlib>
using namespace std;

struct ListNode
{
  int value;
  ListNode *next;
};

int main() 
{
  ListNode *head = NULL;
  ListNode *newNode = new ListNode;
  newNode->next = NULL;
  head = newNode;
  
}
