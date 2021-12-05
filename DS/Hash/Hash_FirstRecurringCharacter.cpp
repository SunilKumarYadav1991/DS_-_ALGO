/* First recurring character */

//Google Question
//Given an array = [2,5,1,2,3,5,1,2,4]:
//It should return 2

//Given an array = [2,1,1,2,3,5,1,2,4]:
//It should return 1

//Given an array = [2,3,4,5]:
//It should return undefined
//
// Naive method: Loop over O(n^2) 
//------------------------------------------------------------------------------
#include<map>
#include<iostream>
#include<vector>

using namespace std;

// if founds returns value of first recurrirng character
// else return -1 (may be we should use better return incase of not found)
int findFirstRecurringCharacter(vector<int>& vi)      // O(n)
{
    map<int,int> lookup;
    
    int key{0};
    for(int i=0; i<vi.size(); ++i)
    {
        key=vi[i];
        lookup[key]++;   // increment
        if(lookup[key] >1)
            return key;
    }
    
    return -1;
}

// if founds returns iterator to first recurrence(second duplicate)
// else iterator one pass end to container
vector<int>::iterator findFirstRecurringCharacterIterator(vector<int>& vi)   // O(n)
{
    map<int,int> lookup;
    
    int key{0};
    
    for(auto it=vi.begin(); it!=vi.end();++it)
    {
        key=*it;
        lookup[key]++;                       // increment and check if already exist. 
											// other alternative would be to have map of {key i.e. vi[i]:true/false}
       if(lookup[key] >1)   	 // second occurance 
			return it;
    }   
    return vi.end();    // not found hence return one pass end to sequence

}

int main()
{
    vector<int> val1{2,3,4,5};
    vector<int> val2{2,1,11,23,3,5,12,21,4};
    
    cout<<findFirstRecurringCharacter(val2)<<endl;
    auto iter=findFirstRecurringCharacterIterator(val2);
    if(iter!=val2.end())
        cout<<"First occurance in sequence is "<<*iter<<endl;
    else
        cout<<"Sequence contains unique no.\n";
    
    return 0;
}