/***************************************************************************************
* Author: Sunil Kumar Yadav
* Date: 24 July 2021
* Description: implementing array class with basic operation
*
* Note: Array::delete_at does not resize existing array. If required then we can reallocate and
* move to memory location.
***************************************************************************************/

#include<iostream>

using namespace std;

class Array
{
private:
	int* elem;
	int sz;
	int offset;
public:
	Array():elem{nullptr},sz{0}, offset{0}{}
	Array(int n): elem{new int[n]}, sz{n}, offset{0}
	{
		for(int i=0;i<n;++i)
			elem[i]=0;
	}
	
	Array(const Array& rhs);                   // copy ctor
	
	Array& operator=(const Array& rhs);        // copy assignment
	
	~Array()
	{
		if(elem) delete[] elem;
	}
	
	int size(){return sz;}
	
	//int& at(int idx);                       // range checked access
	int& operator[](int idx){return elem[idx];}
	
	void delete_at(int idx);
	void shift_elem(int idx);	           // helper function used in shifting elements
}; 

Array::Array(const Array& rhs): elem{new int[rhs.sz]}, sz{rhs.sz}, offset{0}
{
	for(int i=0; i<sz;++i)
		elem[i]=rhs.elem[i];
}

Array& Array::operator=(const Array& rhs)
{
	if(elem) delete[] elem;
	sz=rhs.sz;
	elem=new int[sz];
	offset=rhs.offset;
	for(int i=0; i<sz;++i)
		elem[i]=rhs.elem[i];
	
	return *this;
}

void Array::shift_elem(int idx)
{
	for(int i=idx;i<sz-1;++i)
		elem[i]=elem[i+1];
}

void Array::delete_at(int idx)
// As we can not delete dynamic array, simply reserving mem from deleted idx
{
	if(idx <= sz-1)
	{
		shift_elem(idx);
		sz--;
		offset++;
	}
}

//-------------------------------------------------------------------------------------------------------------------

int main()
{
	Array a(10);
	for(int i=0;i<a.size();++i)
		a[i]=i*i;
	
	cout<<"List of element in array:\n";
	for(int i=0;i<a.size();++i)
		cout<<a[i]<<'\t';
	cout<<'\n';
	
	a.delete_at(5);
	cout<<"Size of array after deleting element at idx 5: "<<a.size()<<endl;
	
	cout<<"List of element in array after delete operation:\n";
	
	for(int i=0;i<a.size();++i)
		cout<<a[i]<<'\t';
	cout<<'\n';
	
	
	a.delete_at(7);
	cout<<"Size of array after deleting element at idx 7: "<<a.size()<<endl;
	
	cout<<"List of element in array after delete operation:\n";
	
	for(int i=0;i<a.size();++i)
		cout<<a[i]<<'\t';
	cout<<endl;
	return 0;
}
