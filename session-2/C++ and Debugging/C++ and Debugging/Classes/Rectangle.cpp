//
//  Rectangle.cpp
//  C++ and Debugging
//
//  Created by Adam Stark on 14/03/2026.
//

#include "Rectangle.h"
#include <string>
#include <iostream>

Rectangle::Rectangle (float w, float h)
{
    width = w;
    height = h;
}

Rectangle::~Rectangle()
{
    std::cout << "Rectangle was destroyed!" << std::endl;
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
