/******************************************************************************
Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.
Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.
Example 1:
Input: nums = [1,2,2,3,1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
*******************************************************************************/
#include <iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int findArrayDegree(vector<int>& nums) {
        map<int,int> mfreq;     // map of {value: occurance}
        for(int i=0; i<nums.size(); ++i)
            ++mfreq[nums[i]];
        
        int currentMax{0};         // holds maximum value of map

        for(auto m: mfreq)
        {
            if(currentMax<m.second)
                currentMax=m.second;
        }
        return currentMax;
    }
};

int main()
{
    vector<int> v{1, 2, 2, 3,3, 4};
    Solution s;
    cout<<"Degree of array is: "<<s.findArrayDegree(v)<<endl;
   

    return 0;
}