

#include<iostream>
#include "HeapSortHeader.h"

using namespace std;

//method for max heapify
void HeapSort::maxHeapify(int arr[] , int n , int i)
{
	int largest = i;//store i in largest variable
	int leftChild = 2*i+1;//store 2i+1 in left child
	int rightChild = 2*i+2;//store 2i+2 in right child

	if(leftChild < n && arr[leftChild]>arr[largest])
	{
		largest = leftChild;//assign leftchild to largest
	}

	if(rightChild<n && arr[rightChild] > arr[largest])
	{
		largest = rightChild;//assign rightchild to largest
	}
	if(largest != i)
	{
		//swapping
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;

		maxHeapify(arr , n , largest); //recursive call

	}
}

//method for min heapify
void HeapSort::minHeapify(int arr[] , int n , int i)
{
	int leftChild = 2*i+1;//store 2i+1 in left child
	int rightChild = 2*i+2;//store 2i+2 in right child
	int smallest = i;//store i in smallest variable

	if(leftChild<n && arr[leftChild]<arr[i])
	{
		smallest = leftChild;//assign leftchild to smallest
	}
	if(rightChild<n && arr[rightChild] < arr[smallest])
	{
		smallest = rightChild;//assign rightchild to smallest
	}


	if(smallest!=i)
	{
		//swapping
		int temp = arr[i];
		arr[i] = arr[smallest];
		arr[smallest] = temp;

		minHeapify(arr,n,smallest); //recursive call
	}


}

//method to create min heap
void HeapSort::createMinHeap(int arr[] , int n)
{
	cout<<"Passwise result of creating Max Heap:::"<<endl;
	int d=1;
	for(int i=n/2 - 1 ; i>=0 ; i--)
	{
		minHeapify(arr , n , i); //recursive call
		cout<<"Pass "<<d++<<":: ";
        displayHeap(arr,n);
	}
}

//method to create max heap
void HeapSort::createMaxHeap(int arr[] , int n)
{
	cout<<"Passwise result of creating Max Heap:::"<<endl;
		int d=1;
	for(int i=n/2 - 1 ; i>=0 ; i--)
	{
		maxHeapify(arr , n , i); //recursive call
		cout<<"Pass "<<d++<<":: ";
		displayHeap(arr,n);

	}
}

//method to display heap
void HeapSort::displayHeap(int arr[] , int n)
{
	for(int i=0 ; i<n ; i++)
	{
		cout<<arr[i]<<" ";//printing array elements
	}
	cout<<endl;
}

//method to display sorted heap
void HeapSort::displayReverse(int arr[] , int n)
{
    for(int i=n-1 ; i>=0 ; i--)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//method for heap sort using max heapify
void HeapSort::heapSortMaxHeap(int arr[] , int n)
{
	createMaxHeap(arr , n);
	cout<<"\nPasswise Result of Max heap sort::"<<endl<<endl;
	for(int i = n-1 ; i>=0 ; i--)
	{
		//swapping
		int temp = arr[0];
		cout<<"Deleted element: "<<temp<<endl;
		arr[0] = arr[i];
		arr[i] = temp;

		maxHeapify(arr , i , 0); //recursive call
		displayHeap(arr,i);
	}
}

//method for heap sort using min heapify
void HeapSort::heapSortMinHeap(int arr[] , int n)
{
	createMinHeap(arr,n);
	cout<<"Passwise Result of Max heap Sort::"<<endl<<endl;
	for(int i=n-1 ; i>=0 ; i--)
	{
		//swapping
		int temp = arr[0];

		cout<<"Deleted element: "<<temp<<endl;
		arr[0] = arr[i];
		arr[i] = temp;

		minHeapify(arr , n , i); //recursive call
		displayHeap(arr,i);
	}
}

//method to insert new element in heap
void HeapSort::insertNewElementInHeap(int arr[] , int& n , int element)
{
	n++;
	arr[n-1] = element;
	maxHeapify(arr , n , n-1); //recursive call
}
