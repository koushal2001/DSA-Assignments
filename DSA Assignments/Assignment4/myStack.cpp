
#include "myStack.h"

#include <iostream>
using namespace std;

template <class T>//template
myStack<T>::myStack() {//constructor
	// TODO Auto-generated constructor stub
	top = NULL;//setting top to null
}

template <class T>//template
void myStack<T>:: display(){//display
	node<T> *temp = top;//creating a pointer which points to top of stack
	while(temp != NULL){
		cout << "\n\t| " << temp->data << "  |";
		temp = temp->next;//traversing through all nodes
	}
}
template <class T>//template
T myStack<T>::peep(){//peep fxn
	return top->data;//returning top value
}

template <class T>//template
node <T> *myStack <T>::getnode(T data){
	node <T> * temp = new node <T>;//creating new node
	temp -> data = data;//putting data in first part
	temp -> next = NULL;//and null in second part
	return temp;
}

template <class T>//template
int myStack<T>::isempty(){//checking stack is empty or not
	if(top == NULL)//if top is null
		return 1;//return 1
	return 0;
}

template <class T>//template
void myStack<T>::push(T data){//pushing element in stack
	if(isempty()){//if stack is empty
		top = getnode(data);//then top will point to new node
	}
	else{
		node <T> *temp = getnode(data);//creating a pointer pointing to new node
		temp ->next = top;
		top = temp;
	}
}

template <class T>
T myStack<T>:: pop(){//deleting top element
	node <T> *temp = top;//creating pointer which will point to top
	T data = top->data;//then change the top location
	top = top->next;//top will point to top next
	delete temp;//and then delete created pointer
	return data;
}
template <class T>
myStack<T>::~myStack() {
	// TODO Auto-generated destructor stub
}
