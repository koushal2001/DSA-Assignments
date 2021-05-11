
#ifndef D_H_
#define D_H_

#include <iostream>
using namespace std;

struct Edge//structure edge
{
    int U,V,wt,no;//declaring variables
    string s,s1,s2;//declaration of strings
};

class Graph//class graph
{
private:
	int weight[20][20];//declaring a 2D array of size 20*20 named as weight
	int visited[20], d[20],p[20];//declaring array of structures
	int v,e;//declaring variables
	Edge edge[20];

public:
	//constructor
	Graph();

	//method to create graph
	void creategraph();

	//method to validate number of vertices and edges
	void validate(int,string);

	//method to find minimum weight using Dijktra's algorithm
	void dijktras();

};


#endif //D_H_
