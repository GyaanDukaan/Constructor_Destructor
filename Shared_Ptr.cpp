#include <iostream>

template <class T>
class Shared_Ptr
{
    T* ptr;
    int* count;
    
    public:
    Shared_Ptr() : ptr(nullptr), count(new int(0))
    {
        
    }
    
    Shared_Ptr(T *p)
    {
        ptr = new T(*p);
        count = new int(1);
    }
    
    Shared_Ptr(const Shared_Ptr& other)
    {
        ptr = other.ptr;
        ++(*other.count);
        count = other.count;
    }
    
    Shared_Ptr& operator=(const Shared_Ptr& other)
    {
        if(this != &other)
        {
         delete ptr;    
         ptr = other.ptr;
         ++(*other.count);
         *count = *(other.count);
        }
        
        return *this;
    }
    
     Shared_Ptr(Shared_Ptr&& other) noexcept
    {
        ptr = other.ptr;
        *count = *(other.count);
        other.ptr = nullptr;
        other.count = nullptr;
    }
    
    Shared_Ptr& operator=(Shared_Ptr&& other) noexcept
    {
       if(this != &other)
       {
         delete ptr;    
         ptr = other.ptr;
         *count = *(other.count);
         other.ptr = nullptr;
         other.count = nullptr;
       }
        
       return *this;
    }

    T* operator->()
    {
      return ptr;
    }
    
    T& operator*() const
    {
      return *ptr;
    }
    
    int getCount() const
    {
      return *count;
    }
    
    T* get() const
    {
      return ptr;
    }
    
    ~Shared_Ptr() 
    {
        --(*count);
        if(*count == 0)
        {
          delete ptr;
          ptr = nullptr;
          std::cout << "\n destructor called.";
        }
        
    }
    
};


int main()
{
    Shared_Ptr<int> p(new int(20));
    
    std::cout << *p << "," << p.getCount() << std::endl;
    
    Shared_Ptr<int> p1(p);
    
    Shared_Ptr<int> p2(p1);
    
    std::cout << *p1 << "," << p1.getCount();
    
    return 0;
}
