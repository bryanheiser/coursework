Bike* populateBikes(string list[ ], int size)
{
	Bike *arr = new Bike[size];
	for(int i = 0; i < size; i++)
		arr[i].style = list[i];
	return arr;
}

template <typename T>
T getSquare(T value)
{
	T result = value * value;
	return result;
}

int LinkedListCount(node *head, int val)
{
	node *temp = head;
	int count = 0;
	while(temp != NULL)
	{
		if(temp.value == val)
		{
			count++;
			temp = temp->next;
		}
		else
			temp = temp->next;
	}
	return count;
}

//*
TreeNode *func(TreeNode *root)
{
	if(root->left != NULL)
		func(root->left);
	if(root->left == NULL && root->right == NULL)
		root->key--;
	if(root->right != NULL)
		func(root->right);
		
	return root;
}
