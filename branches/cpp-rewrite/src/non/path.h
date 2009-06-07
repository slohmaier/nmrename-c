#ifndef PATH_H
#define PATH_H

#include <string>

using std::string;

namespace non {

class Path
{
private:
    Path();
public:
    static string dirname(string path);
    static string basename(string path);
    static string join(...);
    static bool isFile(string path);
    static bool isDir(string path);
};

}

#endif // PATH_H
