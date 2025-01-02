#include <iostream>
#include "logger.hpp"
#include <thread>

using namespace std;

void user1Log()
{
    Logger *logger1 = Logger::getLogger();
    logger1->log("This is created by User 1");
}

void user2Log()
{
    Logger *logger2 = Logger::getLogger();
    logger2->log("This is created by User 2");
}

int main()
{
    // This code is created by without thread;
    // Logger* logger1 = Logger::getLogger();
    // logger1->log("This is created by User 1");
    // Logger* logger2 = Logger::getLogger();
    // logger2->log("This is created by User 2");
    thread t1(user1Log);
    thread t2(user2Log);

    t1.join();
    t2.join();

    return 0;
}