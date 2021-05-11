

#ifndef KP_H_
#define KP_H_

#include <iostream>
using namespace std;

//struct declaration
struct Edge
{
    int no,U,V,wt;
    string s,s1,s2;
};

//class declaration
class Graph
{
private:
	int weight[20][20];//declaration of 2d matrix
	int visited[20], d[20],p[20];//arrays
	int v,e;//variables
	Edge edge[20];
public:
    //constructor
	Graph();

	//method to create graph
	void creategraph();

	//method to sort the vertices of graph
	void sortg();

	//method to validate number of vertices and edges
	void validate(int,string);

	//method to find minimum weight using Kruskal's algorithm
	void kruskals();

	//method to find minimum weight using Prim's algorithm
	void prim();
};


#endif //KP_H_

