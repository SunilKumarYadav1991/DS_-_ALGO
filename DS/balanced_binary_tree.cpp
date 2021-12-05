/**********************************************************************************
* Author: Sunil Kumar Yadav
* Date: 22 Sep 2021
* Description: Understanding how to acces balanced binary tree.
*
*
* Note: Note for n levels 2^n - 1 node are possible
***********************************************************************************/
#include<vector>
#include<iostream>

using namespace std;

int get_parent_idx(int n)
{	
	return (n-1)/2;
}

int main()
{
	vector<int> bt{1,2,3,4,5,6,7};
	
	int bt_size=bt.size();
	cout<<"num of nodes in complete BT are: "<<bt_size<<endl;
	
	// Printing parent of all the nodes
	for(int i=0; i<bt_size; ++i)
	{
		if(i==0) 
			cout<<"Root node "<<i<<" holds "<<bt[i]<<endl;
		else
		{
			int parent=(i-1)/2;
			cout<<"Parent of node "<<i<<" is "<<parent<<endl;
		}
		
	}
	
	// printing child node of an index
	for(int i=0; i<bt_size; ++i)
	{
		int child1=(i*2)+1;
		int child2=(i+1)*2;
		
		if(child1<bt_size && child2<bt_size)       // printing child for nodes having chil only
		{
			
			cout<<"Child node for "<< i<<" index:(" <<child1 <<", "<<child2 <<")\n";
		}
		else break;
	}
	
	return 0;
}

