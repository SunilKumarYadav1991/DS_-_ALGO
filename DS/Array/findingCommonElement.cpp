/* An interviewer just asked us a question, and this is the question right here. 
Given to erase create a function that lets a user know, true or false, whether these two arrays contain any common items, for example, if we had to erase here one containing A, B, C, X, and the other one, Z, Y and I, it would return false because there's nothing common between these two arrays, however, in this example. Array one, an array to both contain X. And because they have a common item, it should return, true. So an interviewer just asked you this question. How would we go about solving it?
*/
// array A= ['a', 'b', 'c', 'x']
// array B=[ 'z','y', 'x']
// result => true

// array A= ['a', 'b', 'c', 'x']
// array B=[ 'z','y', 'm']
// result => false
//-----------------------------------------------------------------------------------------------------------------
// Naive solution
// consider vector for containier 
// complexity O(n*m)
#include <iostream> 
#include <vector>

using namespace std;

bool HasCommonElement(vector<int> vec1, vector<int> vec2)
{
		for(auto v1:vec1)
			for(auto v2:vec2)
				if(v1==v2)
					return true;
		return false;
}
int main()
{
    vector<int> v1{1,3,5,7,9};
    vector<int> v2{11,13,15, 19};
    
    cout<<HasCommonElement(v1,v2);

    return 0;
}
//-----------------------------------------------------------------------------------------------------------------
// improved using map. We can also use unordered map for speed
#include <iostream> 
#include <vector>
#include<map>
// complexity: O(n+m)
using namespace std;

bool HasCommonElement(vector<int> vec1, vector<int> vec2)
{
    map<int,bool> mib;            // alternative unordered_map via #include<unordered_map>
    for(int v1:vec1)
        mib.insert({v1,true});         //        mib[v1]=true;
    
    for(int v2:vec2)
        if(mib[v2]==true)
            return true;
    
    return false;
}
int main()
{
    vector<int> v1{1,3,5,7,9};
    vector<int> v2{11,13,15, 5};
    
    cout<<HasCommonElement(v1,v2);

    return 0;
}