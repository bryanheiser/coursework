#include "Lab8StarterCode.hpp"
using namespace std;

int HashTab::HashFunc(int key)
{
	return key % TABLE_SIZE;
}

void HashTab::Insert(int key)
{
	int hash_index = HashFunc(key);
	if(htable[hash_index] == NULL)
		htable[hash_index] = new Node(key);
	else {
		Node *current = htable[hash_index];
		while(current->next != NULL) current = current->next;
		
		current->next = new Node(key);
	}
}

void HashTab::display()
{
	for(int i = 0; i < TABLE_SIZE; i++) {
		Node* current = htable[i];
		while(current != NULL) {
			cout << current->key << "-->";
			current = current->next;
		}
		cout << endl;
	}
}

int HashTab::Find(int key)
{
	int hash_position = HashFunc(key);
	int count = 0;
	if(htable[hash_position] == NULL) return -1;
	
	Node *current = htable[hash_position];
	while(current != NULL && current->key != key) {
		count++;
		current = current->next;
	}
	if(current == NULL) return -1;
	else return count;
}

void HashTab::Delete(int key)
{
	int hash_index = HashFunc(key);
	if(htable[hash_index] != NULL) {
		Node *current = htable[hash_index];
		Node *prev = NULL;
		while(current->next != NULL && current->key != key) {
			prev = current;
			current = current->next;
		}
		if(current->key == key) {
			if(prev == NULL) {
				Node* temp = current->next;
				delete current;
				htable[hash_index] = temp;
			}
			else {
				prev->next = current->next;
				delete current;
			}
		}
	}
}

