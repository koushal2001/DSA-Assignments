
#ifndef LL_H_
#define LL_H_
#include "Stackk.h"
//node structure
template<typename T1>	//Using templates
struct LLNODE{		//Node structure
	T1 data;		//Data
	LLNODE<T1> *next;	//Neat pointer
};

template<class T1>	//Template for class
class LinkList {

	LLNODE<T1> *head;	//Defining head pointer

public:
	LinkList();			//Constructor

	LLNODE<T1> *getnode(T1 exp);	//Creating a new node
	LLNODE<T1> *ret_head();			//Return head function
	T1 ret_data();					//Return data
	void insert_first(T1 exp);		//Insert at first
	void delete_first();			//Delete first node
	void delete_end();
	void delete_inbetween();

	void display();
	virtual ~LinkList();


};




#endif /* LL_H_ */
