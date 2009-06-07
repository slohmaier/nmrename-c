#include "renamer.h"
#include "iostream"

using namespace std;

list<string> renamer(list<string> paths, int opt, list<string> args) {
    list<string> newpaths;
    list<string>::iterator it;
    size_t pos;
    string buff;

    for(it = paths.begin(); it != paths.end(); it++) {
        switch(opt) {
            case OPT_STRDEL:
                buff = *it;

                while((pos = buff.find(*(args.begin()))) != string::npos)
                    buff = buff.erase(pos, (*(args.begin())).length());

                newpaths.insert(newpaths.end(), buff);
                break;
        }
    }

    return newpaths;
}

