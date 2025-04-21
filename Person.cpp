#include <iostream>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;

class Person
{
  char* name = nullptr;
  
  public:
    Person() : name(nullptr)  {
       
   }
    
   explicit Person(const char* name_) 
    {
        name = new char[strlen(name_) + 1];
        strcpy(name, name_);
    }
    
    Person(const Person& rhs)
    {
        name = new char[strlen(rhs.name) + 1];
        strcpy(name, rhs.name);
    }
    
    Person& operator=(const Person& other)
    {
        if(this != &other)
        {
          name = new char[strlen(other.name) + 1];
          strcpy(name, other.name);
        }
        
        return *this;
    }
    
    Person(Person&& other) noexcept : name(other.name) 
    {
      other.name = nullptr;
    }
    
    Person& operator=(Person&& other)  noexcept
    {
      if(this != &other)
      {
         name = other.name;
         strcpy(name, other.name);
         other.name = nullptr;
      }
        
      return *this;
    }
    
    Person operator+(const Person& rhs)
    {
       return append(rhs);
    }
    
    Person operator+(const char* rhs)
    {
       return append(rhs);
    }
    
    Person append(const Person& rhs)
    {
        char* result = new char[strlen(rhs.name) + strlen(name) + 1];
        sprintf(result, "%s%s", name, rhs.name);
        return Person(result);
    }
    
    Person append(const std::string& rhs)
    {
        char* result = new char[strlen(name) + rhs.length() +1];
        sprintf(result, "%s%s", name, rhs.c_str());
        return Person(result);
    }
    
    void set(const char* name)
    {
        this->name = name;
    }
    
    char* get() const
    {
      return name;
    }
    
    std::string toString()
    {
       return std::string(name);
    }
    
    std::string toString_ostream()
    {
       std::ostringstream s;
       s << name;
       return s.str();
    }
    
     ~Person()
    {
        delete [] name;
        name = nullptr;
    }
    
};

int main()
{ 
    Person p = Person("hello") + "world";
    
    std::cout << p.toString();
    return 0;
}
