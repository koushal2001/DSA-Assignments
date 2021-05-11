
#include "Stackk.h"
#include "LL.h"
#include <iostream>
using namespace std;

template<class T1>
LinkList<T1>::LinkList() {
	// TODO Auto-generated constructor stub
	head = NULL;	//Assigning head pointer to NULL

}
template<class T1>
LLNODE<T1> *LinkList<T1>::getnode(T1 exp) //Get node function creates a node and inputs its value
{
    LLNODE<T1> *temp = NULL; //Creating a pointer
    temp = new (LLNODE<T1>); //Pointing it to a new node
    if (temp == NULL)
        cout << "\n\t Not able to allocate memory";
    else				 //Taking input
    {
    	temp->data = exp;
        temp->next = NULL;
    }
    return temp;		//Returning the node
}
template<class T1>
void LinkList<T1>::insert_first(T1 exp){	//Insert at head
	LLNODE<T1> *temp = getnode(exp);	//Create a new node using getnode function

	temp->next = head;		//Point next of new node to head
	head = temp;			//Make new node as the head

}
template<class T1>
void LinkList<T1>::delete_first(){		//Deleting the first node
	LLNODE<T1> *temp = head;			//Storing head address in temporary pointer
	if(head != NULL){					//When head is not null
		head = head->next;				//Head will be the next node
		temp = NULL;					//temp == null
		delete(temp);					//First node is deleted
	}else								//Else underflow
		cout << "\n\t\t---Underflow!!---" << endl;
}
template<class T1>
LLNODE<T1> *LinkList<T1>::ret_head(){	//Return head
	LLNODE<T1> *temp = head;
	return temp;
}
template<class T1>
T1 LinkList<T1>::ret_data(){			//REturn data
	LLNODE<T1> *temp = head;
	return temp->data;
}
template<class T1>
LinkList<T1>::~LinkList() {
	// TODO Auto-generated destructor stub
}
