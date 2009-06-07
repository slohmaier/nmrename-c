#include "path.h"
#include <sys/stat.h>

string non::Path::dirname(string path) {
    size_t slash;

    slash = path.find_last_of("/\\");

    if(slash)
        return path.substr(slash + 1);
    else
        return "";
}

string non::Path::basename(string path) {
    size_t slash;

    slash = path.find_last_of("/\\");

    if(slash)
        return path.substr(0, slash);
    else
        return path;
}

bool non::Path::isFile(string path) {
    struct stat info;

    if(stat(path.c_str(), &info) == 0)
        return S_ISREG(info.st_mode);
    else
        return false;
}

bool non::Path::isDir(string path) {
    struct stat info;

    if(stat(path.c_str(), &info) == 0)
        return S_ISDIR(info.st_mode);
    else
        return false;
}
