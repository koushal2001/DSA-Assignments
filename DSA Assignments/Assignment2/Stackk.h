
#ifndef STACKK_H_
#define STACKK_H_
#include "LL.h"
template <class T1>
class Stack {

	LinkList<T1> L;

public:
	Stack();
	//void push(int);
	void push(T1);		//Push node
	void pop();			//Pop or delete node
	T1 peep();			//Display top
	void display();		//Display stack
	bool isempty();		//Check if empty
	bool isfull();		//check if full

	virtual ~Stack();


};


#endif /* STACKK_H_ */
