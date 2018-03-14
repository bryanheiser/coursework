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
  //add a node
  ListNode *newLN = new ListNode;
  newLN->value = 9;
  //cout << newLN << endl; //prints address
  //cout << *newLN << endl; //returns error
  cout << newLN->value << endl; //works
  cout << (*newLN).value << endl; //works
  head = newLN;
  cout << head << endl;
  head->next = newLN;
  ListNode *ptr = NULL;
  prt->next = newLN;
}
