//
//  main.cpp
//  C++ and Debugging
//
//  Created by Adam Stark on 14/03/2026.
//

#include <iostream>
#include "Classes/Triangle.h"
#include "Classes/Rectangle.h"

void printShape (Shape& s)
{
    std::cout << s.getName() << " has area of " << s.getArea() << std::endl;
}

int main(int argc, const char * argv[])
{
    Rectangle r (20, 50);
    Triangle t (4, 5, 6);
    
    printShape (r);
    printShape (t);
    
    return EXIT_SUCCESS;
}
