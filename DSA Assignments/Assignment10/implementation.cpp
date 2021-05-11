

#include <iostream>
using namespace std;
#include<fstream>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include "sf_h.h"

//method to read information from user
void file::input(string s)
{
    cout<<endl<<"Enter details : ";
	cout<<endl<<"Enter Roll number : ";
	cin>>roll;//reading roll from user
	validate(roll);
	cout<<"Enter Name : ";
	cin.ignore();
	gets(name);//reading name from user
	cout<<"Enter Division : ";
	cin>>division;//reading division from user
	cout<<"Enter Address : ";
	cin.ignore();
	gets(address);//reading address from user
	cout<<endl<<"Record has been "<<s<<"."<<endl;
}

//method to validate roll number
void file::validate(int i)
{
    if(i<=0 || i>1000)//if i is negative and i is greater than 100 then validate recursive call itself to read again roll no
    {
        cout <<endl<< "Invalid Roll number !"<< endl <<"Roll number should lie in between 1 to 1000." << endl << "Enter correct Roll number : ";
        cin >> i;//reading roll no from user
        validate(i);//recursive call
    }
}

//method to display information of user
void file::show(int i)
{
    cout<<i<<"\t"<<roll<<"\t\t"<<name<<"\t\t"<<division<<"\t\t"<<address;
	cout<<endl;
}

//method to get roll number
int file::getroll()
{
    return roll;//it will return rollno
}

//method to Create Data File
void Seq_File::Create()
{
    file fileobj;//creating obj of class file
    file modified;//creating another obj of class file
    fstream fil;//creating obj of fstream class

    char ch='y';
	fil.open("binary.dat",ios::out| ios::binary);//opening file to write in file of binary typee

	while(ch=='y' || ch =='Y')
	{
		fileobj.input("added");//calling to input fxn with string in parameters
	    fil.write((char*)&fileobj, sizeof(fileobj));//to write in file
		cout<<endl<<"Enter 'y' or 'Y' if you want to add another entry.Else enter any other alphabet.";
		cin>>ch;//the ch taken from user to add or not add the entry
	}

	fil.close();//close file
}

//method to Add New Record in Data File
void Seq_File::Add()
{
    file fileobj;//creating obj of class file
    file modified;//creating another obj of class file
    fstream fil;//creating obj of fstream class

    char ch='y';
	fil.open("binary.dat",ios::app| ios::binary);//opening file to append in file of binary typee

	while(ch=='y' || ch =='Y')
	{
	    fileobj.input("added");//calling to input fxn with string in parameters
		fil.write((char*)&fileobj, sizeof(fileobj));//to write in file
		cout<<endl<<"Enter 'y' or 'Y' if you want to add another entry.Else enter any other alphabet.";
		cin>>ch;//the ch taken from user to add or not add the entry
	}

	fil.close();//close file
}

//method to Display All Record from Data File
void Seq_File::Display()
{
    file fileobj;//creating obj of class file
    file modified;//creating another obj of class file
    fstream fil;//creating obj of fstream class

	fil.open("binary.dat",ios::in| ios::binary);//opening file to read file of binary typee

	if(!fil)
	{
		cout<<endl<<"File not Found";
		exit(0);//exit program
	}

	else
	{
	    fil.read((char*)&fileobj, sizeof(fileobj));//to read in file
	    int i=1;//initialize i to 1
	    cout<<"Sr.    \tRoll Number\tName\t\t\tDivision\tAddress"<<endl;
	    while(!fil.eof())//it will run till end of file
	    {
	        fileobj.show(i);//call to show fxn
	        fil.read((char*)&fileobj, sizeof(fileobj));//to read in file
	        i++;//incrementing i
	    }
	}

	fil.close();//close file
}

