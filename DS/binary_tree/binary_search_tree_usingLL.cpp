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
      5   6          10   15
* Note2: Binary_search_tree::remove() needs to be implemented
************************************************************/

#include<iostream>

using std::cout;
using std::endl;

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
	~Binary_search_tree();//{/*implement*/}
private:
	node* root;
	int sz;
};

void Binary_search_tree::insert(int value)
{
	sz++;                     //increment the size
	node* new_node= new node(value);
	if(!root)
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
	/*node* current_node=root;
	node* left_node=nullptr;
	node* right_node=nullptr;
	
	while(current_node)
	{
		if(current_node->left)
			left_node=current_node->left;
		if((current_node->right)
			right_node=current_node->right;
		
	}*/
	
	//cout<<"Inside BST destructor\n";
	if(root) delete root;
}

//--------------------------------------------------------------------------
/*
		9
	7		  12
      5   6          10     15
                         
*/

//--------------------------------------------------------------------------
	
int main()
{
	Binary_search_tree bst;
	cout<<"Inserting few values in BST\n";
	bst.insert(9);
	bst.insert(7);
	bst.insert(12);
	bst.insert(5);
	bst.insert(6);
	bst.insert(10);
	bst.insert(15);
	
	int value=10;
	bool result=bst.lookup(value);
	cout<<std::boolalpha<<value<<" search result:"<<result<<endl;
	
	cout<<bst.size()<<endl;
	
	//bst.remove(9);
	cout<<bst.size()<<endl;
	
	cout<<std::boolalpha<<" search result:"<<bst.lookup(10)<<endl;
	
	return 0;
}
