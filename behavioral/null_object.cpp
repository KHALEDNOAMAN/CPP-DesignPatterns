// Null Object Pattern - eliminates null checks
#include <iostream>
#include <memory>
using namespace std;

class Logger {
public:
    virtual void log(const string& msg) = 0;
    virtual ~Logger() = default;
};

class ConsoleLogger : public Logger {
public:
    void log(const string& msg) override { cout << msg << endl; }
};

class NullLogger : public Logger {
public:
    void log(const string&) override { }
};