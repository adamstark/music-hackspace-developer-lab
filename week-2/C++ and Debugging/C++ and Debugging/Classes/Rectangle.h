//
//  Rectangle.h
//  C++ and Debugging
//
//  Created by Adam Stark on 14/03/2026.
//

#pragma once

#include "Shape.h"

// Derived class Rectangle inheriting from Shape
class Rectangle :   public Shape
{
public:
    
    Rectangle (float w, float h);
    
    std::string getName() override;
    float getPerimeter() override;
    float getArea() override;
    
private:
    
    float width;
    float height;
};
