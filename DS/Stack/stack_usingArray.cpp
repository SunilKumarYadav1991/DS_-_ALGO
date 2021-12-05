/***********************************************************
* Stack 
* Author: Sunil Kumar Yadav
* Date: 5 Nov 2021
* Description: Implementing Stack using array(vector)
*
* Note: stack is LIFO
************************************************************/
#include<vector>
#include<iostream>

using std::cout;
using std::endl;
using std::vector;


// implementation stack data structor
class Stack
{
public:
    Stack():arr(0), sz{0}, isPoped{false}
    {}
    void push(int i);
    int pop();
    int peek();    // allows looking into top element
    bool isEmpty();
    int size(){return sz;}
    ~Stack();
    void print();
private:
	vector<int> arr;
	int sz;           //local sz to track increase/decrease of size
	bool isPoped;

};

void Stack::push(int d)
{

	if(isPoped)	// if poped then adjust index
	{
		int idx=size();
		arr[idx]=d;
	}
	else
	{
		arr.push_back(d);
	}
		
	sz++;
}

bool Stack::isEmpty()
{
	if(sz==0)
		return true;
	else 
		return false;
}

int Stack::pop()
{
	int data=arr[sz-1];
	arr[sz-1]=0;		// since we can't delete, setting last elem to zero
	sz--;
	isPoped=true;
	return data;
	
}


void Stack::print()
{
	for(int i=0; i<sz;++i)
		cout<<i<<" : "<<arr[i]<<'\n';
}

// if stack is not empty then allow look up to last elem value
int Stack::peek()
{
	if(!isEmpty())
		return arr[sz-1];
	else
	{
		cout<<"Stack is empty!\n";
		return -1;    //to indicate empty stack
	}
}

Stack::~Stack()
{
	
	
}


int main()
{
	Stack s;
	cout<<"is stack empty: "<<std::boolalpha<<s.isEmpty()<<endl;
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
	
	for(int i=0; i<10;++i)
	{
		s.push(i);
		s.push(i*2);
		cout<<"Printing stack\n";
		s.print();
		cout<<"----------------------------\n";
		//cout<<"pop: "<<s.pop()<<endl;
	}

	
};













