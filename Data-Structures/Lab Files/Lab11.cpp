#include <iostream>
using namespace std;

void selectSort(int arr[], int n);
void insertionSort(int arr[], int length);
void swap(int *xp, int *yp);
void bubbleSort(int arr[], int n);
void shellSort(int arr[], int n);

int main()
{
	int arr1[] = {9, 7, 3, 1, 2};
	int arr2[] = {9, 7, 3, 1, 2};
	int arr3[] = {9, 7, 3, 1, 2};
	int arr4[] = {9, 7, 3, 1, 2};
	int n = 5;
	selectSort(arr1, n);
	insertionSort(arr2, n);
	bubbleSort(arr3, n);
	shellSort(arr4, n);
	for(int i = 0; i < n; i++)
		cout << arr1[i] << " ";
	cout << endl;
	for(int j = 0; j < n; j++)
		cout << arr2[j] << " ";
	cout << endl;
	for(int x = 0; x < n; x++)
		cout << arr3[x] << " ";
	cout << endl;
	for(int y = 0; y < n; y++)
		cout << arr4[y] << " ";
	cout << endl;
}

void selectSort(int arr[], int n)
{
	int index_min_value;
	int temp;
	
	for(int i = 0; i < n-1; i++)
	{
		index_min_value = i;
		for(int j = i+1; j < n; j++)
		{
			if(arr[j] < arr[index_min_value])
				index_min_value = j;
		}
		if(index_min_value != i)
		{
			temp = arr[i];
			arr[i] = arr[index_min_value];
			arr[index_min_value] = temp;
		}
	}
}

void insertionSort(int arr[], int length)
{
	int j, temp;
	for(int i = 0; i < length; i++)
	{
		j = i;
		while(j > 0 && arr[j] < arr[j-1])
		{
			temp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = temp;
			j--;
		}
	}
}

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(int arr[], int n)
{
	int i,j;
	for(i = 0; i < n-1; i++)
	{
		for(j = 0; j < n-i-1; j++)
		{
			if(arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
		}
	}
}

void shellSort(int arr[], int n)
{
	for(int gap = n/2; gap > 0; gap /= 2)
	{
		for(int i = gap; i < n; i++)
		{
			int temp = arr[i];
			int j;
			for(j = i; j >= gap && arr[j-gap] > temp; j -= gap)
				arr[j] = arr[j-gap];
			arr[j] = temp;
		}
	}
}
