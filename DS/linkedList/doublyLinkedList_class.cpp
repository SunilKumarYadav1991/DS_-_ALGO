/***********************************************************
* LinkedList 
* Author: Sunil Kumar Yadav
* Date: 15 Oct 2021
* Description: Implementing (doubly) linked list class
*
* Note: Incomplete
************************************************************/
#include<iostream>

using namespace std;

//-----------------------------------------------------------------------------------------------
struct node
{
	int data;
	node* next;
	node* prev;
	node(int d):data{d},next{nullptr},prev{nullptr}{}
};
//-----------------------------------------------------------------------------------------------
class LinkedList
{
public:
	LinkedList():head{nullptr}, tail{nullptr}, sz{0}{}
	LinkedList(int d):head{nullptr}, tail{nullptr}, sz{0}
	{
		node* link=new node(d); // create new node/link
		head=link;     	 // head and points to added link	
		tail=link;		 // as its the only link in list
		sz++;
	}
	
	int size(){ return sz;}
	void append(int d);
	void prepend(int d);
	void insert_at(int idx, int d);	// idx wrt start index 1
	void delete_node(int i);
	void print();
	void print_reverse();                  // not working correctly
	int get_last(){return tail->data;}     // not required; 
	~LinkedList(){/*Need to implement*/}
private:
	node* head;
	node* tail;                // not used
	int sz;
};

void LinkedList::append(int d)
{
	node* link=new node(d);
	sz++;                		// update the list size
	if(head==nullptr)              // if list is empty
	{
		head=link;
		tail=link;
		return;
	}
	
	node* node_ptr=head;
	while(node_ptr!=nullptr)
	{
		if(node_ptr->next==nullptr)
			break;             // break before last link
		node_ptr=node_ptr->next;
	}
	node_ptr->next=link;		  // reset the next pointer to new link
	link->prev=node_ptr;
	tail=link;
}

void LinkedList::prepend(int d)
{
	node* link=new node(d);
	sz++;
	
	if(head==nullptr)              // if list is empty
	{
		head=link;
		tail=link;
		return;
	}
	node* node_ptr=head;
	link->next=node_ptr;
	head=link;
}

void LinkedList::insert_at(int idx, int d)          // prev link not set correctly
{
	if(idx==0)
	{
		prepend(d);
		return;
	} else if(idx==sz)
	{
		append(d);
		return;
	} else if(idx>sz)
	{
		cerr<<"Invalid index specified!\nAborting operation\n";
		return;
	}
	
	// if idx is between [start:end) of list
	int count{0};            // counter used in list traversal; 
				  // Start with 1 to avaoid idx-1 in if condition
	node* link=new node(d);
	node* current_node=head;
	node* temp2;     // holds next node pointer 
	node* temp3;     // holds prev node pointer

	while(current_node!=nullptr)
	{
		if(count==idx-1)			// pos-1 to add before existing pos node
		{
		
			temp2=current_node->next;    // point to pos+1
			temp3=temp2->prev;
			//cout<<"Current: "<<current_node->data<<"\t Tem2: "<<temp2->data<<"\t temp3: "<<temp3->data<<"\n";
			current_node->next=link;     // point to new link
			link->next=temp2;    // set link to point earlier pos+1 
			link->prev=temp3;
			
			
			break;			// exit loop
			
		}
		current_node=current_node->next;
		count++;	
	}
	sz++;   // increase list size by 1
}


void LinkedList::print()
{
	node* node_ptr=head;
	while(node_ptr!=nullptr)
	{
		
		cout<<node_ptr->data<<'\n';
		
		node_ptr=node_ptr->next;
	}
}

void LinkedList::print_reverse()   // insert at has some issue
{
	node* node_ptr=tail;
	while(node_ptr!=nullptr)
	{
		cout<<node_ptr->data<<'\n';
		node_ptr=node_ptr->prev;
	}
}



void LinkedList::delete_node(int idx)            // need to fix issue wrt delete at start 
{
	if(idx>sz || idx<=0)
	{
		cerr<<"Invalid index specified!\nAborting operation\n";
		return;
	}
	
	int count{1};            // counter used in list traversal
	node* temp=head;
	node* temp2;
	node* temp3;     // holds prev node pointer
	while(temp!=nullptr)
	{
		if(count==idx)		
		{
		
			temp2=temp->next;    // point to pos+1			
			temp->prev=temp2->prev;
			temp->next=temp2->next;     // point to new link
			delete temp2;
			break;
		}
		temp=temp->next;
		count++;	
	}
	sz--;   // decrease list size by 1
	
}
	

//-----------------------------------------------------------------------------------------------

int main()
{

	/*cout<<"double linked list example:\n";
	LinkedList lst;
	lst.append(66);
	cout<<"size of list: "<<lst.size()<<endl;
	lst.append(88);
	lst.print();
	cout<<"size of list: "<<lst.size()<<endl;
	*/
	cout<<"---------------------------\n";
	LinkedList lst2(1);
	lst2.append(2);
	cout<<"size of list: "<<lst2.size()<<endl;
	lst2.append(3);
	lst2.prepend(0);
	cout<<"size of list: "<<lst2.size()<<endl;
	lst2.print();
	
	cout<<"inserting at position 3\n";
	lst2.insert_at(3, 88);
	lst2.insert_at(4, 99);
	cout<<"size of list: "<<lst2.size()<<endl;
	lst2.print();
	/*
	lst2.delete_node(1);
	cout<<"List after deleting node 1\n";
	cout<<"size of list: "<<lst2.size()<<endl;
	lst2.print();
	lst2.delete_node(0);
	
	cout<<"last node is: "<<lst2.get_last()<<endl;
	*/
	cout<<"Printing list 2 in reverse\n";
	lst2.print_reverse();
	
	return 0;
}

