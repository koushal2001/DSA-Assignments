//er
#include <iostream>
#include "HeapSortHeader.h"
using namespace std;

int main() {

	int ch;
	int arr[100],n=0;
	//creating object of HeapSort class
	HeapSort heapObject;

	do
	{
		//Menu driven
		cout<<"\n 1. Enter Heap Data \n 2. Create Max Heap \n 3. Create Min Heap "
				"\n 4. Max Heap Sort \n 5. Min Heap Sort \n 6. Insert In Heap \n 7. Exit"<<endl;
		cout<<"Enter your choice: "<<endl;
		cin>>ch;

		//switch cases
		switch(ch)
		{
		//case 1 to take user input of elements of heap
		case 1:
		{
			cout<<"Enter number of elements in the heap: "<<endl;
			cin>>n;
			cout<<"Enter elements of the heap array..."<<endl;
			for(int i=0 ; i<n ; i++)
			{
				cout<<"Element "<<(i+1)<<": ";
				cin>>arr[i];
			}
			break;
		}//end of case 1

		//case 2 for creating max heap
		case 2:
		{
			//validating if user skips case 1
			if(n==0)
			{
				cout<<"Enter heap elements first..."<<endl;
			}
			else
			{
				heapObject.createMaxHeap(arr,n); //calling method to create max heap
				cout<<"Max Heap is: "<<endl;
				heapObject.displayHeap(arr,n); //calling method to display max heap
			}
			break;
		}//end of case 2

		//case 3 for creating min heap
		case 3:
		{
			//validating if user skips case 1
			if(n==0)
			{
				cout<<"Enter heap elements first..."<<endl;
			}
			else
			{
				heapObject.createMinHeap(arr,n); //calling method to create min heap
				cout<<"Min Heap is: "<<endl;
				heapObject.displayHeap(arr,n); //calling method to display min heap
			}
			break;
		}//end of case 3

		//case 4 for heap sort using max heapify
		case 4:
		{
			//validating if user skips case 1
			if(n==0)
			{
				cout<<"Enter heap elements first..."<<endl;
			}
			else
			{
				heapObject.heapSortMaxHeap(arr,n);  //calling method for heap sort using max heap
				cout<<"Result of heap sort: "<<endl;
				heapObject.displayReverse(arr,n); //calling method to display sorted array
			}
			break;
		}//end of case 4

		//case 5 for heap sort using min heapify
		case 5:
		{
			//validating if user skips case 1
			if(n==0)
			{
				cout<<"Enter heap elements first..."<<endl;
			}
			else
			{
				heapObject.heapSortMinHeap(arr,n); //calling method for heap sort using min heap
				cout<<"Result of heap sort using min heapify is: "<<endl;
				heapObject.displayReverse(arr,n); //calling method to display sorted array
			}
			break;
		}//end of case 5

		//case 6 to insert new element in heap
		case 6:
		{
			int element;
			cout<<"Enter the element to be inserted: ";
			cin>>element;
			//calling method to insert new element in heap
			heapObject.insertNewElementInHeap(arr,n,element);
			break;
		}//end of case 6

		//exit case
		case 7:
		{
			cout<<"Application exited successfully :)"<<endl;
			break;
		}//end of case 7
		}

	}while(ch!=7); //end of do-while loop

	return 0;
}
