//
//  main.cpp
//  C++ and Debugging
//
//  Created by Adam Stark on 14/03/2026.
//

#include <iostream>
#include "Classes/Student.h"

int main(int argc, const char * argv[])
{
    Student s1 ("John", 1242);
    Student s2 ("Jane", 8642);
    
    s1.borrowBook ("Harry Potter");
    s2.borrowBook ("Wuthering Heights");
    
    std::cout << "Student 1 is " << s1.getName() << " with student ID " << s1.getStudentID() << std::endl;
    std::cout << "Student 2 is " << s2.getName() << " with student ID " << s2.getStudentID() << std::endl;
    
    std::cout << "Student 1 has borrowed: " << s1.getBook() << std::endl;
    std::cout << "Student 2 has borrowed: " << s2.getBook() << std::endl;
    
    return EXIT_SUCCESS;
}
