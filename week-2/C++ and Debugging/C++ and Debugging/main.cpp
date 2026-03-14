//
//  main.cpp
//  C++ and Debugging
//
//  Created by Adam Stark on 14/03/2026.
//

#include <iostream>
#include "Classes/Rectangle.h"

// STACK
// - Predefined area with fixed size (usually about 2mb)
// - Very fast to access
// - Cleaned up as variables go out of scope

// HEAP
// - Can grow in size as program runs
// - Slower to allocate
// - We have to clean up after oursleves

// This is the old-school what of doing things
// where you have to remember actively to delete
// the memory you allocate
void badOutdatedMemoryAllocationOnTheHeap()
{
    // Hey can I have some space for a Rectangle in memory
    Rectangle* r = new Rectangle (10, 20);
    
    // use our rectangle
    std::cout << r->getArea() << std::endl;
    
    delete r; // cleans up the memory on the heap
    r = nullptr;
}

// Unique pointer cleans up after itself
// Unique pointers cannot be copied
void uniquePointerExample()
{
    // define a unique pointer
    std::unique_ptr<Rectangle> r = std::make_unique<Rectangle> (10, 20);
    
    // use our rectangle
    std::cout << r->getArea() << std::endl;
}


// any shared pointer passed into this function will
// be copied, increasing the use count of the shared pointer
// but at the end of the function that copy will be released
void processRectangle (std::shared_ptr<Rectangle> r)
{
    std::cout << r->getArea() << std::endl;
    std::cout << r->getPerimeter() << std::endl;
}

// We can copy shared pointers
// They can be passed into functions (where they are copied)
// They are still tidied up automatically
void sharedPointerExample()
{
    std::shared_ptr<Rectangle> r1 = std::make_shared<Rectangle> (10, 20);
    std::shared_ptr<Rectangle> r2 = r1;
    
    processRectangle (r2);
}

int main (int argc, const char * argv[])
{
    // Uncommend functions below to show example code running
    
    //badOutdatedMemoryAllocationOnTheHeap();
    //uniquePointerExample();
    sharedPointerExample();
    
    return EXIT_SUCCESS;
}
