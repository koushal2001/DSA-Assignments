
#include "myStack.h"
#include "myStack.cpp"
#include <stack> //Stack stl header file
#include <queue> //Queue stl header file
#include <math.h>

#ifndef MYTREE_H_
#define MYTREE_H_

struct tnode{ 						//Node for tree
	char data; 						//Data in the tree node
	struct tnode *lchild, *rchild;	//Two components left and right

};
class myTree {
	string ip;		//Input Expression
	tnode *root;		//Root node

public:
	myTree();			//Constructor
	void input();		//Input function
	int isvalid();		//Check for valid input
	void create();		//Create the tree for postfix
	void create_prefix();//Create tree for prefix
	string reverse(string);
	void rec_inorder(tnode *temp);		//Recursive inorder
	void rec_preorder(tnode *temp);		//Recursive preorder
	void rec_postorder(tnode *temp);	//Recursive postorder
	void nrec_inorder(tnode *temp);		//Non recursive inorder
	void nrec_preorder(tnode *temp);	//Non recursive preorder
	void nrec_postorder(tnode *temp);	//Non recursive postorder
	void evaluate();					//Evaluating the expression
	tnode * retroot();					//Returning root
	virtual ~myTree();
};

#endif /* MYTREE_H_ */
