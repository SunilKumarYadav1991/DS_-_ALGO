/******************************************************************************
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
Example 1:
Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
*******************************************************************************/

#include <iostream>
#include <vector>
#include<map>
#include<set>

// 1. we can use map and increment if same key appears
// 2. use set and if size of set< size of input array that means there is dubplicate
using namespace std;
class Solution {
public:
    bool containsDuplicate_usingSet(vector<int>& nums)     // O(n)
    {
        set<int> unique;
        for(auto n:nums)
            unique.insert(n);
            
        if(unique.size()!=nums.size())
            return true;    //contains dubplicate
        return false;
        
    }
    
    bool containsDuplicate_usingMap(vector<int>& nums)  // O(n)
    {
        map<int,int> munique;
        for(auto n:nums)
        {
            munique[n]++;
            if(munique[n]>1)
                return true;
        }  
     
        return false;
        
    }
};

int main()
{
    vector<int> vi{1,2,3,1,3,5};
    vector<int> vi2{1,2,3,4};
    
   Solution s;
   cout<<boolalpha<<s.containsDuplicate_usingMap(vi)<<endl;

    
    return 0;
}