
#include <iostream>
#include "BST_Header.h"
#include "Stack_Header.h"
#include "Stack_Impl.cpp"
#include "queue_Header.h"
#include "queue_Impl.cpp"
using namespace std;

//Constructor.
template <class H>
BST<H>::BST()
{
	this->root = NULL;
}

//Method To Insert Node Using Recursion.
template <class H>
TNode<H>* BST<H>::insert(TNode<H>* node, H nev)
{
	if(node == NULL)
	{
		node = newTNode(nev);
		return node;
	}
	else if(nev == node->data)
	{
		//given x is already present...not allow
		cout<<"\n!!! Duplicate Not allowed !!!\n";
		return node;
	}
	else
	{
		if(nev < node->data)//If value is less thean go to left.
		{
			if(node->leftchild != NULL)
			{
				node->leftchild = insert(node->leftchild, nev);
			}
			else{	//If Node availaible then insert here.
				node->leftchild = newTNode(nev);;
			}
		}
		else//If value is greater thean go to right.
		{
			if(node->rightchild != NULL)
			{
				node->rightchild = insert(node->rightchild, nev);
			}
			else{	//If Node availaible then insert here.
				node->rightchild = newTNode(nev);;
			}
		}
	}
	return node;
}

//Method To Insert Node Without Using Recursion.
template <class H>
void BST<H>::insert_NR(H x)
{
	if(root == NULL){	//if root is null then create one.
		root = newTNode(x);
		return;
	}

	TNode<H> *p,*q;
	p = q = root;
	while(q != NULL && x != p->data)
	{
		//traverse until last node
		p = q;
		if(x < p->data)
		{
			//go to left side
			q=p->leftchild;
		}
		else if(x > p->data)
		{
			//right side
			q=p->rightchild;
		}
	}
	//after reaching node
	if(x==p->data)
	{
		//given x is already present...not allow
		cout<<"\n!!! Duplicate Not allowed !!!\n";
		return;
	}
	else if(x<p->data)
	{
		//link to left child
		p->leftchild=newTNode(x);
	}
	else
	{
		//link to right node
		p->rightchild=newTNode(x);
	}
}

//Method for Searching Without Using Recursion.
template<class H>
void BST<H>::search_NR(H x)
{
	TNode<H>* p = root;

	if(root == NULL){	//If root is null then no need to search.
		cout<<"\nTree is Empty\n";
		return;
	}

	while(p){
		if(x == p->data)	//If found then display.
		{
			cout<<"\n"<<x<<" is Found\n";
			return;
		}
		else if(x < p->data)	//If value is less then Traverse Left.
		{
			//go to left
			p = p->leftchild;
		}
		else	//If value is More then Traverse Right.
		{
			//go to right
			p = p->rightchild;
		}
	}
	cout<<"\n!!!"<<x<<" is Not Found !!!\n";	//If Not Found Display Not Found.
}

//Method for Searching Using Recursion.
template<class H>
TNode<H>* BST<H>::search(TNode<H>* temp,H x)
{
	TNode<H>* p = temp;

	if(p == NULL)
	{
		//reach to terminal ..so not found
		cout<<"\n!!! "<<x<<" is Not Found !!!\n";
		return p;
	}
	if(x < p->data)
	{
		//go to left
		p = search(p->leftchild, x);
	}
	else if(x > p->data)
	{
		//go to right
		p = search(p->rightchild, x);
	}
	else{
		cout<<"\n"<<x<<" is Found\n";
		return p;
	}
}

//Method for Mirror Using Recursion.
template<class H>
void BST<H> :: mirror(TNode<H>* temp)
{
	if(temp){
		TNode<H>* temp1 = temp->rightchild;
		temp->rightchild = temp->leftchild;  //swap child
		temp->leftchild = temp1;
		mirror(temp->leftchild); //go for same process of left child
		mirror(temp->rightchild); //go for same process of right child
	}
}

