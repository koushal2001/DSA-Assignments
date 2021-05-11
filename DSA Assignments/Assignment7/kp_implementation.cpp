

#include <iostream>//header file
#include "kp_h.h"
using namespace std;

//constructor
Graph::Graph()
{
	v=10;//initially set vertices to 10
	e=10;//initially set edges to 10
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			weight[i][j]=0;//setting all elements in weight matrix to 0
		}
	}
}

//method to create graph
void Graph::creategraph()
{
	int i,a,b,w;//variables

	cout<<"Enter number of spots : ";
	cin>>v;//no of vertices taken from user
	validate(v,"number of spots");//calling validate fxn for validation
	cout<<endl<<"Enter number of paths : ";
	cin>>e;//no of edges taken from user
	validate(e,"number of edges");//calling validate fxn for validation

	cout<<endl<<"Enter the details of spots : "<<endl;
	for ( i=0;i<v;i++)
	{
	    cout<<endl<<"Enter the name of spot : ";
	    cin.ignore();
	    getline(cin,edge[i].s);//reading name of edge from user
	    cout<<"Enter the number of spot : ";
	    cin>>edge[i].no;//reading no of spots from user
	}

	for ( i=0;i<v;i++)
	{
	    p[i] = visited[i] =0;//setting all elements of p and visited array to 0
	    d[i] = 5000;//setting d array to 5000
	}

	cout<<endl<<"Enter the details of paths : "<<endl;
	for (i=0;i<e;i++)
	{
	    cout<<"Enter starting spot number,ending spot number and path distance between them : ";
		cin>>a>>b>>w;//reading starting spot  ending spot and distance  from user
		weight[a][b]=w;//set w to (a,b) position in 2d matrix
		edge[i].U=a;
		edge[i].V=b;
		edge[i].s1=edge[edge[i].U].s;
		edge[i].s2=edge[edge[i].V].s;
		edge[i].wt=w;
		weight[b][a]=w;//set w to (b,a) position in 2d matrix
	}

    cout<<endl<<"Matrix of distances is as follows :"<<endl<<endl;

    cout<<"\t\t";
    for (i=0;i<v;i++)
	{
	    cout<<edge[i].s<<"\t";//printing name of all edges
	}
    cout<<endl<<endl;

	for (i=0;i<v;i++)
	{
	    cout<<"\t";
	    cout<<edge[i].s<<"\t";//printing name of all edge from user
		for (int j=0;j<v;j++)
		{
			cout<<weight[i][j]<<"\t";//printing all elements of weight matrix
		}
        cout<<endl;
	}
}

//method to sort the vertices of graph
void Graph::sortg()
{
	int i,j;//variables
    Edge temp;

	for(i=0;i<e-1;i++)//run loop to e-1
	{
	    for(j=0;j<e-1;j++)//run loop to e-1, T.C=e^2
		{
		    if(edge[j].wt>edge[j+1].wt)
			{
		    	//swapping
				temp=edge[j+1];
				edge[j+1]=edge[j];
	            edge[j]=temp;
			}
		}
	}

	cout<<endl<<"Sorted List of distances :"<<endl;
	for(int i=0;i<e;i++)//loop run to end of edges
	{
	    cout<<edge[i].s1<<", "<<edge[i].s2<<", "<<edge[i].wt<<endl;
	}
}

//method to validate number of vertices and edges
void Graph::validate(int i,string s)
{
    if (i<=0)
    {
        cout <<endl<< "Invalid "<<s<<" !"<< endl << s<<" should be a positive integer." << endl << "Enter correct "<<s<<" : " << endl;
        cin >> i;
        validate(i,s);//recursive call to validate fxn
    }
}

