

#include "Stackk.h"
#include <iostream>
using namespace std;

template <class T1>
Stack<T1>::Stack() {
	// TODO Auto-generated constructor stub
}
template <class T1>
void Stack<T1>::push(T1 exp){
	//cout << "\n\t\t---Push---" << endl;
	L.insert_first(exp);
}
template <class T1>
void Stack<T1>::pop(){
	//cout << "\n\t\t---Pop---" << endl;
	L.delete_first();
}
template <class T1>
T1 Stack<T1>::peep(){
	//cout << "\n\t\t---Peep---";
	//cout << "\n\t\t" << L.ret_head()->data << endl;
	T1 x = L.ret_data();
	return x;
}
template <class T1>
void Stack<T1>::display(){
	//cout << "\n\t\t---Display Stack---" << endl;
	LLNODE<T1> *temp = L.ret_head();
	while(temp !=NULL){
		cout << "\t  " << temp->data << " " ;
		temp = temp->next;
	}
}
template <class T1>
bool Stack<T1>::isempty(){

	if (L.ret_head() == NULL)
		return true;
	return false;
}

template <class T1>
Stack<T1>::~Stack() {
	// TODO Auto-generated destructor stub
}
