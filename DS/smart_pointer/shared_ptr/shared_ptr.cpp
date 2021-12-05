#include<iostream>
using namespace std;

template<typename T>
class shared_ptr
{
public:
    shared_ptr():_ptr{nullptr},ref_count{nullptr}{}
    shared_ptr(T* p):_ptr{p},ref_count{new int(0)}
    {
        *ref_count=1;
        //cout<<"inside constructor\n";
    }
    ~shared_ptr()
    {
        *ref_count-=1;
        if(*ref_count==0)    // last owner will delete the object
        {
            *ref_count=0;
            delete ref_count;
            if(_ptr)
                delete _ptr;
            _ptr=nullptr;
            ref_count=nullptr;
            //cout<<"inside destructor of last object\n";
        }
        //cout<<"inside destructor\n";
    }
    
    int get_ref_count() {return *ref_count;}
    
    shared_ptr(shared_ptr& rhs):_ptr{rhs._ptr},ref_count{rhs.ref_count}
    {
        *ref_count+=1;
        //cout<<"inside copy constructor\n";
    }
    
    shared_ptr& operator=(shared_ptr& rhs)
    {
        _ptr=rhs._ptr;
        ref_count=rhs.ref_count;
        
        //cout<<"inside copy assignment\n";
        *ref_count+=1;
        
        return *this;
    }
    
    // in move semantic no need to increase ref count
    shared_ptr(shared_ptr&& rhs)
    {
        _ptr=rhs._ptr;
        ref_count=rhs.ref_count;
        rhs._ptr=nullptr;
        rhs.ref_count=nullptr;
        //cout<<"Inside move constructor\n";
    }
    
    shared_ptr& operator=(shared_ptr&& rhs)
    {
        if( this==&rhs)
            return *this;
        _ptr=rhs._ptr;
        ref_count=rhs.ref_count;
        rhs._ptr=nullptr;
        rhs.ref_count=nullptr;

        return *this;
    }
    
    T& operator*(){ return *_ptr;}
    T* operator->(){ return _ptr;}
private:
    T *_ptr;
    int *ref_count; 
};
//---------------------------------------------------------------------------------
class dummy
{
public:
	dummy()
	{
		std::cout<<"*********inside dummy constructor\n";
	}
	~dummy()
	{
		std::cout<<"inside dummy distructor*********\n";
	}
};
//---------------------------------------------------------------------------------
int main()
{
    
    shared_ptr<int> uptr{new int(100)};
    cout<<*uptr<<endl;
    cout<<"ref count: "<<uptr.get_ref_count()<<endl;
    cout<<"----------------------------\n";
    {
        shared_ptr<int> uptr2{uptr};
        cout<<*uptr2<<endl;
        *uptr2=200;
         cout<<*uptr2<<endl;
         cout<<"uptr ref count: "<<uptr.get_ref_count()<<endl;
         cout<<"uptr2 ref count: "<<uptr2.get_ref_count()<<endl;
    }
    cout<<"----------------------------\n";
    cout<<*uptr<<endl;
    cout<<"ref count: "<<uptr.get_ref_count()<<endl;
    
    //---------------------------------------------------------------------------------
    shared_ptr<dummy> dptr{new dummy()};
    {
        shared_ptr<dummy> dptr2{dptr};
    }
    return 0;   

}
