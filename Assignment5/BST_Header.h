
#ifndef BST_HEADER_H_
#define BST_HEADER_H_
#include <iostream>
using namespace std;

//Initializing Structure TNode.
template <class H>
struct TNode
{
public:
	//Data Members Of Node.
	H data;
	TNode<H>* leftchild;
	TNode<H>* rightchild;
};

//Initializing Class ExpressionTree.
template <class H>
class BST
{
private:
	TNode<H>* root;

public:
	//Constructor.
	BST();

	//BST insertion Methods.
	TNode<H>* insert(TNode<H>* node, H nev);		//Insert Using Recursion.
	void insert_NR(H x);							//Insert Without Using Recursion.

	//BST Methods for Searching an Element.
	TNode<H>* search(TNode<H>* temp, H k);			//Search Using Recursion.
	void search_NR(H x);							//Search Without Using Recursion.

	//BST Method for Mirror Image.
	void mirror(TNode<H>* temp);					//Mirror Using Recursion.
	void mirror_NR();								//Mirror Without Using Recursion.

	//BST Method for Height of BST.
	int height(TNode<H>* temp);						//Height Of BST Using Recursion.
	int height_NR();								//Height Of BST Without Using Recursion.

	//Level Order Traversal.
	void levelOrder();								//Level Order Traversal.

	//BST Method to Display Parent Node
	//Along With Child Node.
	void displayParentChild();						//Parent Child Display.

	//BST Method to Display Leaf Nodes.
	void displayLeaf();								//Leaf Node Display.

	//Deletion Of Node.
	TNode<H>* deleteNode(TNode<H>* temp, H x);		//Deletion of an Element(Recursive).
	void deleteItem(TNode<H>* tree, int item);		//Deletion of an Element(Non-Recursive).
	void deleteData(TNode<H>* tree);				//Deletion of an Element(Non-Recursive).

	//Minimum Element Among the Tree.
	TNode<H>* minimumElement(TNode<H>* temp);		//Minimum Element Among The Tree.

	//BST Traversals Using Recursion.
	void inOrderTree(TNode<H>* currentNode);		//Inorder traversal Using Recursion.
	void preOrderTree(TNode<H>* currentNode);		//Preorder traversal Using Recursion.
	void postOrderTree(TNode<H>* currentNode);		//Postorder traversal Using Recursion.

	//BST Traversals Without Using Recursion.
	void inOrderTree_NR(TNode<H>* currentNode);		//Inorder traversal Without Using Recursion.
	void preOrderTree_NR(TNode<H>* currentNode);	//Preorder traversal Without Using Recursion.
	void postOrderTree_NR(TNode<H>* currentNode);	//Postorder traversal Without Using Recursion.

	//Accessor And Mutator Methods For root.
	TNode<H>* getRoot();							//Accessor Method.
	void setRoot(TNode<H>* t);						//Mutator Method.

	//Destructor.
	~BST();
};

template <class H>
TNode<H>* newTNode(H k);

#endif /* BST_HEADER_H_ */


