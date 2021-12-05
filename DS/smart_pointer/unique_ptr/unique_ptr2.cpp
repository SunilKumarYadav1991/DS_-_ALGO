#include<iostream>

template<typename T>

class unique_ptr
{
    T* ptr;
public:
    unique_ptr(T* p = nullptr) : ptr(p){}

    ~unique_ptr()
    {
        delete ptr;
    }
    
    // supress copy constructor 
    unique_ptr(const unique_ptr& rhs) = delete;

    // move constructor
    unique_ptr(unique_ptr&& rhs) : ptr(rhs.ptr)
    {
        rhs.ptr = nullptr;
    }
    
    // supressing copy assignmenint
    unique_ptr& operator=(const unique_ptr& rhs) = delete;
    
    // Move assignmenint operator
    unique_ptr& operator=(unique_ptr&& rhs)
    {        
        if (&rhs == this)    // ensuring no assignment to same pointer
            return *this;
        delete ptr;
		
        ptr = rhs.ptr;
        rhs.ptr = nullptr;
        return *this;
    }
    
    T& operator*() 
    { 
        return *ptr; 
    }
	
	T* operator->()
	{ 
		return ptr; 
	}
    
};

class dummy
{
public:
	dummy()
	{
		std::cout<<"inside dummy constructor\n";
	}
	~dummy()
	{
		std::cout<<"inside dummy distructor\n";
	}
};
int main()
{
    unique_ptr<int> p=new int;
   
   *p=10;
   std::cout<<*p<<std::endl;
    //int* p2=p;
    // unique_ptr p3=p;   // error: call to deleted copy constructor
    unique_ptr<int> p3=std::move(p);
    std::cout<<"Testing Move :"<<*p3<<std::endl;
    
    unique_ptr<dummy> dptr=new dummy;
    
    return 0;
}



