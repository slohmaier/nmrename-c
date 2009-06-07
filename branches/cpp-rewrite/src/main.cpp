#include <iostream>
#include "non/options.h"
using namespace std;

#define OPT_HELP 0
#define OPT_STRDEL 1

int main(int argc, char **argv) {
    non::Options opts;
    list<non::Options::arg>::iterator it;
    list<string> paths;

    opts.add("-h", 0, OPT_HELP);
    opts.add("-sd", 1, OPT_STRDEL);

    opts.parse(argc, argv);

    for(it = opts.begin(); it != opts.end(); it++) {
        if(it->isArg()) {
            switch(it->getId()) {
                case OPT_HELP:
                    cout << "print_help" << endl;
                    break;

                case OPT_STRDEL:
                    cout << "delete " << *(it->getArgs().begin()) << endl;
                    break;
            }
        }
        else {
            cout << "adding "<< it->getStr() << endl;
            paths.insert(paths.end(), it->getStr());
        }
    }

    return 0;
}
