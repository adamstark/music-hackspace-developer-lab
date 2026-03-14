//
//  Shape.h
//  C++ and Debugging
//
//  Created by Adam Stark on 14/03/2026.
//

#pragma once

#include <string>

// Abstract base class for a shape
class Shape
{
public:
    
    virtual std::string getName() = 0;
    
    virtual float getArea() = 0; // pure virtual function
    
    virtual float getPerimeter() = 0;

};


