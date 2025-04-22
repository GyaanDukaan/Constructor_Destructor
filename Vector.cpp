/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <array>
#include <initializer_list>

using namespace std;

template <typename T> 
class Vector 
{
  T* arr;
  int size;
  int capacity;
  
  public:
  
  Vector()  : arr(nullptr), size(0), capacity(1)
  {
      
  }
  
 
  
  Vector(const Vector<T>& rhs)  : arr(new T[rhs.capacity]), size(rhs.size), capacity(rhs.capacity)
  {
      for(int i = 0; i < rhs.size; ++i)
      {
          arr[i] = rhs.arr[i];
      }
  }
  
  Vector& operator=(const Vector<T>& rhs)  
  {
     if(this != & rhs)
     {
      delete [] arr;
      arr = new T[rhs.capacity];
      size= rhs.size;
      capacity = rhs.capacity;
      
      for(int i = 0; i < rhs.size; ++i)
      {
          arr[i] = rhs.arr[i];
      }
      
     }
      
     return *this;    
  }
  
  void push_back(T element)
  {
      T* temp = nullptr;
      if(size+1 >= capacity)
      {
          capacity = 2 * capacity;
          temp = new T[capacity];
          int i;
          for( i = 0; i < size; ++i)
          {
           temp[i] = arr[i];
          }
          temp[i] = element;
          arr = temp;
          ++size;
          temp = nullptr;
      }
      else
      {
       arr[++size] = element;
       
      }
  }
  
  void reserve(int N)
  {
      if(N <= 0) return;
      arr = new T[N];
      capacity = N;
      size = 0;
      
  }
  
  void resize(int N)
  {
      if(N <= 0 || N == size) return;
      

      T* temp = nullptr;
      
      if(N > capacity)
      {
        temp = new T[N];
        capacity = N;
        
        int i ;
        for(i = 0; i < size; ++i)
        {
           temp[i] = arr[i];
        }
        
        size = N;
        
        for(; i < N; ++i)
        {
           temp[i] = 0;
        }
        
        arr = temp;
        temp = nullptr;
        
      }
      
      else
      {
          if(N < capacity && N > size)
          {
             for(int i = size; i < N; ++i) 
             {
                 arr[i] = 0;
             }
             size = N;
          }
          
          else
          {
              for(int i = N; i < size; ++i) 
             {
                 arr[i] = 0;
             }
             size = N;
          }
      }
    
      
  }
  
  bool empty() const 
  {
      return size == 0;
  }
  
  T* data() const
  {
      return arr;
  }
  
  void pop_back()
  {
      if(!empty())
      {
        arr[size-1] = 0;
        --size;
      }
  }

   void clear()
   {
       for(int i = 0 ; i < size; ++i)
       {
           arr[i] = 0;
       }
       size = 0;
   }
   
   void erase(T pos)
   {
       int i = size -1;
       int k = pos - pos.begin();
       while(i > 0 && i > k)
       {
           arr[i-1] = arr[i];
           --i;
       }
       --size;
   }
   
   T& operator[](const int& idx)
   {
      return arr[idx];
        
   }
   
   int getsize() const
   {
       return size;
   }
   
   void shrink_to_fit()
   {
       
   }
};

int main()
{
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    
    for(int i = 0 ; i < v.getsize(); ++i)
    {
        std::cout << v[i];
    }
    //std::cout << v[1];
    
       
    return 0;
}

