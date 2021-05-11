

#include <iostream>
#include "queue_Header.h"
using namespace std;

//Constructor.
template <class H>
QNode<H>::QNode(H x)
{
	data = x;
	next = NULL;
}

//Constructor.
template <class H>
queue<H>::queue()
{
	front = rear = NULL;
	count = 0;
}

//enqueue method
template <class H>
void queue<H>::enqueue(H x)
{
	QNode<H>* temp = new QNode<H>(x);

	if(rear == NULL){
		front = rear = temp;
		count++;
		return;
	}
	rear->next = temp;
	rear = temp;
	count++;
}

//dequeue method.
template <class H>
H queue<H>::dequeue()
{
	if(front == NULL){
		return NULL;
	}
	QNode<H>* temp = front;
	front = front->next;
	count--;

	if(front == NULL){
		rear = NULL;
		count = 0;
	}
	return temp->data;
}

//Method to check if queue is empty.
template <class H>
bool queue<H>::isempty()
{
	if(front == NULL){
		return true;
	}
	return false;
}

//Method for count.
template <class H>
int queue<H>::size()
{
	return count;
}

//Destructor.
template <class H>
queue<H>::~queue()
{
	free(front);
	free(rear);
}

