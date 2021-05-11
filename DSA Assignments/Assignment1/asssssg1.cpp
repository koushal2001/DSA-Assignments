#include<bits/stdc++.h> //header file
using namespace std;//used to remove the ambiguity and name collision
//number of students
#define n 100
//number of subjects
#define m 5
//Structure of information parameters of students
struct stud
{
	//all are public data members by default
	string name;
	int roll;       //4
	int mark[m];    //20
	int total;      //4
	float sgpa;     //4
	string address;
	string mob;

};

//class student
class student
{
	int num;//private data member
	//array of structure
	stud s[n];

public:
	student()   //constructor
			{
			   for(int i=0;i<n;i++)//loop which will run n times
			   {
				    s[i].roll=0;//intitializing rollno as 0

				    num=0;//initializing size to 0
	            }
	        }

//member functions
	int ret_size(){ return num;}//method to return size
	void input();//to take input
	void display();//list display
	void display_1(int x);//single display
	void bubble_roll();//method for sorting roll numbers
	void insertion_name();//methods for sorting names alphabetically
	void bubble_sgpa();//method to sort according to sgpa
	int partition (int l, int r);
	void quick_sgpa(int l,int r);
	void linear_roll();//method to search roll no
	void linear_sgpa();//method to search sgpa
	void binary_name();//method to search name
	void insertion_name1();//methods for sorting names alphabetically for binary search
};

//input method to take inputs from user
void student::input()
{
	cout<<"Enter number of students::";
    cin>>num;//input of total students record user want

		if(num<0 || num>100)//validation student should not be negative no and should not be greater than 100
		{
		cout<<"Please Enter valid no of students!!";
		cout<<"\n\n";//newline
		input();//function calling
		}
		else
		{
		cout<<"Enter Details of students!!";
		cout<<"\n\n";
		}

	//taking name with validations (name should not contain digits)
		cout<<"\n\n";//newline
	for(int i=0;i<num;i++)//loop running to size given by user
	{
		bool flag;//flag

		cout<<"Enter name of student("<<i+1<<")::";

		do
		{
			//initialized flag as true
			flag=true;
			do                        //do- while loop used to take input of name
			{
			  getline(cin,s[i].name);//if there will be anything in buffer it will not read that
			}while(s[i].name.length()==0);//read upto there is atleast one character



			//validations are that the name should not be repeated and
			//no repetition is allowed

			for(int j=0;j<i;j++)
			{

			 if(s[i].name==s[j].name)//validation of already name present or not
			{
			 cout<<"Name alredy taken!!Try another name::";
			// if any of the above is false set flag as false
			  flag=false;
			  break;
			}
			}

			//validation that name should not contain digits

			for(int j=0;j<(s[i].name).length();j++)
			{
				//while checking in a loop if a digit is encountered it will break loop
				//ask for another valid input name
				if(isdigit(s[i].name[j])==true)
				{

					cout<<"Name must not contain any digit,enter valid name::";
					//as soon as a digit is seen in name flag will set as false
					flag=false;
					break;

				}
			}
		}while(flag==false);


		//roll number with validation

		cout<<"Enter roll number of student("<<i+1<<")::";

		do
		{
			//initialized flag as true
			flag=true;
			cin>>s[i].roll;//taking roll nos from user
			if(s[i].roll<=0 || s[i].roll>100)//validation of roll no should not be negative and greater than 100
			{
				cout<<"Invalid roll number ,enter valid roll number ::";
				// if any of the above is false set flag as false
				flag=false;
		    }
			else
			{
			for(int j=0;j<i;j++)
			{
				//validations are that there is no name collision
				   if(s[i].roll==s[j].roll)
				  {
					cout<<"Rollno alredy taken!!Try another rollno::";
					// if any of the above is false set flag as false
					flag=false;
					break;

				  }
			}
			}
		}while(flag==false);


		//marks with validations
		for(int j=0;j<m;j++)
		{

			cout<<"Enter the marks of subject("<<j+1<<")::";
			do
			{
				flag=true;
				cin>>s[i].mark[j];//taking marks from user
				  if(s[i].mark[j]<0 || s[i].mark[j]>100)//validation (marks should not be less than 0 and not greater than 100
				 {
					cout<<"Invalid marks,enter again::";
					flag=false;
				 }
			}while(flag==false);
		}

		//total of all marks
		s[i].total=0;
		for(int j=0;j<m;j++)
		{
			s[i].total+=s[i].mark[j];
		}

		//sgpa
		s[i].sgpa=(s[i].total/m);
		s[i].sgpa=(s[i].sgpa/10);

		//address
		cout<<"Enter address::";
		cin>>s[i].address;//input taking from user

		//mobile number with validation
		cout<<"Enter 10 digit mobile number::";

		do
		{
			cin>>s[i].mob;//input taking from user
			flag=true;
			for(int j=0;j<i;j++)
			{
			//validations are that the roll number should not <0 and
			//no repetition is allowed
			 if(s[i].mob==s[j].mob)//validation of removing phone no collision
			 {
				cout<<"Phoneno alredy taken!!Try another Phoneno::";
			    // if any of the above is false set flag as false
				flag=false;
				break;

			 }
			}
			if(s[i].mob.length()!=10)//validation phone no should be 10 digits
			{
				cout<<"Enter 10 digit valid mobile no!!!";
				flag=false;
			}
			else
			{
		for(int k=0;k<s[i].mob.length();k++)
		{

			if(isalpha(s[i].mob[k]))//checking that there is any alphabet in mobile no
			{
				cout<<"Phoneno does not contain alphabets!!Enter valid mobile no:::";
				flag=false;
				break;//terminate loop)
			}
		}
			}
		}while(flag==false);//when flag becomes false it will again call do loop
		cout<<"\n";

	}

}

