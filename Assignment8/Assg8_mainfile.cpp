
#include <iostream>//header file
#include "d_h.h"
using namespace std;

int main()
{
    cout<<endl<<"WELCOME TO THE PUNE CITY NAVIGATION APPLICATION !!!";
    Graph g;
    int choice=0;//choice
    int create=0;

    int i=1;//initialize i to 1
    while(i>0)//for positive i
    {
        cout<<endl<<endl<<"Enter your choice(0 to 2) : ";
        cout<<"\n1. Create map by inserting locations.\n2. Find the shortest distance uisng Dijkstra's Algorithm.";
        cout<<endl<<endl<<"Enter 0 to end the application."<<endl;
        cin>>choice;//choice taken by user

        switch(choice)//switch case
        {
            case 0://exit the program
            {
                i=-1;
                cout<<endl<<"Thank You !\nYou have ended the appliaction."<<endl;
                cout<<endl<<"-------------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
                break;
            }

            case 1://map creation
            {
                cout<<endl<<"Map Creation : "<<endl<<endl;
                g.creategraph();//calling to creategraph
                cout<<endl<<"The map has been created successfully."<<endl<<endl;
                create++;//incrementing create
                cout<<endl<<"-------------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;

                break;
            }

            case 2://Dijikstras Algorithm
            {
                if(create==0)
                {
                    cout<<endl<<"You first need to create a map for finding shortest distance uisng Dijkstra's Algorithm"<<endl;
                }

                else
                {
                    cout<<endl<<endl<<"Dijkstra's Algorithm : "<<endl;
                    g.dijktras();//calling to dijktras fxn
                }
                cout<<endl<<"-------------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;

                break;
            }

            default:
            {
                cout<<endl<<"Invalid choice !\nEnter choice between 0 to 2."<<endl;
                cout<<endl<<"-------------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
            }
        }
        i++;
    }

    return 0;
}



