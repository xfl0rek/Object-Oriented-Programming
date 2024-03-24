#ifndef PARAMETEREXCEPTION_H
#define PARAMETEREXCEPTION_H

#include "string"
#include <stdexcept>

class ParameterException : public std::logic_error
{
public:
    explicit ParameterException(const std::string &argument) : std::logic_error(argument) {}
};

#endif
