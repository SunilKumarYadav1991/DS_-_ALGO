/******************************************************************************
moveZeroes
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.
Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
*******************************************************************************/

#include <iostream>
#include <vector>
#include<algorithm>


using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) // O(n^2): Bubble sort style 
    {
        for(int i=0; i<nums.size()-1;++i)
        {
            for(int j=0; j<nums.size()-1;++j)
            if(nums[j]==0)
            {
                swap(nums[j],nums[j+1]);
            }
            
        }
    }
    
   
    
    void moveZeroesToEnd(vector<int>& nums)         // better method O(n)
    // find index of non zero elements in count and then copy nums[i] to num[count]
    // at the end simpy zero out nums idx [count:nums.size())
    {
        int count{0};
        for(int i=0; i<nums.size();++i)
        {
            if(nums[i]!=0)
            {
                nums[count]=nums[i];
                count++;
            }
            //cout<<"index, count:"<<i<<", "<<count<<endl;
        }
        
		// zero out rest of sequence from last non zero idx(count)
        while(count!=nums.size())
        {
            nums[count]=0;
            count++;
        }
        
        
    }
};

int main()
{
    vector<int> vi{0,1,0,3,12};
    vector<int> vi2{0,1,0,3,12};
    
   Solution s;
   s.moveZeroesToEnd(vi);
   //s.shift(vi2,0,5,2);
  
   
   for(auto v:vi)
    cout<<v<<", ";
    cout<<endl;
    
    return 0;
}
