
#include <iostream>
#include <iomanip>
#include "Stack_Header.h"
using namespace std;

//Constructor.
template <class H>
Stack_ll<H>::Stack_ll()
{
	count = 0;
	top = NULL;
}
//Push Method.
template <class H>
void Stack_ll<H>::push(H val)
{
	//Checking If First Element.
	if(count == 0)
	{
		//Creating New Node.
		Node<H> *temp = new Node<H>();
		//Assigning Data To The New Node.
		temp->data = val;
		temp->next = NULL;
		//Making The New Node As Top Element.
		top = temp;
		count++;
	}
	//Checking For Stack Size.
	/*
	else if(count == max_size)
	{
		//cout << "\nStack Overflow" << endl;
		return;
	}
	*/
	//Pushing The New Element.
	else
	{
		//Creating New Node.
		Node<H> *temp;
		temp = new Node<H>();

		//Assigning Data To The New Node.
		temp->data = val;
		temp->next = top;
		//Making The New Node As Top Element.
		top = temp;
		count++;
	}
}
//Pop Method.
template <class H>
H Stack_ll<H>::pop()
{
	Node<H> *temp;
	//Checking For If Stack Is Empty or Not.
	if(isempty())
	{
		//cout << "\nStack Underflow" << endl;
		return NULL;
	}
	//Else Popping The Element.
	else
	{
		temp = top;//Creating a local Node temp and assigning it to top.

		top = top->next;//Incrementing Top.
		temp->next = NULL;

		H str = temp->data;
		free(temp);//Deleting Previous top (i.e temp).
		count--;

		return str;
	}
}
//Peek Method.
template <class H>
H Stack_ll<H>::peek()
{
	//Checking for Condition If empty.
	if(isempty())
	{
		//cout<<"\nStack Empty"<<endl;
		return '\0';
	}
	//else Peeking the Top Element.
	else
	{
		return top->data;
		//cout<<"The Top Value Is : "<<top->data<<endl;
	}
}
//Checking If Stack is Empty.
template <class H>
bool Stack_ll<H>::isempty()
{
	//Checking If top is Null
	if(top == NULL)
	{
		return true;	//If Yes Then Return true.
	}
	else
	{
		return false;	//Else false.
	}
}
//Destructor.
template <class H>
Stack_ll<H>::~Stack_ll()
{
	//Initializing Temp Node.
	Node<H>* temp;
	//Initializing While Loop.
	while(top!=NULL)
	{
		temp = top;			//Assigning temp to top.
		top = temp->next;	//Incrimenting top.
		free(temp);			//Deleting Node.
	}
}





