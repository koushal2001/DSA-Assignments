
#ifndef HEAPSORTHEADER_H_
#define HEAPSORTHEADER_H_

class HeapSort
{
public:
	void createMaxHeap(int arr[] , int n); //method to create max heap
	void createMinHeap(int arr[] , int n); //method to create min heap
	void maxHeapify(int arr[] , int n , int i); //method for max heapify
	void minHeapify(int arr[] , int n , int i); //method for min heapify
	void displayHeap(int arr[] , int n); //method to display heap
	void displayReverse(int arr[] , int n); //method to display sorted heap
	void insertNewElementInHeap(int arr[] , int& n , int element); //method to insert new element in heap
	void heapSortMaxHeap(int arr[] , int n); //method for heap sort using max heapify
	void heapSortMinHeap(int arr[] , int n); //method for heap sort using min heapify
};

#endif /* HEAPSORTHEADER_H_ */
