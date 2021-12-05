/***********************************************************
* Binary Tree 
* Author: Sunil Kumar Yadav
* Date: 11 Nov 2021 
* Description: Implementing Binary search tree using linked list
*	In BST each node has 2 childs. A balanced BST will have 2
*	child nodes per each parent node (except leaf node)
*
*    Auto-balancing of trees upon insertion can be achieved via 
*    AVL tree or Red-Black tree
* Note1: Avoid insertion of duplicates in BST
		9
	7		12
      5   8          10   15
* Note2: Binary_search_tree::remove() needs to be implemented
* --------------------------------------------------------------
* Date: 25 Nov 2021
* Description: Implementing Breadth First Search (BFS)
* 	In BFS we iterate/travers horizontally i.e. [9, 7, 12, 5, 6, 10, 15]
*
************************************************************/

#include<iostream>
#include <queue>          // std::queue for BFS
#include <vector>

using std::cout;
using std::endl;
using std::queue;
using std::vector;

struct node
{
	int data;
	node* left;
	node* right;
	node():data{0},left{nullptr}, right{nullptr}
	{}
	node(int d):data{d},left{nullptr}, right{nullptr}
	{}
	~node()                               // Destructor to deallocate if left/right node
	{                                     // is allocated on heap
		//cout<<"Deletting node: "<<data<<endl;
		if(left) delete left;
		if(right) delete right;
	}
};

class Binary_search_tree
{
public:
	Binary_search_tree():root{nullptr},sz{0}
	{}
	int size(){return sz;}
	bool lookup(int num); 
	void insert(int num);
	void remove(int num);
	vector<int> breadth_first_search();            //BFS returns array of int containing node values
	
	vector<int> depth_first_search_InOrder();
	vector<int> depth_first_search_PreOrder();
	vector<int> depth_first_search_PostOrder();
	
	vector<int> traverse_InOrder(node* root);      // helper function for DFS InOrder 
	vector<int> traverse_PreOrder(node* root);      // helper function for DFS PreOrder 
	vector<int> traverse_PostOrder(node* root);      // helper function for DFS PostOrder   
	~Binary_search_tree();
private:
	node* root;
	int sz;
};

void Binary_search_tree::insert(int value)
{
	sz++;                     //increment the size
	node* new_node= new node(value);
	if(!root)   // for root insertion
	{
		root=new_node;
		return;
	}
	
	node* current_node=root;
	while(true)
	{
		if(current_node->data > value)               // insert to left if value < current node
		{
			if(!current_node->left)
			{
				current_node->left=new_node;
				return;
			}
			current_node=current_node->left;
		}
		else                                      // insert to right for value>=
		{
			if(!current_node->right)          
			{
				current_node->right=new_node;
				return;
			}
			current_node=current_node->right;
		}
	}
}

bool Binary_search_tree::lookup(int value)
{
	if(!root)
		return false;
	
	node* current_node=root;
	while(current_node)
	{
		if(value < current_node->data)
		{
			current_node=current_node->left;
		}
		else if(value> current_node->data)
		{
			current_node=current_node->right;
		}
		else                  // found the value in BST
		{
			return true;
		}
	
	}
	// if current_node is null_ptr and value is not found
	return false;
}

// Remove method deletes the node (dirctly if its leaf node) but if node has childs then 
// 1. travers to the target node 
// 2. assign left node of target node-> right node(smaller of two) at target node
// 3. delete target node 
void Binary_search_tree::remove(int value)
{
/****************************** incorrect and incomplete ************************************************/
	if(!root) return;     // do nothing for empty tree
	
	
	node* current_node=root;
	while(current_node)
	{
		if(value < current_node->data)
		{
			current_node=current_node->left;
		}
		else if(value> current_node->data)
		{
			current_node=current_node->right;
		}
		else                  // found the target node to be deleted
		{
			sz--;          
			cout<<"Removed node: "<<value<<endl;
			if(current_node->left==nullptr && current_node->right==nullptr)   // leaf node
			{
				delete current_node;
				return;
			}
			else                  			// node with child nodes or leafs
			{
				node* target_node=current_node;
				node* next_high_node=current_node->right;
				node* next_high_node_left=next_high_node->left;
				
				next_high_node->left=nullptr;     
				target_node =next_high_node_left;
				
				delete current_node;
				return;
				
			}
		}
	
	}
	cout<<"Target node "<<value<<" not present\n";

}

// BST destructor will delete root node which will invoke node::~node recursivly to 
// release the heap allocated nodes
Binary_search_tree::~Binary_search_tree()
{

	if(root) delete root;
}

