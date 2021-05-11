

#ifndef TBT
#define TBT

template<typename T>//template used for generic programming
class tbtnode//node class
{
public:
	//five parts of a node
	T data;//data block
	tbtnode<T>* lptr;//left ptr
	tbtnode<T>*rptr;//right ptr
	int left_thread, right_thread;//left and right thrfead
	int check=0;
};

template<typename T>//template used for generic programming
class tbt//tbt class
{
public:
    tbtnode<T>* head;
	tbtnode<T>* root=NULL;

	//constructor
	tbt();

	//method to create root
	void create_root();

	//method to insert new node
	void insert_node(T);

	//method for inorder traversal
	void inorder();

	//method for preorder traversal of TBT
	void preorder();

	//method for postorder traversal of TBT
	void postorder();
};
#endif // TBT_H_
