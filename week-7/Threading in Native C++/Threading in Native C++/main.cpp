//
//  main.cpp
//  Threading in Native C++
//
//  Created by Adam Stark on 12/05/2026.
//

#include <iostream>
#include <thread>

// WHAT WE WANT TO HAPPEN
// thread 1: reads counter (0)
// thread 1: adds 1 (0 -> 1)
// thread 1: write result of calculation to counter (1)

// thread 2: reads counter (1)
// thread 2: subtracts 1 (1 -> 0)
// thread 2: write result of calculation to counter (0)

// WHAT ACTUALLY HAPPENS
// thread 1: reads counter (0)
// thread 2: reads counter (0)

// thread 1: adds 1 (0 -> 1)
// thread 2: subtracts 1 (0 -> -1)

// thread 1: writes to counter (1)
// thread 2: writes to counter (-1)

int counter = 0;

void task1()
{
    for (int i = 0; i < 10000; i++)
        counter++;
}

void task2()
{
    for (int i = 0; i < 10000; i++)
        counter--;
}

int main(int argc, const char * argv[])
{
    std::thread t1 (task1);
    std::thread t2 (task2);
    
    // at this point task1 and task2 are already doing there work in parallel
    
    // we are waiting for the threads to finish before exiting
    t1.join();
    t2.join();
    
    std::cout << "COUNTER IS: " << counter << std::endl;
    
    return 0;
}
