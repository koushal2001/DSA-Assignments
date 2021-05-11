
#include <iostream>//header file
#include "kp_h.h"
using namespace std;

int main()
{
    cout<<endl<<"WELCOME TO THE COLLEGE NAVIGATION APPLICATION !!!";
    Graph g;
    int choice=0;//choice
    int create=0;

    int i=1;//initialize i to 1
    while(i>0)
    {
        cout<<endl<<endl<<"Enter your choice(0 to 3) : ";
        cout<<"\n1. Create map by inserting locations.\n2. Find the minimum distance using Prim's Algorithm.\n3. Find the minimum distance uisng Kruskal's Algorithm.";
        cout<<endl<<endl<<"Enter 0 to end the application."<<endl;
        cin>>choice;//choice from user

        switch(choice)//switch statement
        {
            case 0://exit
            {
                i=-1;
                cout<<endl<<"Thank You !\nYou have ended the application."<<endl;
                cout<<endl<<"-------------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
                break;
            }



            case 1://map creation
            {
                cout<<endl<<"Map Creation : "<<endl<<endl;
                g.creategraph();
                cout<<endl<<"The map has been created successfully."<<endl<<endl;
                create++;
                cout<<endl<<"-------------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;

                break;
            }

            case 2://prim's algorithm
            {
                if(create==0)
                {
                    cout<<endl<<"You first need to create a map for finding minimum distance uisng Prim's Algorithm"<<endl;
                }

                else
                {
                    cout<<endl<<"Prim's Algorithm :"<<endl;
                    g.prim();
                }
                cout<<endl<<"-------------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;

                break;
            }

            case 3://kruskals algorithm
            {
                if(create==0)
                {
                    cout<<endl<<"You first need to create a map for finding minimum distance uisng Kruskal's Algorithm"<<endl;
                }

                else
                {
                    cout<<endl<<"Kruskal's Algorithm : "<<endl<<endl;
                    g.kruskals();
                }
                cout<<endl<<endl<<"-------------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;

                break;
            }

            default://default case
            {
                cout<<endl<<"Invalid choice !\nEnter choice between 0 to 3."<<endl;
                cout<<endl<<"-------------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
            }
        }
        i++;//incrementing i
    }

    return 0;
}

