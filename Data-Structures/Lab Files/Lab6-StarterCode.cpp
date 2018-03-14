#include <iostream>

using namespace std;
struct TreeNode
{
   int key;
   TreeNode *left;
   TreeNode *right;
   TreeNode *parent;
};

void deleteNode(TreeNode *node, int key);
void deleteAndReplaceMinRight(TreeNode *node, int key);
void preOrderTraversal(TreeNode *node);
void inOrderTraversal(TreeNode *node);
void postOrderTraversal(TreeNode *node);

int main() {
	TreeNode *root = NULL;
//test case input
int a[] = { 25, 15, 30, 28, 35, 27, 29, 33, 70};
int length = 9;
int value = 30;	
	//end of input
	
	for(int i=0; i<length; i++) {
		TreeNode *newnode = new TreeNode;
		newnode->key = a[i];
		newnode->left=NULL;
		newnode->right=NULL;
		newnode->parent = NULL;
		if(root == NULL) {
			root = newnode;
		}
		else {
			TreeNode *temp = root;
			TreeNode *temp2 = NULL;
			while(temp!=NULL) {
				temp2=temp;
				if(temp->key > a[i]) {
					temp = temp->left;
				}
				else {
					temp = temp->right;
				}
			}
			if(a[i]<temp2->key)
			{
			    newnode->parent = temp2;
			    temp2->left = newnode;
			}
			else
			{
			    newnode->parent = temp2;
			    temp2->right = newnode;
			}
		}
	}
	/*deleteNode(root, value);
	cout<<"Pre Order Traversal:"<<endl;
	preOrderTraversal(root);
	cout<<endl<<"In Order Traversal:"<<endl;
	inOrderTraversal(root);
	cout<<endl<<"Post Order Traversal:"<<endl;
	postOrderTraversal(root);*/

	deleteAndReplaceMinRight(root,value);
	cout<<"Pre Order Traversal:"<<endl;
	preOrderTraversal(root);
	cout<<endl<<"In Order Traversal:"<<endl;
	inOrderTraversal(root);
	cout<<endl<<"Post Order Traversal:"<<endl;
	postOrderTraversal(root);
	return 0;
}
//---------------------TO DO----------------------
void deleteNode(TreeNode *node, int key) {
	TreeNode *current = node;
	while(current != NULL){
		if(key < current->key) current = current->left;
		else if(key > current->key) current = current->right;
		else break;
	}
	if(current->left == NULL && current->right == NULL){
		if(current->parent->left == current){
			current->parent->left = NULL;
		}
		else {
			current->parent->right = NULL;
		}
		delete current;
	}
	else if(current->left != NULL && current->right == NULL){
		if(current->parent->left == current){
			current->parent->left = current->left;
			current->left->parent = current->parent;
		}
		else {
			current->parent->right = current->left;
			current->left->parent = current->parent;
		}
		delete current;
	}
	else if(current->left == NULL && current->right != NULL){
		if(current->parent->left == current) {
			current->parent->left = current->right;
			current->right->parent = current->parent;
		}
		else {
			current->parent->right = current->right;
			current->right->parent = current->parent;
		}
		delete current;
	}
	else {
		TreeNode* minValue = current->left;
		while(minValue->right != NULL) minValue = minValue->right;
		current->key = minValue->key;
		if(minValue->left == NULL) {
			minValue->parent->right = NULL;
		}
		else {
			minValue->parent->right = minValue->left;
			minValue->left->parent = minValue->parent;
		}
		delete minValue;
	}
	
	return;
}


//---------------------TO DO----------------------
void deleteAndReplaceMinRight(TreeNode *node, int key) {
	TreeNode *current = node;
	while(current != NULL){
		if(key < current->key) current = current->left;
		else if(key > current->key) current = current->right;
		else break;
	}
	if(current->left == NULL && current->right == NULL){
		if(current->parent->left == current){
			current->parent->left = NULL;
		}
		else {
			current->parent->right = NULL;
		}
		delete current;
	}
	else if(current->left != NULL && current->right == NULL){
		if(current->parent->left == current){
			current->parent->left = current->left;
			current->left->parent = current->parent;
		}
		else {
			current->parent->right = current->left;
			current->left->parent = current->parent;
		}
		delete current;
	}
	else if(current->left == NULL && current->right != NULL){
		if(current->parent->left == current) {
			current->parent->left = current->right;
			current->right->parent = current->parent;
		}
		else {
			current->parent->right = current->right;
			current->right->parent = current->parent;
		}
		delete current;
	}
	else {
		TreeNode* minValue = current->right;
		while(minValue->left != NULL) minValue = minValue->left;
		current->key = minValue->key;
		if(minValue->right == NULL) {
			minValue->parent->left = NULL;
		}
		else {
			minValue->parent->left = minValue->right;
			minValue->right->parent = minValue->parent;
		}
		delete minValue;
	}
	
	return;

}

void preOrderTraversal(TreeNode *node)
{
	if(node == NULL)
		return;
	else
	{
		cout<<node->key<<" ";
		preOrderTraversal(node->left);
		preOrderTraversal(node->right);
	}
}
void inOrderTraversal(TreeNode *node)
{
	if(node == NULL)
		return;
	else
	{
		inOrderTraversal(node->left);
		cout<<node->key<<" ";
		inOrderTraversal(node->right);
	}
}
void postOrderTraversal(TreeNode *node)
{
	if(node == NULL)
		return;
	else
	{
		postOrderTraversal(node->left);
		postOrderTraversal(node->right);
		cout<<node->key<< " ";

	}
}

