/**********************************************************************************
* Author: Sunil Kumar Yadav
* Date: 16 Sep 2021
* Description: Program to learn how merge sort algorithm works
*	Idea behind merge sort is to divide list into smaller chunks and then perform
*	merge to get sorted list.
* Note: Time complexity: 	O(n*log n)
***********************************************************************************/
#include<iostream>

using namespace std;

// merging to sub array
// first array[begin.. mid] and second array[mid+1..end]
void merge(int* arr, int begin, int mid,  int end)
{
	int subArrayOne = mid - begin+1;
	int subArrayTwo = end-mid;
	
	int arr1[subArrayOne];          // [begin..mid]
	int arr2[subArrayTwo];		 // [mid+1..end]
	
	// copying part of arr into two sub arrays
	for(int i=0; i<subArrayOne; ++i)
		arr1[i]=arr[begin+i];
		
	for(int j=0; j<subArrayTwo; ++j)
		arr2[j]=arr[mid+1+j];
	
	int idx1=0, idx2=0;    // index for arr1 and arr2
	int idx=begin;	       // index for merged array
	
	
	while(idx1<subArrayOne && idx2<subArrayTwo)
	{
		if(arr1[idx1]<=arr2[idx2])
		{
			arr[idx]=arr1[idx1];
			idx1++;			
		}
		else
		{
			arr[idx]=arr2[idx2];
			idx2++;
		}
		idx++;
	}
	
	
	// copy left over element in case one sub array is longer than other
	while(idx1<subArrayOne)
	{
		arr[idx]=arr1[idx1];
		++idx1;
		++idx;
	}
		
	while(idx2<subArrayTwo)
	{
		arr[idx]=arr2[idx2];
		++idx2;
		++idx;
	}

	
}


// merge sort algorithm
void merge_sort(int* array, int begin,  int end)
{

	if(begin<end)
	{

		int mid= (begin + end) / 2;
		

		merge_sort(array, begin, mid);
		merge_sort(array, mid+1, end);
		merge(array, begin, mid, end);
	}
}

int main()
{
	int size=8;
	int start =0;
	int end= size;
	int* arr =new int[size]{88,24,4,56,8,10,9,3};
	//int B[size]={0,24,4,56,8,10,55,3};
	
	merge_sort(arr,start,end);
	
	cout<<"Sorted array\n";
	for(int i=0; i<8; ++i)
		cout<<arr[i]<<endl;
	cout<<endl;

	return 0;
}
