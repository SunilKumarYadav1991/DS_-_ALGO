/***********************************************************
* Graph
* Author: Sunil Kumar Yadav
* Date: 117Nov 2021
* Description: Implementing graph
*
*   			(2)-----------------(0)
*			/ \
*		       /   \
*		      /     \
*		    (1)-----(3)
* Above graph is cyclic undirected unweighted connected graph with. 
* Graph can be implemented in below three ways
* Edge list:[ [0,2], [2,3], [2,1], [1,3] ]
* Adjacent list= [ [2], [2,3], [0,1,3], [1,2] ]
* Adjacent Matrix= {
		0: [0,0,1,0],
		1: [0,0,1,1],
		2: [0,1,0,1],
		3: [0,1,1,0]	
		}

Note: Incomplete
************************************************************/
#include<iostream>
#include<map>
#include<vector>

using namespace std;

// using hash for storing node no. and list of connection aka edges.(connection could be  via list)
using node=map<int,vector<int>>;

// Graph using adjacent list
class Graph
{
public:

	Graph():node_numbers{0},node_numbers{}{}
	void add_vertex(node n){}
	void add_edge(node n1, node n2){}
	int number_of_nodes(){node_numbers}
private:
	int node_numbers;  
	vector<node> vertex;	
};

void Graph::add_vertex(

int main()
{
	return 0;
}
