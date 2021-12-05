/***********************************************************
* Stack 
* Author: Sunil Kumar Yadav
* Date: 5 Nov 2021
* Description: Implementing Queue using Linked List
*
* Note: Queue is FIFO
* reusing stack implementation
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

// implementation Queue data structur
class Queue
{
public:
    Queue():head{nullptr}, tail{nullptr}, sz{0}
    {}
    void enqueue(int i);
    int dequeue();
    int peek();    // allows looking into top element
    bool isEmpty();
    int size(){return sz;}
    ~Queue();
    void print();
private:
	node* head;
	node* tail;              // not using
	int sz;

};

// FIFO for new node
void Queue::enqueue(int d)
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

bool Queue::isEmpty()
{
	if(head!=nullptr)
		return false;
	else 
		return true;
}

// push back new element in queue
int Queue::dequeue()
{
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
	
	node* node_ptr=head->next;             // make backup of pointer to 2nd node
	data=head->data;
	delete head;
	head=node_ptr;                        // reset head to 2nd node
	
	sz--;
	
	return data;
	
}

void Queue::print()
{
	node* node_ptr=head;
	while(node_ptr!=nullptr)
	{
		cout<<node_ptr->data<<'\n';
		node_ptr=node_ptr->next;
	}
}

// if stack is not empty then allow look up to last elem value
int Queue::peek()
{
	if(!isEmpty())
		return head->data;
	else
	{
		cout<<"Stack is empty!\n";
		return -1;// indicate error
	}
}

Queue::~Queue()
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
	Queue s;
	cout<<"Is queue empty: "<<std::boolalpha<<s.isEmpty()<<endl;
	s.enqueue(10);
	s.enqueue(20);
	cout<<"Is queue empty: "<<std::boolalpha<<s.isEmpty()<<"\nSize of stack is "<<s.size()<<endl;
	
	s.enqueue(30);
	cout<<"Printing queue\n";
	s.print();
	cout<<"--------------------------------\n";
	cout<<"dequeue: "<<s.dequeue()<<endl;
	cout<<"Printing queue\n";
	s.print();
	
	cout<<"Is queue empty: "<<std::boolalpha<<s.isEmpty()<<"\nSize of stack is "<<s.size()<<endl;
	cout<<"peak "<<s.peek()<<endl;
	
	cout<<"--------------------------------\n";
	cout<<"dequeue: "<<s.dequeue()<<endl;
	cout<<"Printing queue\n";
	s.print();
	
	cout<<"--------------------------------\n";
	cout<<"dequeue: "<<s.dequeue()<<endl;
	cout<<"Printing queue\n";
	s.print();
	
	cout<<"queue is empty now\n";
	cout<<"Is queue empty: "<<std::boolalpha<<s.isEmpty()<<"\nSize of stack is "<<s.size()<<endl;
	cout<<"peak "<<s.peek()<<endl;
	
	s.enqueue(111);

	
};













