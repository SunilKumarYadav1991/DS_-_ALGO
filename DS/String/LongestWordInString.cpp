/********************************************************************************************************************
Longest Word
Have the function LongestWord(sen) take the sen parameter being passed and return the longest word in the string. If there are two or more words that are the same length, return the first word from the string with that length. Ignore punctuation and assume sen will not be empty. Words may also contain numbers, for example "Hello world123 567"
Examples
Input: "fun&!! time"
Output: time
Input: "I love dogs"
Output: love
*******************************************************************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include<vector>
#include<algorithm>
using namespace std;

string LongestWord(string sen) 
{
  stringstream  ss{sen};
  vector<string> svec;
  for(string s; ss>>s;)
  {
    svec.push_back(s);    // store all words in sen to svec
  }

  auto maxIt= max_element(svec.begin(), svec.end(), [](string s1,string s2){return s1.size()<s2.size();});

  return *maxIt;

}

int main(void) { 
   
  // keep this function call here
  cout << LongestWord("Hellooooo world123 567");
  return 0;
    
}