//
//  Student.h
//  C++ and Debugging
//
//  Created by Adam Stark on 14/03/2026.
//

#include <iostream>
#include <string>

// Object-oriented Programming

class Student
{
public:
    
    // Constructor
    Student (std::string n, int idNumber)
    {
        name = n;
        studentID = idNumber;
        postgraduate = false;
    }
    
    // Destructor
    ~Student()
    {
        returnBook();
    }
    
    void borrowBook (std::string bookName)
    {
        book = bookName;
    }
        
    std::string getName()
    {
        return name;
    }
    
    int getStudentID()
    {
        return studentID;
    }
    
    bool isPostgraduate()
    {
        return postgraduate;
    }
    
    std::string getBook()
    {
        return book;
    }
    
private:
    
    void returnBook()
    {
        book = "";
    }
    
    std::string name;
    int studentID;
    bool postgraduate;
    std::string book;
    
};