//list display method specially for sorting algorithms
void student::display()
{
	//template how the results will be displayed
	cout<<"\n Data base is ::";
	cout<<"\n==========================================================================================================================\n";
	cout<<"name\t\t\t";
	cout<<"roll\t";
	for(int j=0;j<m;j++)
	{
		cout<<"sub["<<j+1<<"]\t";
	}
	cout<<"total\t";
	cout<<"sgpa\t";
	cout<<"address\t\t\t";
	cout<<"mobile\t";
	cout<<"\n";
	for(int i=0;i<num;i++)
	{
		cout<<s[i].name<<"\t\t\t";
		cout<<s[i].roll<<"\t";
		for(int j=0;j<m;j++)
		{
			cout<<s[i].mark[j]<<"\t";
		}
		cout<<s[i].total<<"\t";
		cout<<s[i].sgpa<<"\t";
		cout<<s[i].address<<"\t\t\t";
		cout<<s[i].mob<<"\t";

		cout<<"\n";
		cout<<"\n==========================================================================================================================\n";
	}
}

//display one by one specially for search algorithm

void student::display_1(int i)
{
	//Template to display the data which you searched
	cout<<"\n=========================================================================================================================="<<"\n";

	cout<<"name\t\t\t";
	cout<<"roll\t";
	for(int j=0;j<m;j++)
	{
		cout<<"sub["<<j+1<<"]\t";
	}
	cout<<"total\t";
	cout<<"sgpa\t";
	cout<<"address\t\t\t";
	cout<<"mobile";
	cout<<"\n";

	cout<<s[i].name<<"\t\t\t";
	cout<<s[i].roll<<"\t";
	for(int j=0;j<m;j++)
	{
		cout<<s[i].mark[j]<<"\t";
	}
	cout<<s[i].total<<"\t";
	cout<<s[i].sgpa<<"\t";
	cout<<s[i].address<<"\t\t\t";
	cout<<s[i].mob<<"\t";
	cout<<"\n==========================================================================================================================\n";
	cout<<"\n";

}

