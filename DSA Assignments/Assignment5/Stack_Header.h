

#ifndef STACK_HEADER_H_
#define STACK_HEADER_H_
#include <iostream>
#include <iomanip>
using namespace std;

//Initializing Structure Node.
template <class H>
struct Node
{
public:
	//Data Members Of Node.
	H data;
	Node * next;
};

//Initializing Class Stack.
template <class H>
class Stack_ll
{
private :
	//Data Members Of Stack_ll.
	int count;
	Node<H>*top;

public :
	//Constructor.
	Stack_ll();
	//Push Method.
	void push(H val);
	//Pop Method.
	H pop();
	//Peek Method.
	H peek();
	//Checking If Stack is Empty.
	bool isempty();
	//Destructor.
	~Stack_ll();
};

#endif /* STACK_HEADER_H_ */
