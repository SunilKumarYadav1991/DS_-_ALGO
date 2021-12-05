/***********************************************************
* String exercise 
* Author: Sunil Kumar Yadav
* Date: 6 Nov 2021
* Description: Given input strings with below patter create compression
*	function which gives below output.
* input: aabccccdd
* output: a2b1c3d2
************************************************************/
#include<iostream>
#include<string>

using namespace std;

string compress_(string& str)
{
	int sl=str.length();
	string op_str="";
	
	// check for empty string
	if(sl==0)
		return "";
	
	// check if string contain only one character
	if(sl==1)
	{
		op_str=str+to_string(1);
		return op_str;
	}

	int i{1};          // idx start from 1 to compare with i-1 i.e previous char
	int count{1};      // contains the no. of matching char count
	
	while(i<sl)            
	{
		if(str[i-1]==str[i])
		{
			count++;
		}
		else
		{
			op_str=op_str+str[i-1]+to_string(count);
			count=1;
		}
		i++;
	}
	// for last charcter
	op_str=op_str+str[i-1]+to_string(count);
	
	return op_str;
}



int main()
{	
	string input="aabccccd";
	cout<<"input string: "<<input<<endl;

	string output=compress_(input);
	
	cout<<"output string: "<< output<<endl;
	return 0;
}
