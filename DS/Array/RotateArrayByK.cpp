/******************************************************************************
Given an array, rotate the array to the right by k steps, where k is non-negative.
Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;
// shift right by k amount
class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int offset=nums.size() - k;    
        vector<int> buffer{nums.begin()+offset,nums.end()};   // make backup of K right elements
        
        int size=nums.size();
        
        for(int i=size;i>0;--i)                  // shift nums to kth right pos
            nums[i]=nums[i-k];
        
        for(int i=0; i<buffer.size(); ++i)       //assign k right elements to start of sequence
            nums[i]=buffer[i];
    }
    
    void rotate2(vector<int>& nums, int k) 
    {
        // If rotation is greater than size of array
    int n=nums.size();
    k = k % n;
 
    for(int i = 0; i < n; i++)
    {
       if(i < k)
       {
           // Printing rightmost kth elements
           cout << nums[n + i - k] << ", ";
           //nums[n + i - k]=nums[i];
       }
       else
       {
           // Prints array after 'k' elements
           cout << (nums[i - k]) << ", ";
           //nums[i - k]=nums[i];
       }
    }
    cout << "\n";
    }
    
};

int main()
{
    vector<int> vi{1,2,3,4,5,6,7};
    vector<int> vi2{1,2,3,4};
    
    cout<<"origina sequence\n";
    for(auto v:vi)
        cout<<v<<", ";
    cout<<endl;
   Solution s;
   s.rotate2(vi,3);
    for(auto v:vi)
       ;// cout<<v<<", ";
    return 0;
}