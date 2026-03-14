//
//  Triangle.h
//  C++ and Debugging
//
//  Created by Adam Stark on 14/03/2026.
//

#include "Shape.h"

// Derived class Triangle inheriting from Shape
class Triangle :   public Shape
{
public:
    
    Triangle (float a, float b, float c);
    
    std::string getName() override;
    float getArea() override;
    float getPerimeter() override;
    
private:
    
    float sideA;
    float sideB;
    float sideC;
};
