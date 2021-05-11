#include "Queue1.h"
#include<bits/stdc++.h>  // header file
#define tmp 50     //macros
using namespace std;
Queue1::Queue1() {
	// TODO Auto-generated constructor stub
	front=-1;rear=-1;
}
bool Queue1::Q_isempty()  //is empty condition checking
{
	if(front==-1 || front==rear)//Queue empty when no insertion takes place or all elements are deleted
		return true;//returns when value is true
    return false;//returns when value is false
}
bool Queue1::Q_isfull()// checks if queue is full
{
	if ((front == 0 && rear == size-1) || (rear == (front-1)%(tmp-1)))
		return true; //it returns if value is true
	return false; //it returns if value is false
}
int a[tmp];//created a array to store ids for validation of not occuring  same id
  int count1=0;//counter variable

patient Queue1::pat_getdata()   //getting patient details
{
	patient pat1;//structure object
	Queue1 obj;//object creation
	cout<<"\n\t Enter the Patient Details";
	bool f;//flag variable
	do
	{
		f=true;//set f is true
	cout<<"\n\t\tPatient ID::";
	cin >> pat1.P_ID;//input taken from user
	if(pat1.P_ID<=0)
	        {
	        	cout<<"Invalid ID!!Please try again";
	        	f=false;//set f to false

	        }
	count1++;//increment counter
	a[count1-1]=pat1.P_ID;//storing id in array
	if(f==true)
	{
	for(int i=0;i<count1-1;i++)
	{
		if(count1>=2&&pat1.P_ID==a[i])
		{
			cout<<"ID already taken!!Try another ID::";
			f=false;//set f to false
			break;//flow come out of loop
		}
	}
	}
	}while(f==false);
	bool flag;
	do
	{
	cout<<"\n\t\tPatient name::";
	cin>>pat1.Name;//name taken from user
	for(int i=0;i<(pat1.Name).length();i++)//validation name does not contain name
	{
		flag=true;
		if(isdigit(pat1.Name[i])==true)
		{
			cout<<"\n\nName must not contain any digit,enter valid name::\n\n";
			//as soon as a digit is seen in name flag will set as false
			flag=false;
			break;

		}
	}
	}while(flag==false);
	do
	{
	cout<<"\n\t\tEnter the symptoms::";
	cin>>pat1.symptoms;//symptoms taken from user
	for(int i=0;i<(pat1.symptoms).length();i++)//validation symptoms does not contain no
		{
			flag=true;
			if(isdigit(pat1.symptoms[i])==true)
			{
				cout<<"\n\nSymptoms must not contain any digit,enter valid Symptoms::\n\n";
				//as soon as a digit is seen in symptoms flag will set as false
				flag=false;
				break;

			}
		}

	}while(flag==false);
	do{									// validation of Patient weight greater than 0
		cout << "\n\t\tWeight::";
		cin >> pat1.weight;

		if(pat1.weight > 0&&pat1.weight<200){
			break;
		}else
			cout << "\n\t\t---Wrong Weight entered!!---" << endl;
	}while(1);

	cout << "\n\t\tEnter birth details::";	//Taking birth details using nested structure

	do{										//Validating date from nested structure
		cout << "\n\t\tdd:: ";
		cin >> pat1.d1.dd;

		if((pat1.d1.dd > 0) && (pat1.d1.dd <=31) ){	//0 < date <= 31
			break;
		}else
			cout << "\n\t\t---Wrong date entered!!---" << endl;
	}while(1);

	do{													//Month Validations
			cout << "\n\t\tmm:: ";
			cin >> pat1.d1.mm;

			if((pat1.d1.mm > 0) && (pat1.d1.mm <=12) ){ //0< month <= 12
				break;
			}else
				cout << "\n\t\t---Wrong month entered!!---" << endl;
	}while(1);

	do{													//Year validations
		cout << "\n\t\tyyyy:: ";
		cin >> pat1.d1.yyyy;

		if((pat1.d1.yyyy > 1900) && (pat1.d1.yyyy <=2020) ){ //1900< year <2020
			break;
		}else
			cout << "\n\t\t---Wrong year entered!!---" << endl;
	}while(1);

	return pat1;
}
void Queue1::Q_insert() //Inserting in a queue
{
	patient pat;   //structure obj
	if(!Q_isfull()) //condition checking if queue is full
	{
		rear=(rear+1); //Increment rear
		pat=pat_getdata(); // calling to getdata fxn to get details
		pat_list[rear]=pat;//store in array of structure
	}
	else//else queue is full
	{
		cout<<"\n\t Sorry Queue is full!!!!";
	}
}

patient Queue1::Q_delete(){//deleting element in queue
	patient pat;//structure obj
	if(!(Q_isempty()))//checking queue is empty
	{
		pat =pat_list[front];//store in struct variable
		front =(front+1);//incrementing front deleting the previous value
	}
	else//else print queue is empty
	{
		cout<<"\n\t Sorry !!!Queue is empty";
	}
	return pat; //returning pat
}
void Queue1::Q_display(){//displaying the queue
	int i;
	if(Q_isempty())//if queue is empty
	{
		cout<<"\n\tQueue is empty!!";
		cout<<"\n\n\t front==>"<<front;
			cout<<"\n\n\tRear==>"<<rear;
	}
	else
	{
	cout<<"\n Queue is::\n";
	cout<<"\n=================================================================";

	cout<<"\n\tPatient id :: ";
	for(i=front;i!=rear;i++)
	{
		cout<<" | "<<pat_list[i].P_ID<<" | ";
	}
	cout<<" | "<<pat_list[rear].P_ID<<" | ";
	cout<<"\n\t\tfront==>"<<front;//printing front value
	cout<<"\n\t\tRear==>"<<rear;//printing rear value
	cout<<"\n=================================================================\n\n";
	}
}
Queue1::~Queue1() {
	// TODO Auto-generated destructor stub
}
