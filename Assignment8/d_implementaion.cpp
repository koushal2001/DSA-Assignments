#include <iostream>
#include "d_h.h"
using namespace std;

//constructor
Graph::Graph()
{
	v=10;//initially set vertices to 10
	e=10;//initially set edges to 10
	for(int i=0;i<v;i++)//loop will run till last v
	{
		for(int j=0;j<v;j++)//loop will run till last v i.e TC will be V^2
		{
			weight[i][j]=0;//setting (i,j) of weight matrix to 0
		}
	}
}

//method to create graph
void Graph::creategraph()
{
	int i,a,b,w;//declaring variables

	cout<<"Enter number of landmarks : ";
	cin>>v;//no of vertices taken from user
	validate(v,"number of landmarks");//calling validate fxn for validation

	cout<<endl<<"Enter number of paths : ";
	cin>>e;//no of edges taken from user
	validate(e,"number of paths");//calling validate fxn for validation

	cout<<endl<<"Enter the details of landmarks : "<<endl;
	for ( i=0;i<v;i++)//loop will run till last v
	{
	    cout<<endl<<"Enter the name of landmark : ";
	    cin.ignore();
	    getline(cin,edge[i].s);//reading name of edge from user
	    cout<<"Enter the number of landmark : ";
	    cin>>edge[i].no;//reading no of spots from user
	}

	for ( i=0;i<v;i++)
	{
	    p[i] = visited[i] =0;//setting all elements of p and visited array to 0
	    d[i] = 5000;//setting all elements of d array to 5000
	}

	cout<<endl<<"Enter the details of paths : "<<endl;
	for (i=0;i<e;i++)//loop will run till e
	{
	    cout<<"Enter source landmark number,destination landmark number and path distance between them : ";
		cin>>a>>b>>w;//reading starting spot  ending spot and distance  from user
		weight[a][b]=w;//set w to (a,b) position in 2d matrix
		edge[i].U=a;
		edge[i].V=b;
		edge[i].s1=edge[edge[i].U].s;
		edge[i].s2=edge[edge[i].V].s;
		edge[i].wt=w;
	}

    cout<<endl<<"Matrix of distances is as follows :"<<endl;

	cout<<"\t\t";
    for (i=0;i<v;i++)
	{
	    cout<<edge[i].s<<"\t";//printing name of all edges
	}
    cout<<endl<<endl;

	for (i=0;i<v;i++)
	{
	    cout<<"\t";
	    cout<<edge[i].s<<"\t";//printing name of all edges
		for (int j=0;j<v;j++)
		{
			cout<<weight[i][j]<<"\t";//printing all elements of weight matrix
		}
        cout<<endl;
	}
}

//method to validate number of vertices and edges
void Graph::validate(int i,string s)
{
    if (i<=0)//this will run only when i is equal or less than 0
    {
        cout <<endl<< "Invalid "<<s<<" !"<< endl << s<<" should be a positive integer." << endl << "Enter correct "<<s<<" : " << endl;
        cin >> i;//taken from user
        validate(i,s);//calling to validate fxn
    }
}

//method to find minimum weight using Dijktra's algorithm
void Graph::dijktras()
{
    int i,j,k,u,min,current;//declaring variables
    string s_name;//declaring a string s_name
    int s_no;//declaring a variable s_no
    cout<<endl<<"Enter source landmark name : ";
    cin>>s_name;//source name taken from user
    cout<<endl<<"Enter source landmark number : ";
    cin>>s_no;//source no taken from user

    for (i=0;i<v;i++)//loop will run upto i reaches to v
	{
	    visited[i] =0;//set all elements of visited array to 0

	    if(weight[s_no][i]!=0)
	    {
		    d[i] = weight[s_no][i];//assign weight(s_no,i) to d of i
	    }

	    else
	    {
	        d[i] = 32767;//else set d of i to any random max no
	    }
	    p[i]=s_no;//set p of i to s_no
	}

    current=s_no;//assign s_no to current
    visited[current]=1;//set 1 to visited of current location
    d[s_no]=0;//set 0 to d of s_no location

    cout<<endl<<"The visited distance and path status is : ";

	for (i=0;i<v;i++)//loop will run upto i reaches to v
	{
	    cout<<endl<<"For landmark : "<<edge[i].s;//printing landmark
	  	cout<<";  Visited : "<<visited[i];//printing visited
	  	cout<<";  Path : "<<p[i];//printing path
	  	cout<<";  Distance : "<<d[i];//printing distance
	}

    for(i=0;i<v-2;i++)
    {
	    min=32767;//set min to 32767
	    for(j=0;j<v;j++)//loop will run till v
	    {
		    if (min>d[j] && visited[j]==0)//if min is greater than d of j and visited of j is 0 then
		    {
			    min=d[j];//assign d of j to min
			    current=j;//assign j to current
		    }
	    }
	    cout<<endl<<endl<<"Selected landmark number is : "<<current;//printing landmark no
	    cout<<endl<<"Minimum is : "<<min;//printing min

	    visited[current]=1;//set visited of current to 1
	    for(k=0;k<v;k++)//run loop to v
	    {
		    if(visited[k]==0 && (d[current]+weight[current][k])<d[k])
		    {
			    if(weight[current][k]!=0)
			    {
				    d[k]=d[current]+weight[current][k];
			        p[k]=current;//assign current to p of k
			    }
		    }
	    }

	    cout<<endl<<endl<<"The visited distance and path status is : ";

	    for (int m=0;m<v;m++)//run loop to v
	    {
	        cout<<endl<<"For landmark : "<<edge[m].s;//printing landmark
	  	    cout<<";  Visited : "<<visited[m];//printing visited
	  	    cout<<";  Path : "<<p[m];//printing path
	  	    cout<<";  Distance : "<<d[m];//printing distance
	    }

    }

    cout<<endl<<endl<<endl<<"The Shortest Path from Source to all destinations in terms of landmark name : ";
    cout<<endl<<"Source name is : "<<s_name<<endl;//printing source name
    for(i=0;i<v;i++)//loop will run upto v
    {
	    if(i!=0)//if i is not equal to 0 then inner statements will execute
	    {
		    cout<<endl<<"Destination Landmark name : "<<edge[i].s<<";   Distance : "<<d[i];//printing landmark name and distance
		    cout<<";   Path : "<<edge[i].s;//printing path
		    j=i;

		    do
		    {
			    j=p[j];//asssign p of j to j
			    cout<<" <- "<<edge[j].s;//printing j landmark name
		    }
		    while(j!=0);
	    }
    }

    cout<<endl<<endl;
}


