/*
Finding maximum len of sub arry which follows  arr[i]-arr[i+1]<1 or arr[i]-arr[i+1]==0
example
Input: [3,1,4,2,6,8,7,15]
output: 4
explanation:[1,2,3,4],[6,7,8],[15]
*/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;



int max_arr_len(vector<int>& vec)
{
    sort(vec.begin(), vec.end());
    
    int diff{0};
    int start{0};
    int end{0};
    
    int max_arr_len{0};
    
    for(int i=0; i<vec.size();++i)
    {
        diff=vec[i+1]-vec[i];
        if(diff>1)
        {
            int max_so_far=end+1 - start;   
            
            if(max_arr_len<max_so_far)
                max_arr_len=max_so_far;

            start=i+1;
            end=i+1;
        }
        else
        {
            end++;
        }
    }
 
    return max_arr_len;
}

int main()
{
   vector<int> v{55,3,1,4,2,6,8,7,15,16,17,18,19,20};

    cout<<"max array is: "<<max_arr_len(v);
    return 0;
}