//bubble sort for sorting roll numbers in ascending order
void student::bubble_roll()
{
	stud temp;
	//analysis variables
	int pass=0,comparison,total_comparison=0;
	cout<<"pass\t";
	for(int i=0;i<num;i++)
	{
		cout<<"roll("<<i+1<<")\t";
	}
	cout<<"comparison";
	cout<<"\n";
	//outer loop initialized at first index
	for(int i=0;i<num-1;i++)
	{
		comparison=0;
		//inner loop
		for(int j=0;j<num-1;j++)
		{
			//Comparing adjacent elements
			if(s[j].roll>s[j+1].roll)
			{

				//if preceding is greater than succeeding just swap those
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;

				comparison+=1;
				total_comparison+=1;
			}

		}
		//pass wise output display elements after every pass
		cout<<++pass<<"\t";
		for(int i=0;i<num;i++)
		{
			cout<<s[i].roll<<"\t";
		}
		cout<<"\t"<<comparison;
		cout<<"\n";
		//as soon as sorting is done ,break
		if(comparison==0)
			break;
	}
	cout<<"\n";
	//analysis for  bubble sort
	cout<<"Analysis of bubble sort::"<<endl;
	cout<<"Total number of passes::"<<pass<<endl;
	cout<<"Total number of comparisons::"<<total_comparison<<endl;
	cout<<"\n";
	cout<<"\n";
}



//insertion sorting  for name to be arranged in alphabetical order
void student::insertion_name()
{
	//analysis variables
	int pass=0,comparison,total_comparison=0;

	cout<<"pass\t";
	for(int i=0;i<num;i++)
	{
		cout<<"name("<<i+1<<")\t";
	}
	cout<<"comparison";
	cout<<"\n";

	stud value;
	//outer loop
	for(int i=1;i<num;i++)
	{
		//setting up the initial value

		value=s[i];
		//initializing j to i-1
		int j=i-1;
		comparison=0;
		//if j is >=0 and j th element is greater than j+1 th
		//j+1 th element is changed with j th and continues
		while(j>=0 and s[j].name>value.name)
		{
			s[j+1]=s[j];
			//j is further implemented by 1
			j=j-1;

			comparison+=1;
			total_comparison+=1;

		}
		//when while condition is false j+1 th is changed to value element
		s[j+1]=value;

		//pass wise output display
		cout<<++pass<<"\t";
		for(int i=0;i<num;i++)
		{
			cout<<s[i].name<<"\t";
		}
		cout<<comparison;
		cout<<"\n";

	}
	cout<<"\n";
	//analysis of insertion sort
	cout<<"Analysis of bubble sort::"<<endl;
	cout<<"Total number of passes::"<<pass<<endl;
	cout<<"Total number of comparisons::"<<total_comparison<<endl;
	cout<<"\n";
	cout<<"\n";
}

int student::partition (int l, int r)
{
	//analysis variables
	int pass=0,comparison=0;


    stud pivot=s[l];//set pivot value
    int i=l,j=h;//initializing i and j
    while(i<j)
    {
    	do
    	{
    		comparison+=1;//comparision incrementing
    		i++;
    	}while(s[i].sgpa<=pivot.sgpa);//this loop will found index of greater value than pivot value

    	do
    	{
    		comparison+=1;//comparision incrementing
    	    j++;
    	}while(s[j].sgpa>pivot.sgpa);//this loop will found index of smaller value than pivot value

    	if(i<j){
    		 stud temp1=s[j];//swapping
    		 s[j]=s[i];
    		 s[i]=temp1;
    	}

    }
    stud temp2=s[l];//swapping
       s[l]=s[j];
       s[j]=temp2;

    //pass wise output display elements after every pass
    cout<<++pass<<"\t";
    for(int i=0;i<num;i++)
    {
    	cout<<s[i].sgpa<<"\t";//printing sgpa
    }
    cout<<comparison;
    cout<<"\n";

    return (j);//value return this valus will be called to caller function
}

void student::quick_sgpa(int l,int r)
{
    if (l< r)//condition check
    {

        int pi = partition(l,r);//calling partision function

        quick_sgpa(l, pi);//calling sgpa function
        quick_sgpa(pi + 1, r);//calling sgpa function
    }
}