//method to find minimum weight using Kruskal's algorithm
void Graph::kruskals()
{
	int i,j;//variables
	cout<<endl<<"The details you entered in the form of starting spot number,ending spot number and path distance between them are as follows : :"<<endl;

	for (i=0;i<e;i++)//run loop to end of edges
	{
		cout<<edge[i].s1<<", "<<edge[i].s2<<", "<<edge[i].wt<<endl;
	}

	sortg();//calling to sortg fxn

	///initialization
	Edge t[15];
	int conn[10],k,r,p,Val,cnt=0;

	for (i=0;i<e;i++)
	{
		conn[i]=0;//setting 0 to all elements of conn array
	}

	Val=1;//set Val to 1 initially
	cnt=0;//set cnt to 0 initially
	j=0;//initialize j to 0

	while(cnt<e-1 && j<e)
	{
	    if(conn[edge[j].U]==0 && conn[edge[j].V]==0)
		{
		    cout<<endl<<"Path selected : "<<edge[j].s1<<", "<<edge[j].s2<<", "<<edge[j].wt<<endl;
			t[cnt]=edge[j];//assign edge of j to t of cnt
			conn[edge[j].U]=Val;
			conn[edge[j].V]=Val;
			Val++;//incrementing Val
			cnt++;//incrementing cnt
		}

	    else if(conn[edge[j].U]!=conn[edge[j].V])
		{
		    cout<<"Path selected : "<<edge[j].s1<<", "<<edge[j].s2<<", "<<edge[j].wt<<endl;

			if(conn[edge[j].U]!=0 && conn[edge[j].V]!=0)
			{
			    t[cnt]=edge[j];//assign edge of j to t of cnt

			    if(conn[edge[j].U]<conn[edge[j].V])
			    {
			        r=conn[edge[j].U];
				    p=conn[edge[j].V];
			    }

			    else
			    {
			        r=conn[edge[j].V];
				    p=conn[edge[j].U];
			    }

			    for(k=0;k<e;k++)//loop will run to end of e
			    {
			    	if(conn[k]==p)
				    conn[k]=r;//assign r to conn of r
			    }

			     cnt++;//incrementing cnt
		    }

			else if(conn[edge[j].U]==0 && conn[edge[j].V]!=0)
			{
			    t[cnt]=edge[j];//assign edge of j to t of count
			    conn[edge[j].U]=conn[edge[j].V];
			    cnt++;//incrementing cnt
			}

			else
			{
			    t[cnt]=edge[j];//assign edge of j to t of count
			    conn[edge[j].V]=conn[edge[j].U];
			    cnt++;//incrementing cnt
			}
		}

		else
		{
		    cout<<"Path Rejected : "<< edge[j].s1<<", "<<edge[j].s2<<", "<<edge[j].wt<<endl;
		}

		j++;//incrementing j
	}

	cout<<endl<<"Kruskal's MST contains following Distances :"<<endl;
	int cost=0;//initialize cost to 0

	for(i=0;i<cnt;i++)
	{
        cout<<t[i].s1<<", "<<t[i].s2<<", "<<t[i].wt<<endl;
	    cost=cost+t[i].wt;//adding wt to cost
	}
    cout<<endl<<"Total Distance of MST is : "<<cost;
}

//method to find minimum weight using Prim's algorithm
void Graph::prim()
{
	//initialization
	int current, totalvisited, mincost,i;
	current=0; d[current]=0;

	totalvisited =1;//initialize totalvisited to 1
	visited[current]=1;//initialize 1 to visited of current


	cout<<endl<<endl<<"The visited distance and path status is : "<<endl;

	for (i=0;i<v;i++)//run loop to end of v
	{
	    cout<<endl<<"For spot : "<<edge[i].s;//display name of spot
	  	cout<<";  Visited : "<<visited[i];//display all visited vertices
	  	cout<<";  Path : "<<p[i];//display path of all vertices
	  	cout<<";  Distance : "<<d[i];//display distance
	}

	while(totalvisited!=v)//loop will terminate if totalvisited  equal to v
	{
	    cout<<endl<<"Total visited : "<<totalvisited;

        for (i=0;i<v;i++)//loop will run till last v
		{
		    if(weight[current][i]!=0)
			if(visited[i]==0)
			if(d[i]>weight[current][i])
			{
			    d[i] = weight[current][i];//assign weight of current of i to d of i
				p[i] = current;//assign current to p of i
			}
		}
	    cout<<endl<<endl<<"The visited distance and path status is : "<<endl;

	  	for (i=0;i<v;i++)//loop will run till last v
	  	{
	  	    cout<<endl<<"For spot : "<<edge[i].s;//display name of spot
	  	    cout<<";  Visited : "<<visited[i];//display all visited vertices
	  	    cout<<";  Path : "<<p[i];//display path of all vertices
	  	    cout<<";  Distance : "<<d[i];//display distance
	  	}

        mincost= 32767;//initializing mincost with any max value
	    cout<<endl<<endl<<"Finding minimum distance : ";

	    for (i=0;i<v;i++)//loop will run till last v
	    {
		    if(visited[i] ==0)//if visited is equal to 0 then inner statement will run
		    if (d[i] <mincost)//if d of i less than mincost
		    {
			    mincost = d[i];//assign d of i to mincost
			    current = i;//assign i to current
		    }
	    }

	    cout<< endl<<"For Edge number : "<<i;//edge no
	    cout<<";   Minimum distance : "<<mincost;//min dist
	    cout<<";   Current edge : "<<current;//current edge

	    visited[current] = 1;//set 1 to visited of current
	    totalvisited++;//incrementing totalvisited

	    cout<<endl<<"Current edge : "<<current<<endl<<"Total Visited : "<<totalvisited;

	}

	cout<<endl<<endl<<"Minimum spanning tree is : "<<endl;
	mincost =0;//set mincost to 0

	for (i=1;i<v;i++)//run loop from 1 to v
	{
	    mincost += d[i];//adding all elements of d array to mincost
	    cout<<" Edge : "<<edge[i].s1<<"-->"<<edge[i].s2<<";   Distance : "<<d[i]<<endl;;
	}

	cout<<endl<<"Minimum distance : ";
	cout<<mincost;//printing mincost

	cout<<endl<<endl<<"After MST visited distance and path status is :";

	for (i=0;i<v;i++)//run loop from 1 to v
	{
	    cout<<endl<<"For spot : "<<edge[i].s;//printing name of edge
	  	cout<<";  Visited : "<<visited[i];//display all visited vertices
	  	cout<<";  Path : "<<p[i];//display path of all vertices
	  	cout<<";  Distance : "<<d[i];//display distance
	}
	cout<<endl<<endl;
}