//Method for Mirror Without Using Recursion.
template<class H>
void BST<H> :: mirror_NR()
{
	if(root == NULL){
		cout<<"\n!!! Tree is Empty !!!\n";
		return;
	}

	queue<TNode<H>*> q; //create an empty queue for enqueue of all node

	TNode<H> *temp,*temp1;

	q.enqueue(root);  //initially enqueue root

	while(!q.isempty()){  //till all nodes are traversed
		temp = q.dequeue();  //dequeue each node and check below its child condn

		if(temp->leftchild == NULL && temp->rightchild==NULL){ //terminal node no need of exchange
			continue;
		}
		if(temp->leftchild!=NULL && temp->rightchild!=NULL){ //both child are present
			temp1 = temp->leftchild;
			temp->leftchild=temp->rightchild; //swap both child
			temp->rightchild=temp1;
			q.enqueue(temp->leftchild);
			q.enqueue(temp->rightchild); //then enqueue its child for further same process
		}
		else if(temp->leftchild==NULL){ //only right is present
			temp->leftchild=temp->rightchild;  //swap
			temp->rightchild=NULL;
			q.enqueue(temp->leftchild); //then enqueue its child for further same process
		}
		else{  //only left is present
			temp->rightchild=temp->leftchild; //swap
			temp->leftchild=NULL;
			q.enqueue(temp->rightchild);   //then enqueue its child for further same process
		}
	}
}

//Method for Calculating height of the BST Using Recursion.
template<class H>
int BST<H>::height(TNode<H>* temp)
{
	if(temp == NULL) //at terminal node or tree is empty
		return 0;
	else{
		return 1 + (max (height(temp->leftchild), height(temp->rightchild)));
	}
}

//Method for Calculating height of the BST Without Using Recursion.
template<class H>
int BST<H>::height_NR()
{
	if(root == NULL){
		return 0;
	}

	queue<TNode<H>*> q;  //create an empty queue for level order traversal
	q.enqueue(root);     //enqueue root

	int height = 0, nodecount = 0;
	TNode<H>* temp;

	while(1){
		nodecount=q.size();  //nodecount is no of nodes in a level

		if(nodecount == 0)      //if it is zero...then traversing is done ..return height
			return height;
		else height++;        //else increment height for that level

		while(nodecount>0){  //dequeue all elements of cuurent level and enque all next level nodes
			temp = q.dequeue();
			if(temp->leftchild!=NULL) //check for left child and enqueue it
				q.enqueue(temp->leftchild);
			if(temp->rightchild!=NULL)  //check for right child and enqueue it
				q.enqueue(temp->rightchild);
			nodecount--;
		}
	}
	return height; //return height
}

//Method for Level Order traversal.
template<class H>
void BST<H>::levelOrder()
{
	if(root == NULL){
		cout<<"\n!!! Tree is Empty !!!\n";
		return;
	}

	queue<TNode<H>*> q; //queue is created for inserting node of each level
	q.enqueue(root); //initially root is inserted
	TNode<H>* temp;
	int i = 1;
	while(!q.isempty()){ //traversed till que empty i.e.no nodes
		temp = q.dequeue(); //dequeue node and display it
		cout<<temp->data<<" ";

		//check for left or right child has or not and then enqueue it
		if(temp->leftchild!=NULL) {
			q.enqueue(temp->leftchild);
		}

		if(temp->rightchild!=NULL){
			q.enqueue(temp->rightchild);
		}
	}

}

