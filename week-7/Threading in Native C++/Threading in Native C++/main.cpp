//
//  main.cpp
//  Threading in Native C++
//
//  Created by Adam Stark on 12/05/2026.
//

#include <iostream>
#include <thread>
#include <atomic>
#include <string>

// ATOMIC VARIABLES SOLVE PROBLEM (FOR SIMPLE DATA)
// Atomic instruction is a single action

std::atomic<int> counter = 0;
static_assert (std::atomic<int>::is_always_lock_free);


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
