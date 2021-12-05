#include <iostream> 
#include <string>


using namespace std;
//complexity: O(n/2) => O(n)
bool IsPalindrom(string str)
{
    int len=str.size();
    
    for(int i=0; i<len/2;++i)
        if(str[i]!=str[len-1-i] )
            return false;
            
    return true;
        
    
}
//complexity: 
bool IsPalindrom2(string str)
{
    string rev_str(str.rbegin(),str.rend());    // reverse iterator approch
    
    return str==rev_str;
}

int main()
{
      cout<<IsPalindrom("sunillinus");

    return 0;
}