//Method for Displaying Parent And Child Nodes.
template<class H>
void BST<H>::displayParentChild(){

	//Create an queue for node entry.
	queue<TNode<H>*> Q;
	Q.enqueue(root);

	cout<<"\n-------------------------------------";
	cout<<"\nParent \tLeft Child \tRight Child";
	cout<<"\n-------------------------------------"<<endl;
	while(!Q.isempty()){	//Loop until queue is empty.

		TNode<H>* node = Q.dequeue();	//dequeue the parent node.
		cout<<node->data<<"\t";
		if(node->leftchild != NULL){	//enqueue left child if present.
			Q.enqueue(node->leftchild);
			cout<<node->leftchild->data<<" ";
		}
		else{							//Display Node if No left Child.
			cout<<"None"<<" ";
		}
		if(node->rightchild != NULL){	//enqueue right child if present.
			Q.enqueue(node->rightchild);
			cout<<"\t\t"<<node->rightchild->data<<" ";
		}
		else{
			cout<<"\t\tNone"<<" ";		//Display Node if No Right Child.
		}
		cout<<"\n-------------------------------------"<<endl;
	}
}

//Method for Displaying Leaft Nodes.
template<class H>
void BST<H>::displayLeaf(){

	//Create an queue for node entry.
	queue<TNode<H>*> Q;
	Q.enqueue(root);

	cout<<"\n-------------------------------------";
	cout<<"\nLeaf Nodes : ";

	while(!Q.isempty()){	//Loop until queue is empty.
		TNode<H>* node = Q.dequeue();	//dequeue the parent node.

		if(node->leftchild == NULL && node->rightchild == NULL){	//Display data of Leaf Nodes.
			cout<<node->data<<" ";
			continue;
		}
		if(node->leftchild != NULL){	//enqueue left child if present.
			Q.enqueue(node->leftchild);
		}
		if(node->rightchild != NULL){	//enqueue right child if present.
			Q.enqueue(node->rightchild);
		}
	}
	cout<<endl;
}
//Method for deletion of an element(Recursive).
template<class H>
TNode<H>* BST<H>::deleteNode(TNode<H>* temp,H x){

	if(temp == NULL){
		cout<<"\nNode Is Not present"<<endl;
		return NULL;
	}
	TNode<H>* temp1;
	if(x < temp->data){
		temp->leftchild = deleteNode(temp->leftchild, x); //go to left
	}
	else if(x > temp->data){
		temp->rightchild = deleteNode(temp->rightchild, x);//go to right
	}

	//if element is found
	else if(temp->leftchild && temp->rightchild){ //if node have both child

		temp1 = minimumElement(temp->rightchild);  //then find min from its left subtree
		temp->data = temp1->data; //replace data of min with the node
		temp->rightchild = deleteNode(temp->rightchild, temp->data); //delete the node conatining temp1 in right subtree
	}

	else{
		temp1 = temp;
		if(temp1->leftchild == NULL) //left is null
			temp = temp->rightchild;
		if(temp != NULL && temp1->rightchild == NULL)//right is null
			temp = temp->leftchild;
		delete(temp1); //delete that node
	}

	return temp; //return parent
}

//Method to find Minimum Element.
template<class H>
TNode<H>* BST<H>::minimumElement(TNode<H>* temp){
	if(temp != NULL){
		if(temp->leftchild != NULL)
			return minimumElement(temp->leftchild);
		else return temp;
	}
	return NULL;
}

//Method To Traverse tree in InOrder using Recursion.
template <class H>
void BST<H>::inOrderTree(TNode<H>* currentNode)
{
	if(currentNode == NULL){return;}

	inOrderTree(currentNode->leftchild);
	cout<<currentNode->data<<" ";
	inOrderTree(currentNode->rightchild);
}

//Method To Traverse tree in PreOrder using Recursion.
template <class H>
void BST<H>::preOrderTree(TNode<H>* currentNode)
{
	if(currentNode == NULL){return;}

	cout<<currentNode->data<<" ";
	preOrderTree(currentNode->leftchild);
	preOrderTree(currentNode->rightchild);
}

//Method To Traverse tree in PostOrder using Recursion.
template <class H>
void BST<H>::postOrderTree(TNode<H>* currentNode)
{
	if(currentNode == NULL){return;}

	postOrderTree(currentNode->leftchild);
	postOrderTree(currentNode->rightchild);
	cout<<currentNode->data<<" ";
}

