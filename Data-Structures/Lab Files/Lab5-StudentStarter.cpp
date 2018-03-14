#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Return the total number of nodes in the BST.
int getSize(Node* node);

// Return the minimal value in the BST.
int getminValue(Node* node);

// Return the maximum depth of a path in the tree.
int getmaxDepth(Node* node);

// print the tree starting the youngest(smallest) child. 
void printTree(Node* node);

// Insert the new value into the BST in the correct position.
Node *newNode(int data);

// add data given the root (parent)
Node *addNode(Node* node, int data);


int main (int argc, char* argv[]){
  Node* root = NULL;

  root = newNode(5);
  
  addNode(root,3); //left child to 5
  addNode(root,9); //right child to 5

  addNode(root,1); //left child to 3
  addNode(root,4); //right child to 3

  addNode(root,6); //left child to 9

  addNode(root, 2); //left child to 4


  printTree(root);
  cout << endl << "There are " << getSize(root) << " nodes in the tree" << endl;
  cout << "The minimum value node is:  " << getminValue(root) << endl;
  cout << "There max depth is: " << getmaxDepth(root) << endl;
}


Node *newNode(int data) 
{
  Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}

Node *addNode(Node* node, int data) 
{
	if(node == NULL) {
		return newNode(data);
	}
	else {
		if(data < node->data)
			node->left = addNode(node->left, data);
		else
			node->right = addNode(node->right, data);
		
		return node;
	}
}

int getSize(Node* node) 
{
	if(node == NULL) return 0;
	return getSize(node->left) + getSize(node->right) + 1;
}

int getminValue(Node* node) 
{
	if(node == NULL) return 0;
	Node* cur = node;
	while(cur->left != NULL) {
		cur = cur->left;
	}
	return cur->data;
}

void printTree(Node* node) 
{
	if(node == NULL) return;
	printTree(node->left);
	cout << node->data << endl;
	printTree(node->right);
	return;
}

int getmaxDepth(Node* node) 
{
	if(node == NULL) return 0;
	int leftDepth = getmaxDepth(node->left);
	int rightDepth = getmaxDepth(node->right);
	if(leftDepth < rightDepth) return rightDepth+1;
	else return leftDepth+1;
}

