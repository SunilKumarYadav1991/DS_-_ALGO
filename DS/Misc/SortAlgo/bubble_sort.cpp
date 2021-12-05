/**********************************************************************************
* Author: Sunil Kumar Yadav
* Date: 26 Sep 2021
* Description: Understanding how bubble sort works.
*
* Note: Time complexity: O(n^2)
***********************************************************************************/
#include<iostream>
#include<vector>
using namespace std;

void swap(int* a, int*b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void bubble_sort(int* arr, int sz)
{
	for(int i=0; i<sz;++i)
		for(int j=i; j<sz-1;++j)
		{
			if(arr[i]>arr[j])
				swap(arr[i],arr[j]);
		}

}

int main()
{
	int array[]={55,6,7,2,3,4,};
	int sz=sizeof(array)/sizeof(array[0]);
	
	cout<<"Values in array before sorting\n";
	for(int i=0; i<sz;++i)
		cout<<array[i]<<'\t';
	cout<<endl;
	
	
	bubble_sort(array,sz);
	
	cout<<"Values in array after sorting\n";
	for(int i=0; i<sz;++i)
		cout<<array[i]<<'\t';
	cout<<endl;
	
	return 0;
}
