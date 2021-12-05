/***********************************************************
* Chapter 24. Numeric
* Author: Sunil Kumar Yadav
* Date: 4 Oct 2021
* Description: 4. Write a program that takes ints from cin and outputs the sqrt() of each int,
*   or “no square root” if sqrt(x) is illegal for some x (i.e., check your sqrt() return values).
*
*
************************************************************/
#include<cmath>
#include<iostream>

using namespace std;

int main()
{

	cout<<"Please enter integer whoes sqrt you require: \n";
	int input; 
	cin>>input;
	
	errno=0;		// used to indicate if math operation was successful or not.
	 
	float result=sqrt(input);
	
	if(errno) 
		cerr<<"Something went wrong\n";
	
	if(errno ==EDOM)
		cerr<<"sqrt() not defined for negative argument\n";
				
	if(errno==0)	
		cout<<"Output of sqrt("<<input<<") is "<<result<<endl;

	return 0;
}

