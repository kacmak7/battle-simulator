#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
public:
    Logger();
    ~Logger();
    static void info(std::string &message);
    static void error(std::string &message);
};

#endif