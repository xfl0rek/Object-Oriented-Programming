#ifndef LOGICEXCEPTION_H
#define LOGICEXCEPTION_H

#include <string>
#include <stdexcept>

class LogicException : public std::logic_error
{
public:
    explicit LogicException(const std::string &argument) : std::logic_error(argument) {}
};

#endif
