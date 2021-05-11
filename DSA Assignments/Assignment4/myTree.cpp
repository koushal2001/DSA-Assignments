

#include "myTree.h"

#include <iostream>
using namespace std;
myTree::myTree() {//constructor
	// TODO Auto-generated constructor stub
	root = NULL;//root is equal to null
}
//Defining class functions
tnode * myTree::retroot(){
	return root;//returing root
}

int myTree::isvalid(){			//Function to check if the input is valid
	int count1=0, count2=0;		//Assigning two counter variables
	char x;
	int l=sizeof(ip);			//Size of the given expression
	for(int i=0; i<l; i++){
		x=ip[i];
		if(isalpha(x)){//if input character is alphabet increment counter count2
			count2++;
		}else{//else increment counter count1
			count1++;
		}
	}
	if(count2 == (count1+1))	//No of Operands is 1 more than no of Operators
		return 1;
	return 0;
}

void myTree::input(){			//Input Expression fron user

	cout << "\nEnter expression:: ";
	cin >> ip;//input taken from user
}
void myTree::create(){
	myStack <tnode*> s2;			// stack
	int i;                          //declaring a variable
	int l= ip.length();             //length of input exp
	tnode * temp;                   //temporary pointer

	for(i=0; i<l; i++){
		char x =ip[i];
		if((x=='^')||(x=='*')||(x=='/')||(x=='%')||(x=='+')||(x=='-')||(x=='(')||(x==')')){//if character of input exp is same as the ch in condition then it will go inside if condition code
			temp = new tnode;//creating new node
			temp-> data = ip[i];//setting input char in data field
			temp->rchild = s2.peep();//setting  top value to rchild
			s2.pop();//deleting top ele
			temp->lchild=s2.peep();//setting  top value to 1child
			s2.pop();//deleting top ele
			s2.push(temp);//push temp pointer to stack s2
		}
		else{
			temp = new tnode;	//Create a new tree node
			temp-> data = ip[i];		//Assign data part to new node
			temp->lchild = NULL;		//Assign both child to NULL
			temp->rchild = NULL;
			s2.push(temp);//push temp pointer to stack s2
		}
	}
	root = s2.peep();
	s2.pop();//deleting top ele from s2 stack
}

void myTree::rec_inorder(tnode *temp){	//Recursive inorder
	if(temp!=NULL){						//Till node is not Null
		rec_inorder(temp->lchild);		//Recursively go to left
		cout << temp->data;				//Print the left most node data
		rec_inorder(temp->rchild);		//Then go to right node
	}
}
string myTree::reverse(string exp){
	int size = exp.size();
	int j = size, i = 0;
	char temp[size];						//Create a new temp to store the new string

	temp[j--] = '\0';						//Assign to null
	while (exp[i] != '\0')
	{
		temp[j] = exp[i];					//Store the first value in the expression in the last os temp
		j--;								//Decrement temp counter
		i++;								//Increment expression counter
	}
	exp = temp;							//Exp = temp

	 return exp;
}
void myTree::create_prefix(){
	myStack <tnode*> s2;//created a stl stack
	int i;//declaring a var
	int l= ip.length();//storing input length in l
	tnode * temp;//created a temp ptr
	ip= reverse(ip);//calling to reverse stl fxn to reverse whole input
	for(i=0; i<l; i++){
		char x =ip[i];
		if((x=='^')||(x=='*')||(x=='/')||(x=='%')||(x=='+')||(x=='-')||(x=='(')||(x==')')){//if input ch matches whit these ch then
			temp = new tnode;//creating new node
			temp-> data = ip[i];//setting input ch in data field
			temp->lchild = s2.peep();//setting  top value to left child
			s2.pop();//deleting top ele
			temp->rchild=s2.peep();//setting  top value to right child
			s2.pop();//deleting top ele
			s2.push(temp);//pushing temp to s2 stack
		}
		else{
			temp = new tnode;	//Create a new tree node
			temp-> data = ip[i];		//Assign data part to new node
			temp->lchild = NULL;		//Assign both child to NULL
			temp->rchild = NULL;
			s2.push(temp);
		}
	}
	root = s2.peep();
	s2.pop();

}

void myTree::rec_preorder(tnode *temp){	//Recursive preorder
	if(temp!=NULL){						//Till node is not null
		cout << temp->data;				//Print the root data
		rec_preorder(temp->lchild);		//Then go to left
		rec_preorder(temp->rchild);		//Next go to the right node
	}
}
void myTree::rec_postorder(tnode *temp){ //Recursive postorder
	if(temp!=NULL){						 //Till node is not NULL
		rec_postorder(temp->lchild);	 //Print the leftmost node first
		rec_postorder(temp->rchild);	 //Print the rightmost node next
		cout << temp->data;				 //Then the root
	}
}

void myTree::nrec_inorder(tnode *temp){//non recursive inorder
	myStack <tnode *> s;//created a stack
	if(temp == NULL){//if temp null then tree is empty
		cout << "\nTree is empty" << endl;
		return;
	}
	while(temp!=NULL){
		s.push(temp);//pushing temp in stack
		temp = temp->lchild;//traversing till the last left child is reached
	}
	while(!s.isempty()){//this will run until stack is not empty
		temp = s.pop();// deleting top ele
		cout << temp-> data;//printing data
		temp = temp->rchild;//setting temp to right child of deleted item
		while(temp!=NULL){
			s.push(temp);//pushing temp in stack
			temp=temp->lchild;//traversing till last element in left
		}
	}
}
void myTree::nrec_postorder(tnode *temp){//postorder
	myStack <tnode *> s1;//created two stacks
	myStack <tnode *> s2;
	if(temp == NULL){//if temp null then tree is empty
		cout << "\nTree is empty!" << endl;
		return;
	}
	s1.push(temp);//pushing temp to stack which is root
	while(!s1.isempty()){//this will run until stack is not empty
		temp = s1.pop();//storing deleted item in temp
		s2.push(temp);//push to s2 stack
		if(temp->lchild != NULL){//if deleted item has left child then push to s1 stack
			s1.push(temp->lchild);
		}
		if(temp->rchild != NULL){//if deleted item has right child then push to s1 stack
			s1.push(temp->rchild);
		}
	}
	while(!s2.isempty()){//this will run until stack is not empty
		temp=s2.pop();
		cout << temp->data;//printing top data
	}
}

void myTree::nrec_preorder(tnode *temp){//preorder
	myStack <tnode*> s;//created a stack
	if(temp==NULL){//if temp is null then tree is empty
		cout << "\nTree is empty!" << endl;
		return;
	}
	while(temp!=NULL){
		cout << temp->data;//printing data of temp ptr
		s.push(temp);//pushing to stack s
		temp=temp->lchild;//traversing upto last left child
	}
	while(!s.isempty()){//this loop will run until stack is not empty
		temp = s.pop();//storing deleted item in temp
		temp=temp->rchild;//temp pointing to right child
		while(temp!=NULL){
			cout << temp->data;//printing data
			s.push(temp);//pushing temp to s
			temp=temp->lchild;//traversing to last left child of deleted item
		}
	}
}
myTree::~myTree() {
	// TODO Auto-generated destructor stub
}
