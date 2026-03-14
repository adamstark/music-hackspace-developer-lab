//
//  main.cpp
//  C++ and Debugging
//
//  Created by Adam Stark on 14/03/2026.
//

#include <iostream>

void pointers()
{
    int a = 3;
    int b = 7;
    
    int* ptr = &b;
    
    // Print out memory address of a
    std::cout << &a << std::endl;
    
    // Print out pointer
    std::cout << ptr << std::endl;
    
    // "De-reference" pointer and print out value of the location that the pointer points to
    std::cout << *ptr << std::endl;
    
    // Print b before writing to dereferenced pointer
    std::cout << b << std::endl;
    
    *ptr = 11;
    
    // Print b after writing to dereferenced pointer
    std::cout << b << std::endl;
    
    // set a point to null
    ptr = nullptr;
}

void references()
{
    int a = 3;
    
    int& c = a; // 'ref' is an 'alias' for 'a'
    
    std::cout << a << std::endl;
    
    c = 2;
    
    std::cout << a << std::endl;
}


class Counter
{
public:
    
    void increaseValue()
    {
        count += 1;
    }
    
    int getCount()
    {
        return count;
    }
    
private:
    
    int count {0};
};

void processCounter (Counter& c)
{
    c.increaseValue();
    c.increaseValue();
    c.increaseValue();
}

int main(int argc, const char * argv[])
{
    Counter c;
    
    processCounter (c);
    
    std::cout << "COUNT IS: " << c.getCount() << std::endl;
    
    return EXIT_SUCCESS;
}
