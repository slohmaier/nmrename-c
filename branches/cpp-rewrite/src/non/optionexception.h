#ifndef OPTIONEXCEPTION_H
#define OPTIONEXCEPTION_H

#include "exception.h"

namespace non {

class OptionException : public Exception
{
public:
    OptionException(string message) : Exception(message) {}
};

}

#endif // OPTIONEXCEPTION_H
