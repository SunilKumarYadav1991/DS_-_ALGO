/******************************************************************************
Implementing own hash function.
Note: This version does not resolve collision problem.
      Improve idx collision, we can either use linked list 
	  in place of normal pointer elem or 2 d array
*******************************************************************************/
#include<iostream>

using namespace std;

// hash table for key(string) and  value(int)
class Hash
{
public:
    Hash(int n):elem{new int[n]}, sz{n} 
	{
		for(int i=0; i<n;++i)
			elem[i]=-999999999;      // initialize with invalid values 
	}
    Hash():elem{nullptr}, sz{0}{}
    
    int get_size(){return sz;}
    
    void insert(string key, int value)   // insert elemnt in hash table
    {
        int idx=get_hash(key);
		elem[idx]=value;
        
    }
    int get(string key)     // extract elemnt in hash table
    {
        int idx=get_hash(key);
        return elem[idx];
    }
    
    int& operator[](string key)
    {
        int idx=get_hash(key);
        return elem[idx];
    }

private:
    int *elem;
    int sz;
    int get_hash(string key)            // Hash function:generates idx for given key
    {									// for int key simply use key % sz 
        int hash{0};
        for(int i=0; i<key.size(); ++i)
            hash=(hash+key[i]) % sz;
        return hash;
    }
};

int main()
{
    Hash h(50);
    h["apple"]=1000;
    h["orange"]=2000;
    h["apple"]=22200;
    h.insert("banana", 55);
    
    cout<<h["apple"]<<'\t'<<h["banana"];
    cout<<endl;
    
    return 0;
}