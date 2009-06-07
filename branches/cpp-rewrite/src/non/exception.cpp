#include "exception.h"
#include <typeinfo>

string non::Exception::getMessage() {
    return string(typeid(*this).name()) + ": " + message;
}
