/******************************************************************************
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
A subarray is a contiguous part of an array.
Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Example 2:
Input: nums = [1]
Output: 1

Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23

Using Kadane’s Algorithm:
--------------------------------
Initialize:
    max_so_far = INT_MIN
    max_ending_here = 0

Loop for each element of the array
  (a) max_ending_here = max_ending_here + a[i]
  (b) if(max_so_far < max_ending_here)
            max_so_far = max_ending_here
  (c) if(max_ending_here < 0)
            max_ending_here = 0
return max_so_far
*******************************************************************************/

#include <iostream>
#include <vector>


using namespace std;
// complexity: O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        
        int max_so_far{0};				// may use INT_MIN from <climits> if sequence is negative only
        int max_ending_here{0};

        for(int i=0;i<nums.size(); ++i)
        {
            max_ending_here=max_ending_here+nums[i];
            if(max_so_far<max_ending_here)
                max_so_far=max_ending_here;
            if(max_ending_here<0)
                max_ending_here=0;
        }
       return max_so_far;
    }
};

int main()
{
    vector<int> v{-2,1,-3,4,-1,2,1,-5,4,};
   Solution s;
   cout<<s.maxSubArray(v);
    return 0;
}