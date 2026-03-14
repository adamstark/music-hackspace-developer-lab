//
//  Rectangle.cpp
//  C++ and Debugging
//
//  Created by Adam Stark on 14/03/2026.
//

#include "Rectangle.h"
#include <string>

Rectangle::Rectangle (float w, float h)
{
    width = w;
    height = h;
}

std::string Rectangle::getName()
{
    return "Rectangle";
}

float Rectangle::getPerimeter()
{
    return 2 * width + 2 * height;
}

float Rectangle::getArea()
{
    return width * height;
}
