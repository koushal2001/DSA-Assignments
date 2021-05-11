
#include <iostream>
using namespace std;
#include<fstream>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include "sf_h.h"

int
main ()
{
    cout << endl << "WELCOME TO THE STUDENT DATABASE !!!" << endl;
    Seq_File sf;//class object
    int create=0;
    int opt;//choice
    while (1)
    {
        cout << "Enter your choice(0 to 6) to perform following operations : "<< endl;
        cout << "1. Create Data File." << endl;
        cout << "2. Add New Records in Data File." << endl;
        cout << "3. Display All Records From Data File." << endl;
        cout << "4. Search and Display Particular Record From Data File." << endl;
        cout << "5. Modify Paricular Record From Data File." << endl;
        cout << "6. Delete Particular Record From Data File." << endl;
        cout << "Enter 0 to exit." << endl;
        cin >> opt;//choice taken by user

        switch (opt)//switch statement
	    {
	        case 0://exit program
            {
                cout<<endl<<"Thank You !\nYou have ended the appliaction."<<endl;
                cout<<endl<<"-------------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
                exit(0);
            }

	        case 1://creating data file
	        {
	            sf.Create();//calling to create fxn
	            create=1;
	            cout<<endl<<"-------------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
	            break;
	        }

	        case 2://add new records
	        {
	            if(create==0)
	            {
	                cout<<endl<<"You need to first create data file to add new record to it."<<endl;
	            }

	            else
	            {
	                sf.Add();//calling to add fxn
	            }

	            cout<<endl<<"-------------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;

	            break;
	        }

	        case 3://display
	        {
	            if(create==0)
	            {
	                cout<<endl<<"You need to first create data file to display records from it."<<endl;
	            }

	            else
	            {
	                cout<<endl;
	                sf.Display();//calling to display fxn
	            }

	            cout<<endl<<"-------------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
	            break;
	        }

	        case 4://search and display particular record
	        {
	            if(create==0)
	            {
	                cout<<endl<<"You need to first create data file to search any record from it."<<endl;
	            }

	            else
	            {
	                sf.Search_n_display();//calling to search and display
	            }

	            cout<<endl<<"-------------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
	            break;
	        }

	        case 5://modify particular record
	        {
	            if(create==0)
	            {
	                cout<<endl<<"You need to first create data file to modify any record from it."<<endl;
	            }

	            else
	            {
	                sf.Modify();//calling to Modify fxn
	            }

	            cout<<endl<<"-------------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
	            break;
	        }

	        case 6://delete particular record
	        {
	            if(create==0)
	            {
	                cout<<endl<<"You need to first create data file to delete any record from it."<<endl;
	            }

	            else
	            {
	                sf.Delete();//caling to Delete fxn
	            }

	            cout<<endl<<"-------------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
	            break;
	        }

	        default://default case
	        {
	            cout << endl << "Invalid choice !\nEnter choice between 0 to 6."<< endl;
	            cout<<endl<<"-------------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
	        }
	    }
    }
}



