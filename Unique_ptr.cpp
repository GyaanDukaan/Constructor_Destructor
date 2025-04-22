#include <iostream>
#include <utility>

using namespace std;

template <typename T> 
class Unique_ptr
{
    T* ptr;
    
    public :
    
    Unique_ptr() : ptr(nullptr) {}
    
    Unique_ptr(T* y) : ptr(new T(*y))
    {
        
    }
    
    Unique_ptr(const Unique_ptr& rhs) = delete;
    
    Unique_ptr& operator=(const Unique_ptr& rhs) = delete;
    
    Unique_ptr(Unique_ptr&& rhs) noexcept
    {
        ptr = rhs.ptr;
        rhs.ptr = nullptr;
    }
    
    Unique_ptr& operator=(Unique_ptr&& rhs) noexcept
    {
        if(this != &rhs)
        {
        delete ptr;
        ptr = rhs.ptr;
        rhs.ptr = nullptr;
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
    
    bool operator==(const T* rhs) const
    {
        return ptr == rhs;
    }
    
    ~Unique_ptr() 
    {
        if(ptr != nullptr)
        delete ptr;
        ptr = nullptr;
    }
    
    T* release()
    {
        T* p = ptr;
        ptr = nullptr;
        return p;
    }
    
    void reset(T* rhs = nullptr)
    {
      
       if(ptr != rhs){
       delete ptr;
       ptr = rhs;
       }
      // rhs = nullptr;
    }
    
    T* get() const
    { 
       return (ptr !=nullptr) ? ptr : nullptr;
    }
    
};


int main()
{
    
   Unique_ptr<int> p(new int(10));
   
  // Unique_ptr<int> p1 = std::move(p);
   
  // if(p == nullptr) std::cout << "\n reference pointer ";
   
   Unique_ptr<int> p2(new int(28));
   std::cout << *p2 << std::endl;
   p2.reset(std::move(new int(20)));
   
   std::cout << *p2;
   
   return 0;
}
