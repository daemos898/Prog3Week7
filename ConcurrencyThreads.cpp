//Add necessary utilities
#include <iostream>
#include <thread>
#include <atomic>

//Makes thread 1 marked as not completed to start with
std::atomic<bool> threadOneCompleted(false);

//Method for the first thread to count upwards
void countUp()
{
    for (int i = 1; i <= 20; ++i)
    {
        std::cout << "Thread 1: " << i << std::endl;
    }
    //Marks thread 1 as complete
    threadOneCompleted = true;
}

//Method for the second thread to count downwards
void countDown()
{
    while (!threadOneCompleted)
    {
    //Waits for thread 1 to complete so that thread 2 can start
    }

    for (int i = 20; i >= 0; --i)
    {
        std::cout << "Thread 2: " << i << std::endl;
    }
}

//Creates both threads for counting up and down
int main()
{
    std::thread t1(countUp);
    std::thread t2(countDown);

    t1.join();
    t2.join();

    return 0;
}
