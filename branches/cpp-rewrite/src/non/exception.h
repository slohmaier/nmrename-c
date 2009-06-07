#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

using std::string;

namespace non {

class Exception
{
private:
    string message;
public:
    Exception(string message) : message(message) {}
    string getMessage();
};

}

#endif // EXCEPTION_H