//method to search and Display particular Record from Data File
void Seq_File::Search_n_display()
{
    file fileobj;//creating obj of class file
    file modified;//creating another obj of class file
    fstream fil;//creating obj of fstream class

	int rollno;//initialize a variable
	cout<<endl<<"Enter the Roll Number whose record is to be searched : ";
	cin>>rollno;//reading roll no from user

	int check=0;
	fil.open("binary.dat",ios::in| ios::binary);//opening file to read file of binary typee

	if(!fil)
	{
	    cout<<endl<<"File not Found";
		exit(0);//exit the program
	}

	else
	{
	    fil.read((char*)&fileobj, sizeof(fileobj));//to read in file
	    while(!fil.eof())//it will run till end of file
		{
		    if(rollno==fileobj.getroll())
		    {
		        cout<<endl<<"Sr.    \tRoll Number\tName\t\t\tDivision\tAddress"<<endl;
		        fileobj.show(1);//calling to show fxn
		        check=1;//set check to 1
		    }

			fil.read((char*)&fileobj, sizeof(fileobj));//to read in file
	    }

	    if(check==0)
	    {
	        cout<<endl<<"Record not found in the database."<<endl;
	    }

	}


	fil.close();//file close
}

//method to Modify Particular Record from Data File
void Seq_File::Modify()
{
    file fileobj;//creating obj of class file
    file modified;//creating another obj of class file
    fstream fil;//creating obj of fstream class

	int rollno;//initialize a variable
	cout<<endl<<"Enter the Roll Number whose record is to be modified : ";
	cin>>rollno;//reading roll no from user

	int check=0;
	ofstream m;//creating object of fstream class
	fil.open("binary.dat",ios::in| ios::out|ios::binary);//opening a file in both read and write mode and type is binary
	m.open("new.dat",ios::out|ios::binary);//opening this file is write mode type is binary

	if(!fil)
	{
		 cout<<endl<<"File not Found";
		 exit(0);//exit the program
	}

	else
	{
	    fil.read((char*)&fileobj, sizeof(fileobj));//reading a file
		while(!fil.eof())
		{
		    if(rollno==fileobj.getroll())
		    {
		        check=1;
		    }

			if(rollno==fileobj.getroll())
			{
				cout<<endl<<"Enter modified record : "<<endl;
				modified.input("modified");//calling to input fxn
				m.write((char*)&modified, sizeof(modified));//write in "new.dat"
			}

			else
			{
			    m.write((char*)&fileobj, sizeof(fileobj));//write in "new.dat"
			}

		    fil.read((char*)&fileobj, sizeof(fileobj));//reading from the "binary.dat" file
		}

		if(check==0)
	    {
	        cout<<endl<<"Record not found in the database."<<endl;
	    }
	}

	m.close();//closing the "new.dat" file
	fil.close();//closing the "binary.dat" file
	remove("binary.dat");//removing "binary.dat" file
	rename("new.dat", "binary.dat");//renaming "new.dat" file to "binary.dat" file
}

//method to Delete Particular Record from Data File
void Seq_File::Delete()
{
    file fileobj;//creating obj of class file
    file modified;//creating another obj of class file
    fstream fil;//creating obj of fstream class

	int rollno;//initialize a variable
	cout<<endl<<"Enter the Roll Number whose record is to be deleted : ";
    cin>>rollno;//reading roll no from user

    int check=0;
	ofstream o;//creating object of ofstream
	o.open("new.dat",ios::out|ios::binary);//opeing of file in writing mode and type is binary
	fil.open("binary.dat",ios::in| ios::binary);//opening file in reading mode and type is binary

	if(!fil)
	{
	    cout<<endl<<"File not Found";
		exit(0);//exit the program
	}

	else
	{
	    fil.read((char*)&fileobj, sizeof(fileobj));//reading a file
		while(!fil.eof())//loop will run till end of file
		{
		    if(rollno==fileobj.getroll())
		    {
		        check=1;
		    }

			if(rollno!=fileobj.getroll())
			{
			    o.write((char*)&fileobj, sizeof(fileobj));//writing in "new.dat" file
			}

			fil.read((char*)&fileobj, sizeof(fileobj));//reading in "binary.dat" file
		}

		if(check==0)
	    {
	        cout<<endl<<"Record not found in the database."<<endl;
	    }

	    if(check!=0)
	    {
	        cout<<endl<<"Record has been deleted from the database."<<endl;
	    }
    }

	o.close();//closing "new.dat" file
	fil.close();//closing "binary.dat" file
	remove("binary.dat");//removing binary.dat file
	rename("new.dat", "binary.dat");//rename binary file "new.dat" to "binary.dat" file
}



