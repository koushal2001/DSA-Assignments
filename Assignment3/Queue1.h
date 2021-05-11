#include<bits/stdc++.h>//header file
using namespace std;
#ifndef QUEUE1_H_
#define QUEUE1_H_
struct dob   //structure dob
{
	int dd;//date
	int mm;//month
	int yyyy;//year
};
struct patient//structure patient
{
	int P_ID;
	string Name;
	dob d1;
	string symptoms;
	float weight;
};

class Queue1 {
	int front,rear;//initialize front and rear
	patient pat_list[20];//array of structure
public:
	Queue1();//intialize queue to empty queue
	//Function decleration
	void Q_insert();//insert
	patient Q_delete();//delete
	bool Q_isempty();//check if queue empty
	bool Q_isfull();//check if queue full
	void Q_display();//display
	patient pat_getdata();//get details
	virtual ~Queue1();
};

#endif /* QUEUE1_H_ */