//Method To Traverse tree in inOrder.
template <class H>
void BST<H>::inOrderTree_NR(TNode<H>* currentNode)
{
	Stack_ll<TNode<H>*> iostack;	//Create stack to push elements.
	if(currentNode == NULL)	//if tree empty.
	{
		cout<<"Empty Tree"<<endl;
		return;
	}

	do{

		while(currentNode != NULL)	//Traverse all the left child.
		{
			iostack.push(currentNode);
			currentNode = currentNode->leftchild;
		}
		if(!iostack.isempty())	//if not empty then display data.
		{
			currentNode = iostack.pop();
			cout<<currentNode->data<<" ";
			currentNode = currentNode->rightchild;	//go to the right child.
		}

	}while(!iostack.isempty() || currentNode!=NULL);

}

//Method To Traverse tree in PreOrder.
template <class H>
void BST<H>::preOrderTree_NR(TNode<H>* currentNode)
{
	if(currentNode == NULL){return;}//if tree empty.

	Stack_ll<TNode<H>*> prestack;	//Create stack to push elements.
	prestack.push(currentNode);

	while(prestack.isempty() == false)
	{
		TNode<H>* node = prestack.pop();
		cout<<node->data<<" ";	//Display data.

		if(node->rightchild){prestack.push(node->rightchild);}//Push the right child.
		if(node->leftchild){prestack.push(node->leftchild);}//Push the left child.
	}
}

//Method To Traverse tree in PostOrder.
template <class H>
void BST<H>::postOrderTree_NR(TNode<H>* currentNode)
{
	Stack_ll<TNode<H>*> postack;	//Create stack to push elements.
	Stack_ll<int> flagstack;	//Create stack to push flags.
	int flag = 0;

	do{

		while(currentNode!=NULL && flag == 0)	//Traverse till element is present and flaf is zero.
		{
			postack.push(currentNode);	//Push the Element.
			flagstack.push(1);	//set flag to one.
			currentNode = currentNode->leftchild;
		}
		if(!postack.isempty())	//pop element if not empty.
		{
			currentNode = postack.pop();
			flag = flagstack.pop();

			if(flag == 1)	//If flag is true.
			{
				postack.push(currentNode);
				flagstack.push(2);
				currentNode = currentNode->rightchild;
				flag = 0;
			}
			else
			{
				cout<<currentNode->data<<" ";	//Display data.
			}
		}
	}while(!postack.isempty());
	return;
}

//Method To Return The Root Node.
template <class H>
TNode<H>* BST<H>::getRoot()
{
	return this->root;
}

//Method To Set Root Node.
template <class H>
void BST<H>::setRoot(TNode<H>* t)
{
	this->root = t;
}

//Destructor.
template <class H>
BST<H>::~BST(){
	free(root);
}

//Function To Create New Node.
template <class H>
TNode<H>* newTNode(H k)
{
	TNode<H>* temp = new TNode<H>;
	temp->leftchild = temp->rightchild = NULL;
	temp->data = k;
	return temp;
}

