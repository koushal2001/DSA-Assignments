

#ifndef QUEUE_HEADER_H_
#define QUEUE_HEADER_H_
#include <iostream>

//Class QNode.
template <class H>
struct QNode
{
	H data;			//Data Value.
	QNode<H>* next;	//Pointer to next.
	QNode(H x);		//Constructor.
};

//Class queue.
template <class H>
class queue
{
private:
	QNode<H> *front, *rear;	//front and rear pointer.
	int count;				//count of the number of elements.
public:
	queue();				//Constructor.
	void enqueue(H x);		//enqueue method.
	H dequeue();			//dequeue method.
	bool isempty();			//method to check if queue is empty.
	int size();				//method to check the size of the queue.
	~queue();				//Destructor.
};



#endif /* QUEUE_HEADER_H_ */