//linear search to search a student sgpa wise
void student::linear_roll()
{
	int rolll;
	cout<<"Enter roll number::";
	cin>>rolll;//taking from user
	//analysis variables
	int comparison=0,pass=0;
	cout<<"Pass\t";
	for(int i=0;i<num;i++)//this will run upto num which is size
	{
		cout<<"rollno("<<i+1<<")\t";
	}

	cout<<"Comparison\n";

	for(int i=0;i<num;i++)//this will run upto num
	{
		int flag=1;//intially flag set to 1
		cout<<++pass<<"\t";
		for(int i=0;i<num;i++)//this will run upto num
		{
		  cout<<s[i].roll<<"\t\t";
		}
		//if value is found its index is returned
		if(rolll==s[i].roll)
		{
			comparison+=1;//incrementing comparisions
			flag=0;//setting flag to 0
		}
      cout<<comparison<<"\n";
      if(flag==0)
      {
    	  display_1(i);//calling display function which give one by one value
      }
   	}

	cout<<"\n";
	//analysis of insertion sort
	cout<<"Analysis of linear search::"<<endl;
	cout<<"Total number of passes::"<<pass<<endl;
	cout<<"Total number of comparisons::"<<comparison<<endl;
	cout<<"\n";
	cout<<"\n";

	 if(comparison==0)//if there is no comparison print no records
	    {
		 cout<<"\n\n========================================================";
	    	cout<<"\n\n\tRecord not found!!!\n";
	    }


}


//linear search to search a student sgpa wise
void student::linear_sgpa()
{
	float sg;
	cout<<"Enter sgpa to be searched";
	cin>>sg;//taking from user
	int comparison=0,pass=0;
	cout<<"Pass\t";
	for(int i=0;i<num;i++)//loop will execute upto num
	{
		cout<<"sgpa("<<i+1<<")\t";
	}
	cout<<"Comparison\n";
	for(int i=0;i<num;i++)
	{
		int flag=1;
		cout<<++pass<<"\t";
		for(int i=0;i<num;i++)
		{
		 cout<<s[i].sgpa<<"\t";
		}
		//if value is found its index is returned
		if(sg==s[i].sgpa)
		{
			comparison++;//incrementing comparision
			flag=0;//setting flag to 0
			//display_1(i);
		}
		//++pass;
	cout<<comparison<<"\n";
	if(flag==0)//if flag=0
	{
		display_1(i);//call to display function which will print one by one
	}


	}
	cout<<"\n";
		//analysis of insertion sort
	cout<<"Analysis of linear search::"<<endl;
	cout<<"Total number of passes::"<<pass<<endl;
	cout<<"Total number of comparisons::"<<comparison<<endl;
	cout<<"\n";
	cout<<"\n";
	//cout<<"\nComparison=" <<comparison;
	//cout<<"\nPass=" <<pass;
    if(comparison==0)
    {
    	cout<<"\n\n========================================================";
    	cout<<"\n\n\tRecord not found!!!\n";
    }

}

void student::insertion_name1()//this sort is for binary search
{

	stud value;
	//outer loop
	for(int i=1;i<num;i++)//loop will run upto num
	{
		//setting up the initial value

		value=s[i];
		//initializing j to i-1
		int j=i-1;
		//if j is >=0 and j th element is greater than j+1 th
		//j+1 th element is changed with j th and continues
		while(j>=0 and s[j].name>value.name)
		{
			s[j+1]=s[j];
			//j is further implemented by 1
			j=j-1;
		}
		//when while condition is false j+1 th is changed to value element
		s[j+1]=value;

	}
}


//binary search method to search a student by its name
void student::binary_name() {
	    insertion_name1();//sorting names by alphabetically order by calling to insertion sort function
        int low, high;//intializing values
        int p=0;//temporary variable used to store the index where key is found
        low = 0;
        string key;
        cout<< "Enter the Key tobe search :: ";
        cin>>key;//taking input from user
        int comparision=0,pass=0;
        cout<<"Pass\t";
        for(int i=0;i<num;i++)//loop will execute upto num
        	cout<<"name("<<i+1<<")\t";
        high = num- 1;//initially setting high to size-1
        cout<<"Comparison\n";
        while (low <= high) {//this loop will run upto high is greater than low
        	cout<<++pass<<"\t";
        	for(int i=0;i<num;i++)
        	{
        		cout<<s[i].name<<"\t";
        	}
            int mid = (low + high)/2;//this will take mean of beg and end
             if (s[mid].name == key)
             {
            	 p=mid;//initializing p=mid
            	 cout<<comparision<<endl;
                 break;//if programs reached to this statement this will terminate the loop
            }

            else if (s[mid].name > key) {//if key is smaller it will go to  left portion
            	 comparision++;//incrementing comparision
                high = mid - 1;//setting high to mid-1
            }
            else if (s[mid].name < key) {//if key is bigger it will go to  right portion
            	 comparision++;//incrementing comparision
                low = mid + 1;//setting low to mid+1
            }
            //}
        cout<<comparision<<endl;
        }

        display_1(p);//calling display function

        cout<<"Analysis of linear search::"<<endl;
        cout<<"Total number of passes::"<<pass<<endl;
        cout<<"Total number of comparisons::"<<comparision<<endl;
        cout<<"\n";
        cout<<"\n";
    }

