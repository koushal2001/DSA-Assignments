
#include<iostream>//header files
using namespace std;
#include "Queue1.h"
#define newline cout << "\n\t\t-----";

int main()
{
	Queue1 Qu1;//object
    int ch;//choice of user
    bool isemf;//check queue is empty or not
    do{
	cout<<"\n===================================================================================================";
    cout<<"\n\t Queue Operations :: \n\t 1.Insert \n\t 2.Delete \n\t 3.Isempty \n\t 4.Isfull \n\t 5.Display \n\t 6.Exit";
    cout<<"\n===================================================================================================\n";
    cin>>ch;//users choice
    switch(ch)
    {
    case 1://insert elements in queue
    {
    	newline
//    	Qu1.Q_display();//display existing queue
    	Qu1.Q_insert();//insert element
    	newline
    	Qu1.Q_display();//displaying after insertion
    	newline
    	break;
    }
    case 2://deletion
    {
//    	Qu1.Q_display();//displaying existing queue
    	newline
    	Qu1.Q_delete();//delete element
    	newline
    	Qu1.Q_display();//displaying after deletion
    	newline
    	break;
    }
    case 3://checks is queue empty or not
    {
    	isemf=Qu1.Q_isempty();
    	if(isemf == true){
    		cout <<"\n\t\t---Queue Empty!!---"<<endl;
    	}else
    		cout<<"\n\t\t---Queue is not empty---"<<endl;
    	break;
    }
    case 4://checks is queue full or not
    {
    	isemf=Qu1.Q_isfull();
    	if(isemf==true){
    	cout<<"\n\t\t---Queue full!!---"<<endl;
    	}else
    	cout<<"\n\t\t---Queue not full---"<<endl;
    	break;
    }
    case 5://display
    {
    	Qu1.Q_display();
    	break;
    }
    case 6://Exit
    {
    	int m;
    	cout <<"\n\t\tDo you want to exit?\n\t\t1. YES\n\t\t2. NO "<<endl;
    	cin >> m;
    	if (m==1)
    		return 0;
        else
    		break;
    }
    default:cout<<"\n\tInvalid choice !!";//default case
    }
    }while(1);//infinite loop
}
