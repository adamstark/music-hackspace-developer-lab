//
//  Triangle.cpp
//  C++ and Debugging
//
//  Created by Adam Stark on 14/03/2026.
//

#include "Triangle.h"

Triangle::Triangle (float a, float b, float c)
{
    sideA = a;
    sideB = b;
    sideC = c;
}

std::string Triangle::getName()
{
    return "Triangle";
}

float Triangle::getArea()
{
    float semiperimeter = getPerimeter() / 2.f;
    float result = semiperimeter * (semiperimeter - sideA) * (semiperimeter - sideB) * (semiperimeter - sideC);
    return sqrt (result);
}

float Triangle::getPerimeter()
{
    return sideA + sideB + sideC;
}