//main method
int main()
{
	//object of class student
	student S;
	//taking inputs
	S.input();
	int exit;
	do
	{
		//main menu
		cout<<"\n\n";
		cout<<"Enter choice to perform operations::\n";
		cout<<"Enter 1 to get a roll call list\n";//using bubble sort
		cout<<"Enter 2 to get alphabetical list of student\n";//using insertion sort
		cout<<"Enter 3 to get toper list\n";//using quicksort
		cout<<"Enter 4 to search a student roll number wise\n";//using linear search
		cout<<"Enter 5 to search student sgpa wise\n";//using linear search
		cout<<"Enter 6 to search student name wise\n";//using binary search
		cout<<"Enter 7 To EXIT";
		int choice;
		cin>>choice;
		//switch case
		switch(choice)
		{
			case 1://sorted roll list
				if(S.ret_size()!=0)
				{
				  S.bubble_roll();//calling roll call
				  cout<<"\nData is Sorted SuccessFully.";
				  cout<<"\n==========================================";
				  S.display();//calling display function
				}
				else
				{
				     cout<< "\n\tNothing to Sort.";
				     cout<<"\n\tEnter Student Data First.";
				     cout<<"\n\t==========================================";
				}
				break;
			case 2://sorted alphabetically
				if(S.ret_size()!=0)
				{
				  S.insertion_name();//alphabetical name display
				  S.display();//calling display function
				}
				else
				{
				 cout<< "\n\tNothing to Sort.";
				 cout<<"\n\tEnter Student Data First.";
				 cout<<"\n\t==========================================";
				}
				break;
			case 3:{//sorted as topper
				if(S.ret_size()!=0)
				{
				  cout<<"pass\t";
				for(int i=0;i<S.ret_size();i++)
				{
					cout<<"sgpa("<<i+1<<")\t";
				}
				  cout<<"comparison";

				  cout<<"\n";
				  S.quick_sgpa(0,S.ret_size()-1);//toper list
				  S.display();//calling display function
				}
				else
				{
					cout<< "\n\tNothing to Sort.";
				    cout<<"\n\tEnter Student Data First.";
				    cout<<"\n\t==========================================";

				}
				break;
			}
			case 4://search roll no
			{
			  if(S.ret_size()!=0)
				S.linear_roll();
			  else
			 {
				  cout<< "\n\tNothing to Search.";
				  cout<<"\n\tEnter Student Data First.";
				  cout<<"\n\t==========================================";
			 }
             break;
			}
			case 5://search sgpa
			{
				if(S.ret_size()!=0)
				  S.linear_sgpa();//sgpa search
				else
				{
					cout<< "\n\tNothing to Search.";
					cout<<"\n\tEnter Student Data First.";
				    cout<<"\n\t==========================================";
				}
				break;


			}
			case 6://search name
			{
				if(S.ret_size()!=0)
				  S.binary_name();
				else
				{
					cout<< "\n\tNothing to Search.";
				    cout<<"\n\tEnter Student Data First.";
					cout<<"\n\t==========================================";
				}
				break;
			}
			 case 7://to exit the program
			 {
				 cout<<"\n\t Are you sure you want to exit the program   \n\t 1. Yes \n\t 2. No ";
			         cin>>exit;
			         if(exit==1)
			         {
			            return 0;
			         }
			         break;
			 }
			 default : cout<<"\n\t Invalid  option !! Please enter the valid  option !!";
		}


	}while(1);

}