//----------------------------------------------------------------------------------------------------------
// For implementation of BFS we need queue(FIFO) which will store parent nodes while traversing
// left to right. This means space requirment would be large.
vector<int>  Binary_search_tree::breadth_first_search()
{
	queue<node*> node_queue;
	vector<int> value_list;
	node* current_node=root;
	
	node_queue.push(current_node);
		
	while(!node_queue.empty())
	{
		current_node=node_queue.front();   // get current node from queue
		node_queue.pop();                  // remove/pop out front element
		
		value_list.push_back(current_node->data);           // store value/data field of BST node
	
		// if parent node have left or right child,
		// push them in queue
		if(current_node->left)
			node_queue.push(current_node->left);
			
		if(current_node->right)
			node_queue.push(current_node->right);
	}
	return value_list;
}

//----------------------------------------------------------------------------------------------------------
/* Depth First Search have 3 different type:
1. InOrder  : [5, 7, 8, 9, 10, 12, 15]
2. PreOrder : [9, 7, 5, 8, 12, 10, 15]      # Useful in recreating tree
3. PostOrder: [5, 8, 7, 10, 15, 12, 9]      # sequence: start from bottom most left to right child node-> Parent node 

*/
/*--------------------------------------------------------------------------
		9
	7		  12
      5   8          10     15
--------------------------------------------------------------------------*/

//--------------------------------------------------------------------
vector<int> Binary_search_tree::depth_first_search_InOrder()
{
	return traverse_InOrder(root);
}

vector<int> Binary_search_tree::traverse_InOrder(node* root)
{
	static vector<int> node_list;
	
	if(root==nullptr)
		return {};
	
	
	if(root-> left) traverse_InOrder(root->left);
	
	node_list.push_back(root->data);         // push data once in array
	//cout<<"node ->data: "<<root->data<<endl;
	
	if(root-> right) traverse_InOrder(root->right);
	
	return node_list;	
}

//--------------------------------------------------------------------

vector<int> Binary_search_tree::depth_first_search_PreOrder()
{
	return traverse_PreOrder(root);
}

vector<int> Binary_search_tree::traverse_PreOrder(node* root)
{
	static vector<int> node_list;
	
	if(root==nullptr)
		return {};
	
	node_list.push_back(root->data);         // push data once in array
	//cout<<"node ->data: "<<root->data<<endl;
	
	if(root-> left) traverse_PreOrder(root->left);
		
	if(root-> right) traverse_PreOrder(root->right);
	
	return node_list;	
}

//--------------------------------------------------------------------

vector<int> Binary_search_tree::depth_first_search_PostOrder()
{
	return traverse_PostOrder(root);
}

vector<int> Binary_search_tree::traverse_PostOrder(node* root)
{
	static vector<int> node_list;
	
	if(root==nullptr)
		return {};
	
	if(root-> left) traverse_PostOrder(root->left);
		
	if(root-> right) traverse_PostOrder(root->right);
	
	node_list.push_back(root->data);         // push data once in array
	//cout<<"node ->data: "<<root->data<<endl;
	return node_list;	
}

//--------------------------------------------------------------------


/*--------------------------------------------------------------------------
		9
	7		  12
      5   8          10     15
--------------------------------------------------------------------------*/
	
int main()
{
	Binary_search_tree bst;
	cout<<"Inserting few values in BST\n";
	bst.insert(9);
	bst.insert(7);
	bst.insert(12);
	bst.insert(5);
	bst.insert(8);
	bst.insert(10);
	bst.insert(15);
	
	int value=10;
	bool result=bst.lookup(value);
	cout<<std::boolalpha<<value<<" search result:"<<result<<endl;
	
	cout<<bst.size()<<endl;
	
	//bst.remove(9);
	cout<<bst.size()<<endl;
	
	cout<<std::boolalpha<<" search result:"<<bst.lookup(10)<<endl;
	
	cout<<"---------------------------------------\n";
	auto lst_bfs=bst.breadth_first_search();
		
	cout<<"print BFS result\n";
	for(auto i:lst_bfs)
		cout<<i<<' ';
	cout<<endl;
	
	cout<<"---------------------------------------\nprint DFS InOrder result\n";
	auto lst_DFSInOrder=bst.depth_first_search_InOrder();
	
	for(auto i:lst_DFSInOrder)
		cout<<i<<' ';
	cout<<endl;
	
	cout<<"---------------------------------------\nprint DFS PreOrder result\n";
	auto lst_DFSPreOrder=bst.depth_first_search_PreOrder();
	
	for(auto i:lst_DFSPreOrder)
		cout<<i<<' ';
	cout<<endl;
	
	cout<<"---------------------------------------\nprint DFS PostOrder result\n";
	auto lst_DFSPostOrder=bst.depth_first_search_PostOrder();
	
	for(auto i:lst_DFSPostOrder)
		cout<<i<<' ';
	cout<<endl;
	
	return 0;
}
