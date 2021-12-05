/***************************************************************************************************************************************************
https://leetcode.com/problems/two-sum/description/
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target. You may assume that each input would have exactly one solution, and you may not use the same element twice. You can return the answer in any order. 
Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
**************************************************************************************************************************************************/
#include<vector>
#include<map>		// for speed use <unordered_map>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
		map<int,int> comp_idx;     // stores {complement, idx}
		int comp{0};
        for(int i=0; i<nums.size(); ++i)
        {
            auto Iter=comp_idx.find(nums[i]);     // find if we've seen target - nums[i] early
			                                      // such that nums[i] + comp = target
            if(Iter!=comp_idx.end())
            {
                return {comp_idx[nums[i]],i};
            }
            else 
            {   comp=target - nums[i];
               comp_idx[comp]=i;
            }
         cout<<i<<endl; 
        }
        return {-1,-1}; // not found
    }
};
int main()
{
    vector<int> nums{-1,2,6,17,11,15};
    int target=9;
    Solution S;
    vector<int> res=S.twoSum(nums,target);
    cout<<"done with calculation\n";
    cout<<res[0]<<", "<<res[1]<<endl;
    return 0;
}