/***********************************************************
* LinkedList 
* Author: Sunil Kumar Yadav
* Date: 15 Oct 2021
* Description: Implimenting Linked List of int data using procedural 
*		programming style
*
*
************************************************************/
#include<iostream>

using namespace std;

struct node
{
	int data;
	node* next;
	node(int d):data{d}, next{nullptr}{}
	node(): data{0}, next{nullptr} {}
};

//----------------------------------------------------------------------------
void insert_front(node** head, int data)
{
	node* link=new node(data);
	
	node* temp=*head;
	link->next=temp;
	*head=link;
	
}

void insert_back(node** head, int data)
{
	node* link=new node(data);
	
	if(*head==nullptr)    // for first link in list
	{
		*head=link;
		return;
	}
		
	node* temp=*head;
	while(temp!=nullptr)
	{
		if(temp->next==nullptr)
			break;
		temp=temp->next;
	}
	temp->next=link;
	
}

void insert_at(node** head, int pos, int data)   //need to add check for valid pos
{
	if(*head==nullptr)   
	{
		cout<<"List is empty!\n";
		return;
	}
	
	node* link=new node(data);
	
	node* temp=*head;
	node* temp2;
	int idx{0};
	while(temp!=nullptr)
	{
		if(idx==pos-1)			// pos-1 to add before existing pos node
		{
		
			temp2=temp->next;    // point to pos+1
			temp->next=link;     // point to new link
			link->next=temp2;    // set link to point earlier pos+1 
			return;
			
		}
		temp=temp->next;
		idx++;	
	}
}

void print_list(node** head)
{
	node* temp=*head;

	//int i=0;
	while(temp!=nullptr)
	{
		cout<<temp->data<<", ";
		temp=temp->next;
		//if(i++==10)
		//	return;
	}
}

int get_size(node** head)
{
	node* temp=*head;
	int sz{0};
	while(temp!=nullptr)
	{	
		sz++;
		temp=temp->next;
	}
	return sz;
}

//----------------------------------------------------------------------------
int main()
{
	node* head=nullptr;
	
	//node* n1=new node(10);
	//node*n2= new node(20);
	
	//head=n1;
	//n1->next=n2;
	
	insert_front(&head, 10);
	insert_front(&head, 20);
	insert_front(&head, 30);
	insert_back(&head, 100);
	
	cout<<"size of list is "<<get_size(&head)<<endl;
	insert_front(&head, 40);
	insert_back(&head, 200);
	
	
	cout<<"size of list is "<<get_size(&head)<<endl;

	cout<<"inserting node at 4th position\n";
	insert_at(&head, 4, 88);
	
	cout<<"Printing linked list:\n";
	print_list(&head);
	cout<<endl;
	
	cout<<"inserting node at 3rd position\n";
	insert_at(&head, 3, 99);
	
	cout<<"Printing linked list:\n";
	print_list(&head);
	cout<<endl;
	return 0;
}
