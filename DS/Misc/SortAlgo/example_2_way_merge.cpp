/**********************************************************************************
* Author: Sunil Kumar Yadav
* Date: 15 Sep 2021
* Description: Program to learn how 2 way merge sort algorithm works
*
*
* Note: Incomplete
***********************************************************************************/
#include<iostream>

using namespace std;

int* merge(int A[], int B[], const int m, const int n)
{
	const int size=m+n;
	int* C = new int[size];
	
	int i=0,j=0, k=0;              // indexes for 3 arrays
	         
	while(i<m && j<n)              // index of array start from 0 - n-1 or m-1
	{

		if(A[i]<=B[j])
		{
			C[k]=A[i];
			i++;
			k++;
		}
		else
		{
			C[k]=B[j];
			j++;
			k++;
		}
		
	}
	// copying left over element if size of two arrays are not same
	if(i<m )
	{
		for(;i<m;++i,++k)
			C[k]=A[i];
			
	}
	else if (j<n)
	{
		for(;j<n;++j,++k)
			C[k]=B[j];

	}
	return C;
}

int main()
{

	int A[5]={1,3,5,7,9};
	int B[8]={0,2,4,6,8,10,55,39};
	
	int* C;
	C=merge(A,B,5,8);
	
	for(int i=0; i<13; i++)
	cout<<C[i]<<endl;

	return 0;
}
