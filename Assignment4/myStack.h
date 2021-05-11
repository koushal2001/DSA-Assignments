
#ifndef MYSTACK_H_
#define MYSTACK_H_
template <class T>//declaring template for generic programming
struct node{//structure
	T data; //Binary node
	struct node <T> * next;//next pointer
};

template <class T>
class myStack {
	node <T> *top;//pointing to top
public:
	//function declerations
	myStack();//constructor
	node <T> * getnode(T data);
	int isempty();//checking stack is empty or not
	void push(T data);//to push element in satck
	T pop();//to delete element in stack
	T peep();//it will return top value
	void display();//used to display
	virtual ~myStack();//destructor
};

#endif /* MYSTACK_H_ */
