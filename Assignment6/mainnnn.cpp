

#include<iostream>//header file
#include "tbt_header.h"
#include "tbt_implementation.cpp"
using namespace std;

int main()
{
    cout <<"TBT Assignment"<<endl;

    tbt<int> tree;//object of class tree
    int choice;//choice
    while(true){
    	cout << "\nMenu:\n\t0.Exit\n\t1. Create root.\n\t2. Inserion.\n\t3. Inorder.\n\t4. Postorder. \n\t5. Preorder."<<endl;
        cout << "Enter your choice : ";
        cin >> choice;//taking choice from user
        if(choice!=0){
            switch(choice){
                case 1://to create root
                    tree.create_root();//calling to create_root fxn
                    cout <<endl<<"The node has been created.";
                    break;

                case 2://to insert node
                    int data;
                    cout<<"\nEnter data to be inserted : ";
                    cin>>data;//reading data from user
                    tree.insert_node(data);//calling insert_node fxn
                    cout <<endl<<data<<" has been inserted in TBT."<<endl ;
                    break;

                case 3://inorder traversal
                    cout <<"Inorder Traversal: ";
                    tree.inorder();//calling to inorder fxn
                    break;

                case 4://postorder traversal
                    cout <<endl<<"Postorder Traversal: " ;
                    tree.postorder();//calling to postorder fxn
                    break;

                case 5://preorder traversal
                    cout <<endl<<"Preorder Traversal: ";
                    tree.preorder();//calling to preorder fxn
                    break;

                default:
                    cout<< "Select from the above options"<<endl;
                    break;

            }
        }
        else{//to exit program
            break;
        }
    }


}
