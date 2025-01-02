#ifndef logger_hpp
#define logger_hpp

#include <string>
#include<mutex>

using namespace std;

class Logger
{
    static int cnt;
    static Logger *loggerInstance;
    static mutex mtx;
    Logger();
    Logger(const Logger &obj);
    Logger operator=(const Logger &obj);

public:
    static Logger *getLogger();
    void log(string msg);
};

#endif