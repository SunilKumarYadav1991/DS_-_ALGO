/***********************************************************
* Stack 
* Author: Sunil Kumar Yadav
* Date: 5 Nov 2021
* Description: Implementing Stack using Linked List
*
* Note: stack is LIFO
*
************************************************************/
#include<vector>
#include<iostream>

using std::cout;
using std::endl;
using std::vector;

struct node
{
	int data;
	node* next;
	node(int d):data{d},next{nullptr}{}
	~node()
	{
		if(next) delete node;
	}
};

// implementation stack data structor
class Stack
{
public:
    Stack():head{nullptr}, tail{nullptr}, sz{0}
    {}
    void push(int i);
    int pop();
    int peek();    // allows looking into top element
    bool isEmpty();
    int size(){return sz;}
    ~Stack();
    void print();
private:
	node* head;
	node* tail;
	int sz;

};

// Stacks are LIFO data structure and to speed up push and pop
// improve push by adding new node to head rather than at the end
void Stack::push(int d)
{
	node* link=new node(d);
	sz++;                		// update the list size
	if(head==nullptr)              // if list is empty
	{				// append
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
	tail=link;
}

bool Stack::isEmpty()
{
	if(head!=nullptr)
		return false;
	else 
		return true;
}

int Stack::pop()
{
	node* temp=head;
	node* temp2;
	int data{0};
	
	if(sz==1)			// if stack have only one element 
	{				// return data filed -> delte the node -> set head to nullptr
		data=head->data;
		delete head;
		head=nullptr;
		tail=nullptr;
		sz--;
		return data;
	}
	
	int idx=0;
	while(idx<(sz-2) && temp!=nullptr)                 // travese till n-2 th node
	{
		temp=temp->next;
		idx++;
	}
	temp2=temp->next;    			// point to pos+1
	
	data=temp2->data;		
	temp->next=temp2->next;     		// point to second last node
	delete temp2;
	
	sz--;
	tail=temp;				// reset tail to new last node
	return data;
	
}


void Stack::print()
{
	node* node_ptr=head;
	while(node_ptr!=nullptr)
	{
		cout<<node_ptr->data<<'\n';
		node_ptr=node_ptr->next;
	}
}

// if stack is not empty then allow look up to last elem value
int Stack::peek()
{
	if(!isEmpty())
		return tail->data;
	else
	{
		cout<<"Stack is empty!\n";
		return -1;// indicate error
	}
}

Stack::~Stack()
{
	node* temp=head;
	while(head)
	{
		cout<<"deleting "<<temp->data<<endl;
		temp=head->next;
		delete head;
		head=temp;
	}
	sz=0;
	head=nullptr;
	tail=nullptr;
	// Another alternative for cleaning up 
	// memory would be to simply use node::~node() by deleting head i.e.
	// if(head) delete head;
}


int main()
{
	Stack s;
	cout<<std::boolalpha<<s.isEmpty()<<endl;
	s.push(10);
	s.push(20);
	cout<<std::boolalpha<<s.isEmpty()<<"\nSize of stack is "<<s.size()<<endl;
	
	s.push(30);
	cout<<"Printing stack\n";
	s.print();
	cout<<"--------------------------------\n";
	cout<<"pop: "<<s.pop()<<endl;
	cout<<"Printing stack\n";
	s.print();
	
	cout<<std::boolalpha<<s.isEmpty()<<"\nSize of stack is "<<s.size()<<endl;
	cout<<"peak "<<s.peek()<<endl;
	
	cout<<"--------------------------------\n";
	cout<<"pop: "<<s.pop()<<endl;
	cout<<"Printing stack\n";
	s.print();
	
	cout<<"--------------------------------\n";
	cout<<"pop: "<<s.pop()<<endl;
	cout<<"Printing stack\n";
	s.print();
	
	cout<<"Stack is empty now\n";
	cout<<std::boolalpha<<s.isEmpty()<<"\nSize of stack is "<<s.size()<<endl;
	cout<<"peak "<<s.peek()<<endl;
	
	s.push(111);

	
};