int main() {

	BST<int> b;		//Creating BST.
	TNode<int>* copy;	//Creating copy Node.

	int choice = -1;

	while(choice != 0){

		//User Guide.
		cout<<"\n*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^"<<endl;

		cout<<"Please Select One Of The Following Choices"<<endl;
		cout<<"1. Insert Data(Non-Recursive)"<<endl;
		cout<<"2. Insert Data(Recursive)"<<endl;
		cout<<"3. Search Data(Non-Recursive)"<<endl;
		cout<<"4. Search Data(Recursive)"<<endl;
		cout<<"5. Tree Traversals"<<endl;
		cout<<"6. Mirror Image(Non-Recursive)"<<endl;
		cout<<"7. Mirror Image(Recursive)"<<endl;
		cout<<"8. Height Of The Tree(Non-Recursive)"<<endl;
		cout<<"9. Height Of The Tree(Recursive)"<<endl;
		cout<<"10. Level Order Traversal"<<endl;
		cout<<"11. Delete An Element(Recursive)"<<endl;
		cout<<"12. Display All Parent With Their Child"<<endl;
		cout<<"13. Display Leaf Nodes"<<endl;
		cout<<"0. Exit"<<endl;

		cout<<"\n*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^"<<endl;

		cout<<"\nEnter You'r Choice : ";
		cin>>choice;

		cout<<"\n*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^"<<endl;

		switch(choice){
		case 1:{
			int data;
			cout<<"\nEnter The Data : ";
			cin>>data;
			b.insert_NR(data);
			break;
		}
		case 2:{
			int data;
			cout<<"\nEnter The Data : ";
			cin>>data;
			b.setRoot(b.insert(b.getRoot(), data));
			break;
		}
		case 3:{
			int data;
			cout<<"\nEnter The Data You Want To Search : ";
			cin>>data;
			b.search_NR(data);
			break;
		}
		case 4:{
			int data;
			cout<<"\nEnter The Data You Want To Search : ";
			cin>>data;
			b.search(b.getRoot(), data);
			break;
		}
		case 5:{
			if(b.getRoot() == NULL){
				cout<<"\n!!! Tree is Empty !!!\n";
			}
			else{
				cout<<"\n\n------------------Recursive------------------"<<endl;
				cout<<"  Inorder   = ";
				b.inOrderTree(b.getRoot());cout<<endl;
				cout<<"  Preorder  = ";
				b.preOrderTree(b.getRoot());cout<<endl;
				cout<<"  Postorder = ";
				b.postOrderTree(b.getRoot());cout<<endl;
				cout<<"---------------------------------------------"<<endl;
				cout<<"\n----------------Non Recursive----------------"<<endl;
				cout<<"  Inorder   = ";
				b.inOrderTree_NR(b.getRoot());cout<<endl;
				cout<<"  Preorder  = ";
				b.preOrderTree_NR(b.getRoot());cout<<endl;
				cout<<"  Postorder = ";
				b.postOrderTree_NR(b.getRoot());cout<<endl;
				cout<<"---------------------------------------------"<<endl;
			}
			break;
		}
		case 6:{
			b.mirror_NR();
			cout<<"\nMirror Image Created Successfully\n";
			break;
		}
		case 7:{
			if(b.getRoot() == NULL){
				cout<<"\n!!! Tree is Empty !!!\n";
			}
			else{
				b.mirror(b.getRoot());
				cout<<"\nMirror Image Created Successfully\n";
			}
			break;
		}
		case 8:{
			cout<<"\nHeight = "<<b.height_NR()<<"\n";
			break;
		}
		case 9:{
			cout<<"\nHeight = "<<b.height(b.getRoot())<<"\n";
			break;
		}
		case 10:{
			cout<<"\n-----------------------------------------------------------------\n"<<endl;
			cout<<"\n\nLevel order Traversal"<<endl;
			b.levelOrder();
			cout<<"\n-----------------------------------------------------------------\n"<<endl;
			break;
		}
		case 11:{
			if(b.getRoot() == NULL){
				cout<<"\n!!! Tree is Empty !!!\n";
			}
			else{
				int key;
				cout<<"\nEnter The Element You Want To Delete : ";
				cin>>key;
				b.deleteNode(b.getRoot(), key);
			}
			break;
		}
		case 12:{
			if(b.getRoot() == NULL){
				cout<<"\n!!! Tree is Empty !!!\n";
			}
			else{
				b.displayParentChild();
			}
			break;
		}
		case 13:{
			if(b.getRoot() == NULL){
				cout<<"\n!!! Tree is Empty !!!\n";
			}
			else{
				b.displayLeaf();
			}
			break;
		}
		case 0:{
			break;
		}
		default :{
			cout<<"\nPlease Select Among The Availaible Choice"<<endl;
		}

		}
	}

	cout << "\nProgram End" << endl; // prints Expression Tree
	return 0;
}


