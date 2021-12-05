#include <iostream> 
#include<vector>
#include <string>
#include<sstream>

using namespace std;

vector<string> reverse_words_in_sentence(string str)
{
    stringstream iss(str);
    
    
    vector<string> rev_words;
    
    for(string temp; iss>>temp;)
    {
        string s(temp.rbegin(), temp.rend());
        rev_words.push_back(s);
    }
    return rev_words;
}

// using string stream method
string reverse_words_in_sentence2(string str)
{
    stringstream iss(str);
    stringstream oss;
    

    
    for(string temp; iss>>temp;)
    {
        
        oss<<string(temp.rbegin(), temp.rend())<<" ";
    }
    //cout<<oss.str(); // get string
    return oss.str();    // get string from stringstream
}



int main()
{
      cout<<reverse_words_in_sentence2("sunil kumar yadav");  
   

    return 0;
}

/* converting string to int
 stringstream ss("12");
    int i;
    ss>>i;
    cout<<i;
*/