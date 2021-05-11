
#ifndef SF_H_H_
#define SF_H_H_


#include<fstream>

class file
{
    private:

	int roll;
	char name[100];//char of arrays
	char division;
	char address[200];//char of array

    public:

    //method to read information from user
	void input(string s);

	//method to validate roll number
	void validate(int i);

	//method to display information of user
	void show(int i);

	//method to get roll number
	int getroll();
};

class Seq_File
{
    public:

    //method to Create Data File
    void Create();

    //method to Add New Record in Data File
    void Add();

    //method to Display All Record from Data File
    void Display();

    //method to search and Display particular Record from Data File
    void Search_n_display();

    //method to Modify Particular Record from Data File
    void Modify();

    //method to Delete Particular Record from Data File
    void Delete();
};


#endif /* SF_H_H_ */
