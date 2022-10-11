
#include "myTree.h"

#include <iostream>
using namespace std;



int main() {
	myTree T; //Tree object

	int ch, exp;	  //Choice
	do{
		cout << "\n===================================" << endl;
		cout << "\n1. Input"
				"\n2. Create"
				"\n3. Recursive Traversal"
				"\n4. Non-Recursive Traversal"
				"\n5. Exit";
		cout << "\n===================================" << endl;
		cout << "Enter choice:: ";
		cin >> ch;
		switch(ch){
		case 1://input
			cout << "\nSelect Input::"
					"\n1. Postfix"
					"\n2. Prefix " << endl;
			cout << "Enter choice:: ";
			cin >> exp;
			T.input();
			break;

		case 2://create
			if(exp==1)
				T.create();
			else if(exp==2)
				T.create_prefix();

			break;

		case 3://Recursive Traversal
			cout << "---Recursive Traversal---" << endl;
			cout << "Inorder Traversal::	";
			T.rec_inorder(T.retroot());
			cout << "\nPostorder Traversal::	";
			T.rec_postorder(T.retroot());
			cout << "\nPreorder Traversal::	";
			T.rec_preorder(T.retroot());
			break;

		case 4://Non Recursive Traversal
			cout << "---Non Recursive Traversal---" << endl;
			cout << "Inorder Traversal::	";
			T.nrec_inorder(T.retroot());
			cout << "\nPostorder Traversal::	";
			T.nrec_postorder(T.retroot());
			cout << "\nPreorder Traversal::	";
			T.nrec_preorder(T.retroot());
			break;

		case 5://Exit
			int z;
			cout << "\nDo you want to exit: "
					"\n1. Yes"
					"\n2. No" << endl;
			cin >> z;
			if(z==1)
				return 0;
			break;
		}
	}while(1);

	return 0;
}
