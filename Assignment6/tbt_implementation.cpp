



#include<iostream>//header file
#include "tbt_header.h"
using namespace std;

//constructor
template<typename T>//template used for generic programming
tbt<T>::tbt()
{
	head = new tbtnode<T>;//creating new node named as head
	head->lptr = head;//left ptr pointing to head
	head->rptr = head;//right ptr pointing to head
	head->data = -1;//initially set -1 in data part
	head->left_thread = 0;//initializing left thread to 0
	head->right_thread = 1;//initializing right thread to 1
}

//method to create root of TBT
template<typename T>//template used for generic programming
void tbt<T>::create_root()
{
    root = new tbtnode<T>;//creating new node named as root

	cout<<"\nEnter data to be inserted at root : ";
	cin>>root->data;//reading data from user

	head->lptr = root;//left pointer of head node points to root
	head->left_thread = 1;//left thread of head node is set to 1 i.e there is thread
	root->lptr = head;//left pointer of root node points to head
	root->rptr = head;//right pointer of root node points to head

	root->left_thread = 0;//left thread of root node is set to 0 i.e there is no thread
	root->right_thread = 0;//right thread of root node is set to 0 i.e there is no thread
}

//method to insert new node in TBT
template<typename T>//template used for generic programming
void tbt<T>::insert_node(T data)
{
    if (head->lptr == head)//if head's left ptr is pointing to itself then root is to be created
	{
		cout<<"A root is needed to be created."<<endl;
		return;
	}

	tbtnode<T>* temp1 = new tbtnode<T>;//new node name as temp1
	temp1->data = data;//putting data in data part
	temp1->left_thread = temp1->right_thread = 0;//initializing 0 to both left and right thread
	tbtnode<T>* temp2 = root;//declaring pointer temp2 pointing to root
	int choice1;

	int check1=1;

	do
	{
		cout << "\nThe current node is : ";
		cout << temp1->data;
		cout << "\nMenu : \n1. Add to left. \n2. Add right.\n";
		cin>>choice1;//choice from user
		switch(choice1)
		{
		    case 1://to add element in left
		    {
			    if(temp2->left_thread == 1)//if left thread of temp2 is 1 then
			    {
				    temp2 = temp2->lptr;//traverse temp2 till last left node is encountered
			    }
			    else
			    {
			    	//swapping
				    temp1->lptr = temp2->lptr;
				    temp2->lptr = temp1;
				    temp1->rptr = temp2;
				    temp2->left_thread = 1;//set 1 to the left thread of temp2
				    check1=0;//set check1 to 0
				    break;
			    }
			    break;
		    }

		    case 2://to add element in right
		    {
			    if(temp2->right_thread == 1)//if right thread of temp2 is 1 then
			    {
				    temp2 = temp2->rptr;//traverse temp2 till last right node is encountered
			    }
			    else
			    {
			    	//swapping
				    temp1->rptr = temp2->rptr;
				    temp2->rptr = temp1;
				    temp1->lptr = temp2;
				    temp2->right_thread = 1;//set 1 to the right thread of temp2
				    check1=0;//set check1 to 0
				    break;
			    }
			    break;
		    }

		    default://default case
			{
				cout << "\nEnter from above choices only.\n";
			}
		}
	}
	while(check1!=0);//this loop run until and unless check1 is 1


}

//method for inorder traversal of TBT
template<typename T>//template used for generic programming
void tbt<T>::inorder()
{
	tbtnode<T>* temp = head->lptr;//pointer pointing to left pointer of head

	while (temp != head)
	{
	    while(temp->left_thread != 0)//this loop will run until and unless left thread is 0
		{
			temp = temp->lptr;//traverse to left most node present in tree
		}

		while(temp->right_thread != 1)//this loop will run until and unless right thread is 0
		{
			cout<<temp->data<<" ";//printing value
			temp = temp->rptr;//move to rightmost child of left most node in tree
		}

		if(temp==head)
		{
			break;
		}

		cout<<temp->data<<" ";//printing data
		temp = temp->rptr;//move to right child
	}
}

//method for preorder traversal
template<typename T>//template used for generic programming
void tbt<T>::preorder()
{
	tbtnode<T>* temp = head->lptr;//pointer pointing to left pointer of head

	while (temp != head)
	{
		while(true)
		{
			cout<<temp->data<<" ";//printing data

			if(temp->left_thread == 0)//if left thread is 0 then loop will terminate
			{
				break;
			}

			else
			{
				temp = temp->lptr;//else move to left child
			}
		}

		while(temp->right_thread != 1)//this loop will run until and unless right thread is 0
		{
			temp = temp->rptr;//move to right child
		}

		temp = temp->rptr;//move to right child
	}
}

//method for postorder traversal of TBT
template<typename T>//template used for generic programming
void tbt<T>::postorder()
{
    tbtnode<T>* temp = head->lptr;//pointer pointing to left pointer of head
	temp->check = 0;//check part is initialized by 0

	while(temp!=head)//this loop will run until and unless temp equals to head
	{
		if(temp->left_thread == 1 && (temp->lptr->check!=2))
		{
			temp = temp->lptr;//move to left pointer
			temp->check = 0;//set check value to 0
		}

		if(temp->right_thread == 1 && (temp->rptr->check != 2))
		{
			temp = temp->rptr;//move to right pointer address
			temp->check = 1;//set check value to 1
		}

		cout<<temp->data<<" ";//print data

		if(temp->check == 0)//if check is equal to 0
		{
			temp->check= 2;//set check equal to 2
			while(temp->right_thread == 1)//this loop will run when right thread is 1
			{
				temp = temp->rptr;//move to right pointer address
			}

			temp = temp->rptr;//move to right pointer address
		}

		else
		{
			temp->check = 2;//set check equal to 2
			while(temp->left_thread == 1)//this loop will run when left thread is 1
			{
				temp = temp->lptr;//move to left pointer address
			}
			temp = temp->lptr;//move to left pointer address
		}
	}
	return;
}
