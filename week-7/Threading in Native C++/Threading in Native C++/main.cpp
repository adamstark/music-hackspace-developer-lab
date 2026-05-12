//
//  main.cpp
//  Threading in Native C++
//
//  Created by Adam Stark on 12/05/2026.
//

#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>

// LOCKS ENSURE THE ORDER OF ACTIONS TO SYNCHRONISE THREADS
// 1. Never lock the audio thread
// 2. Never lock the audio thread
// 3. Never lock the audio thread

// pretend this is complex data
int counter = 0;
std::mutex m;

void task1()
{
    for (int i = 0; i < 10000; i++)
    {
        std::lock_guard<std::mutex> lock (m);   // Scoped Lock
        counter++;
    }
}

void task2()
{
    for (int i = 0; i < 10000; i++)
    {
        std::lock_guard<std::mutex> lock (m);
        counter--;
    }
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
