// Finding if pair exist in a sequence or container whos sum is equal to specified value.
// example:
// A= [1,2,4,9]    sum=8    => no pair with sum 8
// A= [1,2,4,4]    sum=8    => pair with sum
// Scenario 1: no. are in increasing order. would return ture or false if its present

// Approch 1. Loop through each element at a time and add it with other elements to find if sum exist or not
//        e.g. [1+1, 2+1, 4+1, 9+1], [1+2, 2+2, 4+2, 9+2]      Time complexity O(^2)
// Approch 2: As array is sorted, in such case we can loop through arry each index at a time and try to find if sum - A[i] exist in sequence 
// may be use binary search . complexity O(nlogn)
// or we can start from start and end and do addition(start, end)==sum then found. If addition() > sum then '--end' else '++start'

// If no. are not in increasing order and can be random then?
// Approch 3: in this case we can start with hash/unordered set/map(no map as value is not intrested) 
// which contain complement i.e. sum-num such that we can lookup if complement of A[i] is present or not

#include<iostream>
#include<vector>
#include<unordered_set>


using namespace std;

bool HasPairWithSum(vector<int>& ivec, int sum)
{
    unordered_set<int> compLookUp;
    int comp{0};
        //std::set<int>::iterator it;
    for(auto val:ivec)
    {
        comp=sum-val;
        auto it=compLookUp.find(val);
              
        if(it!=compLookUp.end())
            return true;
        else
            compLookUp.insert(comp);
    }
    return false;
}

int main()
{
    vector<int> vi{1,3,4,5,8,12};
    cout<<boolalpha<<HasPairWithSum(vi,15)<<endl;
    
    return 0;
}
